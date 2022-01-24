#!/bin/bash

mkdir -p data/out
mkdir -p data/inversed/source
mkdir -p data/inversed/out

declare -a sortings=("selection-sort" "swap-sort" "insertion-sort")
declare -a files_a=("20k_100" "20k_10000" "40k_100" "40k_10000")

for i in "${sortings[@]}"
do
   echo "* $i"
   for j in "${files_a[@]}"
   do
      echo " - $j"
      "./$i/$i" -in "data/source/$j.txt" -out "data/out/$i-$j.txt"
   done
done

# worst case scenario
for j in "${files_a[@]}"
do
  echo " - inversing $j"
  ./inverse/inverse -in "data/out/swap-sort-$j.txt" -out "data/inversed/source/$j.txt"
done

for i in "${sortings[@]}"
do
   echo "* $i"
   for j in "${files_a[@]}"
   do
      echo " - $j (inversed)"
      "./$i/$i" -in "data/inversed/source/$j.txt" -out "data/inversed/out/$i-$j.txt"
   done
done

# task 2

declare -a sortings=("merge-sort" "quick-sort" "std-sort")
declare -a files_a=("1m_100" "1m_10000" "2m_100" "2m_10000")

for i in "${sortings[@]}"
do
   echo "* $i"
   for j in "${files_a[@]}"
   do
      echo " - $j"
      "./$i/$i" -in "data/source/$j.txt" -out "data/out/$i-$j.txt"
   done
done

# worst case scenario
for j in "${files_a[@]}"
do
  echo " - inversing $j"
  ./inverse/inverse -in "data/out/std-sort-$j.txt" -out "data/inversed/source/$j.txt"
done

for i in "${sortings[@]}"
do
   echo "* $i"
   for j in "${files_a[@]}"
   do
      echo " - $j (inversed)"
      "./$i/$i" -in "data/inversed/source/$j.txt" -out "data/inversed/out/$i-$j.txt"
   done
done