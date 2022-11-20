#!/usr/bin/env -S make -f

include ../Makefile.conf

# CFLAGS := $(subst -O3,-Og,$(CFLAGS))
BIN := $(filter-out cg,$(BIN))

include ../Makefile.rule

$(OBJ): defs.h
cg-test: cg.o
