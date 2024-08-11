#!/bin/sh

set -xe

CC="${CXX:-cc}"
CFLAGS="-Wall -Wextra -ggdb -O3 -std=c11 -pedantic"

$CC factory.c $CFLAGS -o factory
