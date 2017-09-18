#!/usr/bin/env bash

lcov --directory itst/ --capture --output-file coverage_itst.info # capture coverage info
lcov --directory utst/ --capture --output-file coverage_utst.info # capture coverage info
lcov --remove coverage_itst.info '/usr/*' --output-file coverage_itst.info # filter out system
lcov --remove coverage_itst.info 'tst/itst/*' --output-file coverage_itst.info # filter out system
lcov --remove coverage_utst.info '/usr/*' --output-file coverage_utst.info # filter out system
lcov --remove coverage_utst.info 'tst/utst/*' --output-file coverage_utst.info # filter out system
lcov --add-tracefile coverage_itst.info --add-tracefile coverage_utst.info --output-file coverage_total.info #combining tracefiles
lcov --list coverage_total.info #debug info

