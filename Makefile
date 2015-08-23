projectroot: projectroot.c Makefile
	gcc -std=gnu11 -O3 projectroot.c -o projectroot

install-local:
	cp projectroot ~/.bin/projectroot
