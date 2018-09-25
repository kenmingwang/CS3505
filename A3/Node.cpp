#include"Node.h"
 #include <iostream>
using namespace std;
 Node::Node(){
  for(int i = 0; i<POTENTIAL_SIZE; i++){
    branch[i] = NULL;
  }
  isWord = NULL;
 }
