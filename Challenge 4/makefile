SOURCES= main.cpp

OBJECTS=$(SOURCES:.cpp=.o)

CC=g++
LIBS=
LIB_PATHS=
INCLUDE_PATHS=
CFLAGS=-O -g -std=c++11 -Wall

EXECUTABLE=main

MAKE_CMD=$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJECTS) $(LIB_PATHS) $(INCLUDE_PATHS) $(LIBS)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(MAKE_CMD)

.cpp.o:
	$(CC) $(CFLAGS) -c -o $@ $<

remake:
	rm $(EXECUTABLE)
	$(MAKE_CMD)

clean:
	rm $(EXECUTABLE)
	rm $(OBJECTS)
