#!/usr/bin/env bash

set -e

cd ${TRAVIS_BUILD_DIR}/tst/
lcov --directory itst/ --capture --output-file coverage_itst.info # capture coverage info
lcov --directory utst/ --capture --output-file coverage_utst.info # capture coverage info
lcov --add-tracefile coverage_itst.info --add-tracefile coverage_utst.info --output-file coverage_total.info #combining tracefiles
lcov --remove coverage_total.info '/usr/*' --output-file coverage_total.info # filter out system
path=`pwd`
utst_path=${path}/utst/*
utst_path1=${path}/utst/RequestsTests.cpp
itst_path=${path}/itst/*
lcov --remove coverage_total.info $utst_path --output-file coverage_total.info # filter out system
lcov --remove coverage_total.info $utst_path1 --output-file coverage_total.info # filter out system
lcov --remove coverage_total.info $itst_path --output-file coverage_total.info # filter out system
lcov --list coverage_total.info #debug info
# Uploading report to CodeCov
bash <(curl -s https://codecov.io/bash) -t c129d72a-3721-47cb-98e9-2b95cc643ea0 || echo "Codecov did not collect coverage reports"
