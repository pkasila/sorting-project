#!/bin/sh

mkdir -p data/source

./random/random -n 20000 -min -10000 -max 10000 -out data/source/20k_10000.txt
./random/random -n 20000 -min -100 -max 100 -out data/source/20k_100.txt

./random/random -n 40000 -min -10000 -max 10000 -out data/source/40k_10000.txt
./random/random -n 40000 -min -100 -max 100 -out data/source/40k_100.txt

./random/random -n 100000 -min -10000 -max 10000 -out data/source/100k_10000.txt
./random/random -n 100000 -min -100 -max 100 -out data/source/100k_100.txt
