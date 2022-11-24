#!/usr/bin/env -S make -f

include ../Makefile.conf

RUN += plot
OUT += lorenz.pdf

# CFLAGS := $(subst -O3,-Og,$(CFLAGS))

include ../Makefile.rule

plot: lorenz.c lorenz.out
