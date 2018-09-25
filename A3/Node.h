
// Constant size of the alphabets
const int POTENTIAL_SIZE = 26;

class Node {

public:
  // A flag for whether the current node is the end of a word
  bool isWord;
  // The potential branch for the this node
  Node* branch[POTENTIAL_SIZE];
  // Constructor for Node Class
  Node();
};
