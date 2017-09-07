
[![Build Status](https://travis-ci.org/lalanne/LoadGenerator.svg?branch=develop)](https://travis-ci.org/lalanne/LoadGenerator)
[![codecov](https://codecov.io/gh/lalanne/LoadGenerator/branch/develop/graph/badge.svg)](https://codecov.io/gh/lalanne/LoadGenerator)

# LoadGenerator
Simple load generator

## Compilation
 * in root folder

For release build:

 * cmake -DCMAKE_BUILD_TYPE=Release .

For debug build:

 * cmake -DCMAKE_BUILD_TYPE=Debug .

 * make clean
 * make

## Execution

usage: load_generator \<n\> \<t\> 

n: number of concurrent requests

t: number of \<n\> that will be executed
