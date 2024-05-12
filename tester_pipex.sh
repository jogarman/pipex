#!/bin/bash

# Verificar si se proporcionan 5 argumentos
if [ "$#" -ne 5 ]; then
    echo "Uso: $0 archivo1 comando1 comando2 comando3 archivo2"
    exit 1
fi

# Almacenar los argumentos en variables
archivo1="$1"
comando1="$2"
comando2="$3"
comando3="$4"
archivo2="$5"

# Ejecutar el equivalente de línea de comandos original y almacenar la salida en otro archivo
 echo "Comando original..."
 echo "<$archivo1 $comando1 | $comando2 | $comando3 > $archivo2"
 eval "<$archivo1 $comando1 | $comando2 | $comando3 > $archivo2"
 cat $archivo2

# Ejecutar tu programa pipex y almacenar la salida en un archivo
echo "Ejecutando tu programa..."
echo ./pipex "$archivo1" "$comando1" "$comando2" "$comando3 "$archivo2"
./pipex "$archivo1" "$comando1" "$comando2" "$comando3 "$archivo2"
# Mostrar los contenidos de los archivos de salida generados
echo "Contenido de outfile_tester:"
cat outfile_tester
