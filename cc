#!/bin/bash

# Compila pipex.c con libft.a
make
#gcc -o pipex pipex.c libft/libft.a -g3

# Verifica si la compilación fue exitosa
if [ $? -eq 0 ]; then
    echo "./pipex infile '$1'"
    echo '------------------------ '
    ./pipex infile "$1"
    rm pipex.o
else
    echo "Error: la compilación falló"
fi
echo "-cat de outfile-"
cat outfile
