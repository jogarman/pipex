#include "../pipex.h"

/*
	prints an array of arrays.
	returns number of strings printed
	"%d>%s<
*/
int		ft_print_vector(char **vector)
{
	int		i = 0;

	while (vector[i] != NULL)
	{
		//write(2, vector[i], strlen(vector[i]));
		//printf("%d>%s<\n", i, vector[i]);
		i++;
	}
	printf("%d>Null\n", i);
	return (i);
}
/*
int  main()
{
	char	*arr[] = {"hola", "mundo", NULL};
	ft_print_vector(arr);
}
*/
/*
	ft_print_vector(&argv[2]);		//Imprime arg2
	ft_print_vector(arguments);		//Imprime el split de arg2
*/