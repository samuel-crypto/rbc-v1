BINARY := rbc
OBJECTS := rbc.o main.o

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BINARY)
	rm -f $(OBJECTS)
