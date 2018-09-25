CC = g++
CFLAG = -c -Wall -fsanitize=undefined -g

TrieTest: TrieTest.o Trie.o Node.o
	$(CC) -o TrieTest TrieTest.o Trie.o Node.o

TrieTest.o : TrieTest.cpp Trie.h
	$(CC) $(CFLAG) TrieTest.cpp -I ./

Trie.o : Trie.h Trie.cpp
	$(CC) $(CFLAG) Trie.cpp -I ./

Node.o: Node.h Node.cpp
	$(CC) $(CFLAG) Node.cpp -I ./

clean:
		rm -f *.o  test
