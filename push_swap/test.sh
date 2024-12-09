#!/bin/bash

# Generar n números
n=500

ARG=$(seq -1000 1000 | shuf -n $n | tr '\n' ' ')

# Mostrar los números generados
echo "Números generados: $ARG"

# Ejecutar el programa push_swap con los números generados y contar el número de líneas de salida
./push_swap $ARG | echo "¿Es correcto? $(./checker_linux $ARG)"

./push_swap $ARG | echo "Número de movimientos: $(wc -l)"