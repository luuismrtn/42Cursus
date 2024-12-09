#!/bin/bash

# Número de veces que se realizarán las pruebas
repeticiones=1

# Cantidad de números a generar en cada prueba
n=500

# Rango
rango_negativo=-1000
rango_positivo=1000

movimientos_totales=0

resultados=()

for ((i = 1; i <= repeticiones; i++)); do
  ARG=$(seq $rango_negativo $rango_positivo | shuf -n $n | tr '\n' ' ')

  movimientos=$(./push_swap $ARG | wc -l)

  movimientos_totales=$((movimientos_totales + movimientos))

  resultado=$(./push_swap $ARG | ./checker_linux $ARG)

  resultados+=("$resultado")

done

media_movimientos=$((movimientos_totales / repeticiones))

echo "Media de movimientos: $media_movimientos"

echo "Resultados de las pruebas: ${resultados[@]}"
