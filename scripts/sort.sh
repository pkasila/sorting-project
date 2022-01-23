#!/bin/bash

mkdir -p data/out

declare -a sortings=("insertion-sort" "merge-sort" "quick-sort" "selection-sort" "swap-sort")
declare -a files_a=("20k_100" "20k_10000" "40k_100" "40k_10000" "100k_100" "100k_10000")

for i in "${sortings[@]}"
do
   echo "* $i"
   for j in "${files_a[@]}"
   do
      echo " - $j"
      "./$i/$i" -in "data/source/$j.txt" -out "data/out/$i-$j.txt"
   done
done
