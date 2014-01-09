CFLAGS=-g -Wall
CC=arm-unknown-linux-gnueabi-gcc
AR=ar
RANLIB=ranlib
LIBS=-L./ -lcgic

all: libcgic.a index.cgi

install: libcgic.a
	cp libcgic.a /usr/local/lib
	cp cgic.h /usr/local/include
	@echo libcgic.a is in /usr/local/lib. cgic.h is in /usr/local/include.

libcgic.a: cgic.o cgic.h
	rm -f libcgic.a
	$(AR) rc libcgic.a cgic.o
	$(RANLIB) libcgic.a

index.cgi: minIni.o webpanel.o libcgic.a
	${CC} minIni.c webpanel.c -o index.cgi ${LIBS}

clean:
	rm -f *.o *.a index.cgi

