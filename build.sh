#!/usr/bin/env bash

cd tst/utst/
cmake .
ret=$?
if [ "$ret" != "0" ]; then
    echo "ERROR: cmake unit tests!!!!"
	exit 1
fi

make clean
make
./utst
cd -

cd tst/itst/
cmake .
ret=$?
if [ "$ret" != "0" ]; then
    echo "ERROR: cmake integration tests!!!!"
	exit 1
fi
make clean
make
./itst
cd -
