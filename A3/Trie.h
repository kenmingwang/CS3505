/*
 Name: MingFeng(Ken) Wang
 Class: CS3505
 Date: Sept.17.2018
 */
#include <string>
#include <vector>
#include "Node.h"
using namespace std;


/* Generates a Trie */
class Trie {

private:
  // The root node of the trie
  Node* root;

public:
  // Inner class for the node structure
  int wordCount;
  // The default Constructor without any parameters
  Trie();
  // The Deep copy Constructor, parameter is the source Trie.
  Trie(const Trie& Other);
  // The destructor for the trie.
  ~Trie();
  // The assignment operation for the trie, parameter is the source Trie.
  Trie& operator=(Trie other);
  // Adds key into the trie.
  void addAWord(string key);
  // Checks if key is in the trie.
  bool isAWord(string key);
  // finds all the words starts with prefix(Including prefix if isAWord(prefix))
  vector<string> allWordsStartingWithPrefix(string prefix);
  // finds all the words in the trie with the prefix, but prefix can contain 0
  // or more wildcard character '?'.
  vector<string> wordsWithWildcardPrefix(string prefix);
  // print all words in trie for test purpose
  void printAllWords();
};
