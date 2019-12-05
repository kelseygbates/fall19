// Kelsey Bates
// tree.cpp
// Implementation of tree.h

#include <iostream>
#include <stack>
#include "tree.h"
using namespace std; 

// public methods

// constructor
Tree::Tree()
{
  root = nullptr;  
}

// copy constructor
Tree::Tree(const Tree& t)
{
  if(t.root == nullptr)
    root = nullptr;
  else
    root = makeCopy(t.root);
}

// overloaded assignment operator
Tree& Tree::operator=(const Tree& other)
{
  if(this != &other) {
    deleteAll(root);
    root = makeCopy(other.root);
  }
  return *this;
}

// destructor 
Tree::~Tree()
{
  deleteAll(root);
}

bool Tree::insert(int key)
{
  return insert(root, key);
}

bool Tree::findKey(int key)
{
  return findKey(root, key);
}

int Tree::height()
{
  return height(root);
}

void Tree::preOrder()
{
  preOrder(root);
}

void Tree::inOrder()
{
  stack<Node*> s;
  Node* current = root;
  while(current != nullptr || !s.empty()) {
    if(current != nullptr) {
      s.push(current);
      current = current->left; 
    } else {
      current = s.top();
      s.pop();
      cout << current->key << " ";
      current = current->right; 
    }
  }
}

void Tree::deleteNode(int key)
{
  if(findKey(key))
    deleteNode(root, key);
}

// private methods 
bool Tree::insert(Node*& root, int key)
{
  if(root == nullptr) {
    root = new Node;
    root->key = key;
    root->left = nullptr;
    root->right = nullptr;
    return true;
  } else if (root->key == key) {
    return false;
  } else if (root->key > key) {
    return insert(root->left, key);
  } else {
    return insert(root->right, key);
  }
}

bool Tree::findKey(Node* root, int key)
{
  if(root != nullptr) {
    if(root->key == key)
      return true;
    else if (root->key > key)
      return findKey(root->left, key);
    else if (root->key < key)
      return findKey(root->right, key);
    else
      return false; 
  } else {
    return false;
  }  
}

int Tree::height(Node* root)
{
  int leftH;
  int rightH;
  if (root == nullptr)
    return 0;
  else {
    leftH = height(root->left);
    rightH = height(root->right);
    if(leftH > rightH)
      return 1 + leftH;
    else
      return 1 + rightH;
  }
}

void Tree::preOrder(Node* root)
{
  if(root != nullptr) {
    cout << root->key << " ";
    preOrder(root->left);
    preOrder(root->right);
  }
}

void Tree::deleteNode(Node*& root, int key)
{
  Node* parent;
  if(root != nullptr) {
    parent = getParent(root, key);
    if(parent->right != nullptr && parent->right->key == key)
      makeDeletion(parent->right);
    else
      makeDeletion(parent->left);
   }   
}

void Tree::makeDeletion(Node*& delPtr)
{
  Node* helper;
  if(delPtr == nullptr) {
    return;
  } else if (delPtr->right == nullptr) {
    helper = delPtr;
    delPtr = delPtr->left;
    delete helper;
  } else if (delPtr->left == nullptr) {
    helper = delPtr;
    delPtr = delPtr->right; 
    delete helper; 
  } else {
    helper = delPtr->left;
    while(helper->right != nullptr && helper->right->right != nullptr)
            helper = helper->right;
    if(helper->right == nullptr) {
      delPtr->key = helper->key;
      makeDeletion(delPtr->left);
    } else {
      delPtr->key = helper->right->key;
      makeDeletion(helper->right);
    }
  }
}

void Tree::deleteAll(Node*& root)
{
  if(root != nullptr) {
    deleteAll(root->left);
    deleteAll(root->right);
    delete root;
    root = nullptr;
  }
}

Tree::Node* Tree::makeCopy(Node* root)
{
  if(root == nullptr)
    return nullptr;
  else {
    Node* temp = new Node;
    temp->key = root->key;
    temp->left = makeCopy(root->left);
    temp->right = makeCopy(root->right);
    return temp; 
  }
}

Tree::Node* Tree::getParent(Node* root, int key)
{
  if(root == nullptr)
    return nullptr;
  else if(root->left == nullptr && root->right == nullptr)
    return nullptr;
  else if( (root->left !=nullptr && root->left->key == key)
           || (root->right != nullptr && root->right->key == key)) {
      return root;
  } else if(root->key > key)
    return getParent(root->left, key);
  else
    return getParent(root->right, key); 
}

