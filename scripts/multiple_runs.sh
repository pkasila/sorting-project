#!/bin/bash

mkdir -p data/runs

for ((i=1;i<=10;i++));
do
  echo "RUN $i"
  mkdir -p "data/runs/$i"

  ./scripts/gen_sources.sh
  ./scripts/sort.sh
  cp -r data/source "data/runs/$i/source"
  cp -r data/out "data/runs/$i/out"
  cp -r data/inversed "data/runs/$i/inversed"
done