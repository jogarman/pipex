#!/bin/bash

# Verificar si se proporcionan 4 argumentos
if [ "$#" -ne 4 ]; then
    echo "Uso: $0 archivo1 comando1 comando2 archivo2"
    exit 1
fi

# Almacenar los argumentos en variables
archivo1="$1"
comando1="$2"
comando2="$3"
archivo2="$4"

# Ejecutar tu programa pipex y almacenar la salida en un archivo
echo "Ejecutando tu programa..."
./pipex "$archivo1" "$comando1" "$comando2" "$archivo2"

# Ejecutar el equivalente de línea de comandos original y almacenar la salida en otro archivo
echo "Ejecutando el comando original..."
eval "<$archivo1 $comando1 | $comando2 > outfile_tester"
echo "Comparando resultados..."

# Mostrar los contenidos de los archivos de salida generados
echo "Contenido de outfile_ft:"
cat $archivo2
echo "Contenido de outfile_tester:"
cat outfile_tester
