#!/usr/bin/env bash

set -e

sudo wget https://github.com/google/googletest/archive/release-1.8.0.tar.gz
sudo tar xzvf release-1.8.0.tar.gz
cd googletest-release-1.8.0
sudo cmake -DBUILD_SHARED_LIBS=ON .
sudo make
sudo make install
sudo apt-get install libboost-all-dev
sudo apt-get -y install python-pip
sudo pip install -U pytest
python --version
cd "${TRAVIS_BUILD_DIR}"
