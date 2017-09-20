#!/usr/bin/env bash

cd tst/
cmake .
ret=$?
if [ "$ret" != "0" ]; then
    echo "ERROR: cmake unit tests!!!!"
	exit 1
fi

make clean
make
ret=$?
if [ "$ret" != "0" ]; then
    echo "ERROR: compilation!!!!"
	exit 1
fi

cd utst/
./utst
cd -

cd itst/
./itst
cd -

cd ../
cmake .
ret=$?
if [ "$ret" != "0" ]; then
    echo "ERROR: cmake of load generator!!!!"
	exit 1
fi
make clean
make
if [ "$ret" != "0" ]; then
    echo "ERROR: compilation of load generator!!!!"
	exit 1
fi
cd -

cd ftst
pytest -v
ret=$?
if [ "$ret" != "0" ]; then
    echo "ERROR: functional tests fail!!!!"
	exit 1
fi
cd -
