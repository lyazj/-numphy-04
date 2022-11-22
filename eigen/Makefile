#!/usr/bin/env -S make -f

include ../Makefile.conf

# CFLAGS := $(subst -O3,-Og,$(CFLAGS))
BIN := $(filter-out logging qr qrh qri qrih hhr qrig jcbi sgi,$(BIN))
RUN += plot
OUT += eigen-0.pdf eigen-1.pdf eigen-2.pdf eigen-3.pdf

include ../Makefile.rule

$(OBJ): defs.h
$(BIN): logging.o

qr-test: qr.o
qrh-test: qrh.o
qri-test: qr.o qri.o
qrih-test: qrh.o qrih.o
hhr-test: hhr.o qr.o qri.o
qrig-test: qrig.o hhr.o qr.o qri.o
jcbi-test: jcbi.o qr.o qri.o
sgi-test: sgi.o
eigen: qr.o qrh.o qri.o qrih.o qrig.o jcbi.o sgi.o
plot.run: eigen.out
