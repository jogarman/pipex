#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 512

// Ejemplo  funcional de pipes
/*

int	main(int argc, char* argv[], char **env)
{
	pid_t	pid;
	int		p[2];
	int		readbytes;
	char	buffer[SIZE];

	pipe(p);
			// 0: lee
			// 1: escribe
	printf("p[0] lee: %d \np[1] escribe: %d\n", p[0], p[1]);
	pid = fork();
	if (pid == 0)
	{
		close(p[1]);
		readbytes = 1;
		while(readbytes > 0)
		{
			readbytes =read(p[0], buffer, SIZE);
			write(1, buffer, readbytes);
		}
		close(p[0]);
	}
	else
	{
		close(p[0]);
		//first_command(argv, env);
		strcpy(buffer, "Esto llega a traves de la tuberia\n" );
		write(p[1], buffer, strlen(buffer));
		close(p[1]);
	}
	waitpid(pid, NULL, 0);
	exit(0);
} */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define READ_END 0 /* índice del extremo de lectura de la tubería */
#define WRITE_END 1 /* índice del extremo de escritura de la tubería */

int main(int argc, char* argv[]) {
    int fd1[2], fd2[2];
    int status, pid;

    pipe(fd1); /* tubería para comunicar ls y grep */

    pid = fork();

    if (pid == 0) { /* hijo 1 */
        close(fd1[READ_END]); /* cerrar el extremo no necesario */

        dup2(fd1[WRITE_END], STDOUT_FILENO);
        close(fd1[WRITE_END]);

        execlp("/bin/ls", "ls", "-l", NULL);
    } else { /* padre */
        close(fd1[WRITE_END]); /* cerrar el extremo no necesario */

        pipe(fd2); /* tubería para comunicar grep y wc */
        pid = fork();

        if (pid == 0) { /* hijo 2 */
            close(fd2[READ_END]); /* cerrar el extremo no necesario */

            dup2(fd1[READ_END], STDIN_FILENO);
            close(fd1[READ_END]);

            dup2(fd2[WRITE_END], STDOUT_FILENO);
            close(fd2[WRITE_END]);

            execlp("/bin/grep", "grep", "u", NULL);
        } else { /* padre */
            close(fd1[READ_END]); /* cerrar el extremo no necesario */
            close(fd2[WRITE_END]); /* cerrar el extremo no necesario */

            pid = fork();

            if (pid == 0) { /* hijo 3 */
                dup2(fd2[READ_END], STDIN_FILENO);
                close(fd2[READ_END]);

                execlp("/usr/bin/wc", "wc", "-l", NULL);
            }
        }
    }

    close(fd2[READ_END]); /* cerrar el extremo que queda abierto en el padre */

    /* esperar a cada hijo */
    wait(&status);
    wait(&status);
    wait(&status);

    return 0;
}


