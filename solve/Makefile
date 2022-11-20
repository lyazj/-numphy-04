#!/usr/bin/env -S make -f

include ../Makefile.conf

# CFLAGS := $(subst -O3,-Og,$(CFLAGS))
BIN := $(filter-out cg gd,$(BIN))

include ../Makefile.rule

$(OBJ): defs.h
cg-test: cg.o
solve-cg: cg.o
gd-test: gd.o
solve-gd: gd.o
