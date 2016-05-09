CC     ?= cc
PREFIX ?= /usr/local

SRC  = projectroot.c libprojectroot.c
DEPS = $(wildcard deps/*/*.c)
OBJS = $(DEPS:.c=.o)

all: projectroot libprojectroot.o

projectroot: $(SRC) Makefile $(OBJS)
	$(CC) -I./ -Ideps/commander -std=c99 -Wall -O3 $(SRC) $(OBJS) -o projectroot

libprojectroot.o: libprojectroot.c libprojectroot.h Makefile
	$(CC) libprojectroot.c -O3 -std=c99 -c -o libprojectroot.o

%.o: %.c
	$(CC) $< -O3 -std=c99 -c -o $@

install:
	cp projectroot $(PREFIX)/projectroot

install-local:
	cp projectroot ~/.bin/projectroot
