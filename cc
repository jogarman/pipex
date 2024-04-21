#!/bin/bash

# Compila pipex.c con libft.a
cc -o pipex pipex.c libft/libft.a

# Verifica si la compilación fue exitosa
if [ $? -eq 0 ]; then
    echo "Compilación exitosa: pipex creado"
else
    echo "Error: la compilación falló"
fi

