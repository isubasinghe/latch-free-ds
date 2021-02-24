CC	=	g++

CFLAGS	=	-O2 -g -Wall -Werror -pedantic -std=gnu99
EXE = main
OBJ = main.o llist.o

all: $(EXE)

debug: CFLAGS = -Wall -Werror -pedantic -lpthread -std=gnu99 -O0 -g -DDEBUG

main.o: llist.o
llist.o: llist.hpp



debug: $(OBJ)
	$(CC) -o $(EXE) $(OBJ) $(CFLAGS)
	
$(EXE): $(OBJ)
		$(CC) -o $(EXE) $(OBJ) $(CFLAGS)

.PHONY: clean cleanly

clean:
	rm -rf $(OBJ)