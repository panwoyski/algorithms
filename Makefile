CC=g++
CFLAGS=-c -std=c++11 -Wall -pedantic
LDFLAGS=
HEADERS=graph.h iterative_dfs.h
SOURCES=iterative_main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=solver.out

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f *.o solver.out
