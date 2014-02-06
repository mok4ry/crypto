# Makefile for crypto projects

SHELL = /bin/sh
CC = gcc
CFLAGS = -Wall
.SUFFIXES:
.SUFFIXES: .c .o

BDIR = ./build
ODIR = ./build/obj
CIPHER_LIB = $(ODIR)/cipher.o
IO_UTILS = $(ODIR)/ioutils.o

shift: $(BDIR) $(ODIR) $(CIPHER_LIB) $(IO_UTILS)
	$(CC) $(CFLAGS) -c -o $(ODIR)/shift-cipher.o ./shift-cipher/shift-cipher.c
	$(CC) $(CFLAGS) -o $(BDIR)/shift-cipher \
		$(ODIR)/shift-cipher.o $(CIPHER_LIB) $(IO_UTILS)

$(CIPHER_LIB):
	$(CC) $(CFLAGS) -c -o $@ ./lib/cipher.c

$(IO_UTILS):
	$(CC) $(CFLAGS) -c -o $@ ./lib/ioutils.c

$(BDIR):
	if [ ! -d $(BDIR) ]; then mkdir $(BDIR); fi

$(ODIR): $(BDIR)
	if [ ! -d $(ODIR) ]; then mkdir $(ODIR); fi

clean:
	if [ -d $(BDIR) ]; then rm -r $(BDIR); fi
