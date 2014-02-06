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
CRYPTO_MATH = $(ODIR)/cryptomath.o
LIBS = $(CIPHER_LIB) $(IO_UTILS) $(CRYPTO_MATH)
DEPENDENCIES = $(BDIR) $(ODIR) $(LIBS)

shift: $(DEPENDENCIES)
	$(CC) $(CFLAGS) -c -o $(ODIR)/shift-cipher.o ./shift-cipher/shift-cipher.c
	$(CC) $(CFLAGS) -o $(BDIR)/shift-cipher \
		$(ODIR)/shift-cipher.o $(LIBS)

affine: $(DEPENDENCIES)
	$(CC) $(CFLAGS) -c -o $(ODIR)/affine-cipher.o ./affine-cipher/affine-cipher.c
	$(CC) $(CFLAGS) -o $(BDIR)/affine-cipher \
		$(ODIR)/affine-cipher.o $(LIBS)

$(CIPHER_LIB):
	$(CC) $(CFLAGS) -c -o $@ ./lib/cipher.c

$(IO_UTILS):
	$(CC) $(CFLAGS) -c -o $@ ./lib/ioutils.c

$(CRYPTO_MATH):
	$(CC) $(CFLAGS) -c -o $@ ./lib/cryptomath.c

$(BDIR):
	if [ ! -d $(BDIR) ]; then mkdir $(BDIR); fi

$(ODIR): $(BDIR)
	if [ ! -d $(ODIR) ]; then mkdir $(ODIR); fi

clean:
	if [ -d $(BDIR) ]; then rm -r $(BDIR); fi
