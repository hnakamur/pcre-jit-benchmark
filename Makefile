CC=		gcc
CFLAGS=		-g -Wall -O2 -fomit-frame-pointer
INCLUDES=
LIBS=		-lpcre
#INCLUDES=	-I/opt/include
#LIBS=		-L/opt/lib64 -lpcre

.SUFFIXES:.c .o

.c.o:
	$(CC) -c $(INCLUDES) $(CFLAGS) $(DFLAGS) $< -o $@

all: test-pcre

test-pcre: test-pcre.o
	$(CC) $(CFLAGS) -o $@ test-pcre.o $(LIBS)

clean:
	rm -f *.o a.out *~ test test-posix test-cpp
