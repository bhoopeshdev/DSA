CFLAGS = -O
CC = g++
SRC = main.cpp trie.cpp
OBJ = $(SRC:.cpp = .o)
trie: $(OBJ)
	$(CC) $(CFLAGS) -o trie $(OBJ)
clean:
	rm -f core *.o 