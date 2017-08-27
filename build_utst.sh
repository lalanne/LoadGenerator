#!/usr/bin/env bash

cd utst/
cmake .
make clean
make
./utst
cd -
