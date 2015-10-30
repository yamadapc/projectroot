CC     ?= cc
PREFIX ?= /usr/local

SRC  = projectroot.c
DEPS = $(wildcard deps/*/*.c)
OBJS = $(DEPS:.c=.o)

projectroot: $(SRC) Makefile $(OBJS)
	$(CC) -Ideps/commander -std=gnu11 -Wall -O3 $(SRC) $(OBJS) -o projectroot

%.o: %.c
	$(CC) $< -c -o $@

install:
	cp projectroot $(PREFIX)/projectroot

install-local:
	cp projectroot ~/.bin/projectroot
