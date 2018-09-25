
#include "Trie.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main (int argc, char **argv)
{
  ifstream wordFile;
  ifstream qFile;
  if(argc != 3){
    cerr <<"Invalid number of arguments." << endl;
    exit(1);
  }


    wordFile.open(argv[1]);
    if(!wordFile){
      cerr<<"Unable to open file." << endl;
      exit(1);
    }

    qFile.open(argv[2]);
    if(!qFile){
      cerr<<"Unable to open file." << endl;
      exit(1);
    }


  Trie* test = new Trie();
  string word;
  while(wordFile >> word){
    test->addAWord(word);
  }
  wordFile.close();
  while(qFile >> word){
    if(test->isAWord(word)){
      cout << word << " is found" << endl;
    }
    else{
      cout << word << " is not found, did you mean:" << endl;
      std::vector<string> v = test->allWordsStartingWithPrefix(word);
      if(v.size()){
        for(unsigned int i = 0; i<v.size(); i++){
          cout << "   " << v.at(i) << endl;
        }
      }
      else{
          cout << "   " << "no alternatives found" << endl;
      }
    }
  }
  qFile.close();

  //Rule of three
  Trie rule;
  Trie rule2 (rule); //Copy Constructor
  rule = rule2; // Assignment

  return 0;
}
