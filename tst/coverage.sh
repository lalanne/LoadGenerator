#!/usr/bin/env bash

lcov --directory itst/ --capture --output-file coverage_itst.info # capture coverage info
lcov --directory utst/ --capture --output-file coverage_utst.info # capture coverage info
lcov --add-tracefile coverage_itst.info --add-tracefile coverage_utst.info --output-file coverage_total.info #combining tracefiles
lcov --remove coverage_total.info '/usr/*' --output-file coverage_total.info # filter out system
path=`pwd`
utst_path=${path}/utst/*
itst_path=${path}/itst/*
lcov --remove coverage_total.info $utst_path --output-file coverage_total.info # filter out system
lcov --remove coverage_total.info $itst_path --output-file coverage_total.info # filter out system
lcov --list coverage_total.info #debug info

