#!/usr/bin/env -S make -f

include ../Makefile.conf

# CFLAGS := $(subst -O3,-Og,$(CFLAGS))
BIN := $(filter-out logging qr qri hhr qrig,$(BIN))

include ../Makefile.rule

$(OBJ): defs.h
$(BIN): logging.o

qr-test: qr.o
qri-test: qr.o qri.o
hhr-test: hhr.o qr.o qri.o
qrig-test: qrig.o hhr.o qr.o qri.o
eigen: qr.o qri.o qrig.o
