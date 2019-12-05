// Kelsey Bates
// tree.h

#ifndef TREE_H
#define TREE_H

class Tree
{
 public:
  explicit Tree();
  // constructor

  Tree(const Tree& t);
  // copy constructor

  Tree& operator=(const Tree& other);
  // overloaded assignment operator

  ~Tree();
  // destructor

  bool insert(int key);
  // Inserts a new node into the tree with key value, if key is unique
  // Pre: key is unique
  // Post: returns true if a new Node with key is inserted into BST
  // returns false if key is not unique
  
  bool findKey(int key);
  // Pre: none
  // Post: returns true if key is found, otherwise returns false
  
  int height();
  // Pre: none
  // Post: returns the height of the tree
  
  void preOrder();
  // Pre: none
  // Post: prints all keys in the tree in a pre order traversal
  
  void inOrder();
  // Pre: none
  // Post: prints all keys in the tree in an in order traversal 
  
  void deleteNode(int key);
  // Pre: none
  // Post: if tree contains node with key, it is deleted from the tree

 private:
  struct Node {
    int key;
    Node* left;
    Node* right; 
  };
  Node* root;
  
  bool insert(Node*& root, int key);
  bool findKey(Node* root, int key);
  int height(Node* root);
  void preOrder(Node* root);
  void deleteNode(Node*& root, int key);
  void makeDeletion(Node*& root);
  void deleteAll(Node*& root);
  Node* makeCopy(Node* r);
  Node* getParent(Node* root, int key);
};

#endif
