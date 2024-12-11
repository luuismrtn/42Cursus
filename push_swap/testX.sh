#!/bin/bash

# Número de veces que se realizarán las pruebas
repeticiones=10

# Cantidad de números a generar en cada prueba
n=500

# Rango
rango_negativo=-1000
rango_positivo=1000

movimientos_totales=0

resultados=()
movimientos_list=()

for ((i = 1; i <= repeticiones; i++)); do
  ARG=$(seq $rango_negativo $rango_positivo | shuf -n $n | tr '\n' ' ')

  movimientos=$(./push_swap $ARG | wc -l)
  movimientos_list+=("$movimientos")

  movimientos_totales=$((movimientos_totales + movimientos))

  resultado=$(./push_swap $ARG | ./checker_linux $ARG)

  resultados+=("$resultado")

done

media_movimientos=$((movimientos_totales / repeticiones))

echo "Número de pruebas: $repeticiones"

echo "Resultados de las pruebas: ${movimientos_list[@]}"

echo "Resultados de las pruebas: ${resultados[@]}"

echo "Media de movimientos: $media_movimientos"


