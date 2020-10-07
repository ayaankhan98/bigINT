#!/bin/bash
CC=gcc
CFLAGS=-I.

cd ../build/tests/operators/
ctest
cd ../operations/
ctest
