CC=g++
CFLAGS=-Wall -pedantic
ODIR=obj

testmake: main.o
	$(CC) $(CFLAGS) main.o -o test

.PHONY: clean

clean:
	rm -f *.o test 
