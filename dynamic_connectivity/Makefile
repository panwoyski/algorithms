CC=g++
CFLAGS=-c -std=c++11 -Wall -pedantic
LDFLAGS=
HEADERS=graph.h
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=solver.out

all: union

union: HEADERS += union_find.h
union: clean $(OBJECTS) $(EXECUTABLE)

iterative: CFLAGS += -DUSE_DFS
iterative: HEADERS += iterative_dfs.h
iterative: clean $(OBJECTS) $(EXECUTABLE)

recursive: CFLAGS += -DUSE_DFS
recursive: CFLAGS += -DRECURSIVE
recursive: HEADERS += recursive_dfs.h
recursive: clean $(OBJECTS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f *.o solver.out
