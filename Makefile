CC     ?= cc
PREFIX ?= /usr/local

SRC  = projectroot.c
DEPS = $(wildcard deps/*/*.c)
OBJS = $(DEPS:.c=.o)

projectroot: $(SRC) Makefile $(OBJS)
	$(CC) -Ideps/commander -std=c99 -Wall -O3 $(SRC) $(OBJS) -o projectroot

%.o: %.c
	$(CC) $< -O3 -std=c99 -c -o $@

install:
	cp projectroot $(PREFIX)/projectroot

install-local:
	cp projectroot ~/.bin/projectroot
