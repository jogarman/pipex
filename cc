#!/bin/bash

# Compila pipex.c con libft.a
gcc -o pipex pipex.c libft/libft.a -g3

# Verifica si la compilación fue exitosa
if [ $? -eq 0 ]; then
    echo "Compilación SIN banderas exitosa!"
    echo "./pipex infile '$1'"
    echo '------------------------ '
    ./pipex infile "$1"
    rm pipex
else
    echo "Error: la compilación falló"
fi

