#!/usr/bin/env -S make -f

include ../Makefile.conf

# CFLAGS := $(subst -O3,-Og,$(CFLAGS))
BIN := $(filter-out qr qri hhr qrig,$(BIN))

include ../Makefile.rule

qr-test: qr.o
qri-test: qr.o qri.o
hhr-test: hhr.o qr.o qri.o
qrig-test: qrig.o hhr.o qr.o qri.o
$(OBJ): defs.h
