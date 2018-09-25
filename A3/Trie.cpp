/*
 Name: MingFeng(Ken) Wang
 Class: CS3505
 Date: Sept.17.2018
 */
 #include <iostream>
 #include <string>
 #include "Trie.h"
 using namespace std;



 Trie::Trie(){
   root = new Node();
   wordCount = 0;
 }
 Trie::Trie(const Trie& Other){
   root = Other.root;
   wordCount = Other.wordCount;
 }
 Trie::~Trie(){
   delete root;
 }
 Trie& Trie::operator=(Trie Other){
   swap(root,Other.root);
   swap(wordCount,Other.wordCount);
   return *this;
 }
 void addAWordHelper(Node* &curr,string key, unsigned int index){
   //Base case
   if(curr == NULL) {
     curr = new Node();}
   if(index == key.length()){
     curr->isWord = true;
     return;
   }
   int nextIndex = key.at(index) - 'a';
   addAWordHelper(curr->branch[nextIndex],key,index+1);
 }
 void Trie::addAWord(string key){
   addAWordHelper(root,key,0);
   wordCount++;
 }
 bool isAWordHelper(Node* curr,string key, unsigned int index){
   //Base case
   if(!curr) {
     return false;
   }
   if(index == key.length()){
     return curr->isWord;
   }
   int nextIndex = key.at(index) - 'a';
   return isAWordHelper(curr->branch[nextIndex],key,index+1);
 }
 bool Trie::isAWord(string key){
   return isAWordHelper(root,key,0);
 }
 //Returns the node at the end of the word
 Node* findWord(Node* curr, string word, unsigned int index){
   //Base case
   if(!curr) {
     return NULL;
   }
   if(index == word.length()){
     return curr;
   }
   int nextIndex = word.at(index) - 'a';
   return findWord(curr->branch[nextIndex],word,index+1);
 }
 void allWordsStartingWithPrefixHelper(Node* start, vector<string> &ls, char* prefix, unsigned int index){
   if(!start) return;
   if(start->isWord){
     char temp[index+1];
     for(unsigned int i = 0; i< index; i++){
       temp[i] = prefix[i];
     }
     temp[index] = '\0';
     ls.push_back(string(temp));
   }
   for(int i = 0; i<POTENTIAL_SIZE; i++){
     if(start->branch[i]){
       prefix[index] = i + 'a';
       allWordsStartingWithPrefixHelper(start->branch[i],ls,prefix,index+1);
     }
   }
 }
 vector<string> Trie::allWordsStartingWithPrefix(string prefix){
   vector<string> result;
   char pre[45];
   //Coner Case where prefix is empty string
   if(prefix == ""){
     allWordsStartingWithPrefixHelper(root,result,pre,0);
     return result;
   }
   Node* start = findWord(root,prefix,0);

   if(start){
     int index;
     for(unsigned int i = 0; i<prefix.length(); i++){
      pre[i] = prefix[i];
      index = i;
     }
     allWordsStartingWithPrefixHelper(start,result,pre,index+1);
   }
   return result;
 }
 void wordsWithWildcardPrefixHelper(Node* curr, vector<string> &ls, char* buffer, string prefix, unsigned int index){
   if(!curr) return;
   if(curr->isWord){
     char temp[index+1];
     for(unsigned int i = 0; i< index; i++){
       temp[i] = buffer[i];
     }
     temp[index] = '\0';
     ls.push_back(string(temp));
   }
    if(index < prefix.length()){
      int preIndex = prefix.at(index) - 'a';
      if(preIndex == -34){ //wildcard case 63-97
        for(unsigned int i = 0; i<POTENTIAL_SIZE; i++){
          if(curr->branch[i]){
            buffer[index] = i + 'a';
            wordsWithWildcardPrefixHelper(curr->branch[i],ls,buffer,prefix,index+1);
          }
        }
      }
      else if(curr->branch[preIndex]){
         buffer[index] = preIndex + 'a';
         wordsWithWildcardPrefixHelper(curr->branch[preIndex],ls,buffer,prefix,index+1);
       }
    }
    else{
      for(unsigned int i = 0; i<POTENTIAL_SIZE; i++){
        if(curr->branch[i]){
          buffer[index] = i + 'a';
          wordsWithWildcardPrefixHelper(curr->branch[i],ls,buffer,prefix,index+1);
        }
      }
    }
  }
 vector<string> Trie::wordsWithWildcardPrefix(string prefix){
   vector<string> result;
   char pre[45];
   //Coner Case where prefix is empty string
   if(prefix == ""){
     allWordsStartingWithPrefixHelper(root,result,pre,0);
     return result;
   }

   wordsWithWildcardPrefixHelper(root,result,pre,prefix,0);
   return result;
 }
 void print(char* word, unsigned int index){
   for(unsigned int i = 0; i< index; i++){
     cout << word[i] << "";
   }
 }
 void printAllWordsHelper(Node* curr, char* word, unsigned int index){
   if(!curr){
     return;
   }
   if(curr->isWord){
    print(word,index);
    cout << endl;
   }
   for(unsigned int i = 0; i<POTENTIAL_SIZE; i++){
     if(curr->branch[i]){
       word[index] =  i + 'a';
       printAllWordsHelper(curr->branch[i],word,index+1);
     }
   }
 }

 void Trie::printAllWords(){
   if(!root) return;
   char word[45]; //Logest English Word
  printAllWordsHelper(root,word, 0);
   }
