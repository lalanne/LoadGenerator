#!/usr/bin/env bash

cd tst/utst/
cmake .
make clean
make
./utst
cd -

cd tst/itst/
cmake .
make clean
make
./itst
cd -
