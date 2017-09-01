#!/usr/bin/env bash

cd tst/utst/
cmake .
make clean
make
./utst
cd -
