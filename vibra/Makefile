#!/usr/bin/env -S make -f

include ../Makefile.conf

# CFLAGS := $(subst -O3,-Og,$(CFLAGS))
RUN += stat plot

include ../Makefile.rule

stat.run: vibra
plot.run: stat.out
