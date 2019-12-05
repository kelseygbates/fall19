// Kelsey Bates
// p3.cpp
// Tests operations of my binary search tree class 

#include <iostream>
#include "tree.h"
using namespace std;

const int DATA[] = {12, 5, 9, 8, 1, 3, 17, 6, 2, 10, 11, 14, 4, 7, 19,
                    20, 18, 13, 16, 15};
const int DATA_LEN = 20;

int main()
{
  cout << endl << "Welcome to P3!" << endl << "Constructing an empty tree (t1)"
       << endl;
  Tree t1;
  cout << endl << "Printing traversals of the empty tree: "; 
  t1.preOrder();
  t1.inOrder();
  cout << endl << "Height of empty tree: " << t1.height()
       << endl; 
  cout << endl << "Inserting " << DATA_LEN << " values into t1..."
       << endl;
  for (int i = 0; i < DATA_LEN; i++) {
    t1.insert(DATA[i]);
  }

  cout << endl << "Pre-order traversal (t1): ";
  t1.preOrder();
  cout << endl << "In-order traversal (t1):  "; 
  t1.inOrder();
  cout << endl << endl << "Height (t1): " << t1.height() << endl << endl; 

  cout << "Attempting to insert a duplicate value, should be rejected" << endl
       << "Inserting value " << DATA[7] << " into t1..." << endl;
  if(t1.insert(DATA[7]))
    cout << "Value was accepted" << endl;
  else
    cout << "Value was rejected" << endl; 

  cout << endl << "Making a new tree (t2) as a copy of t1" << endl;
  Tree t2 = t1;
  cout << endl << "Pre-order traversal (t2): ";
  t2.preOrder();
  cout << endl << "Pre-order traversal (t1): ";
  t1.preOrder();

  cout << endl << endl
       << "Testing findKey method on t2 with key " << DATA[4] << endl;
  if(t2.findKey(DATA[4]))
    cout << "Found key" << endl << endl;
  else
    cout << "Did not find key" << endl << endl;

  cout << "Deleting node with key " << DATA[14] << " from t1..." << endl; 
  t1.deleteNode(DATA[14]);
  cout << "In-order traversal (t1): ";
  t1.inOrder();
  cout << endl << endl;
  cout << "Deleting node with key " << DATA[3] << " from t1..." << endl;
  t1.deleteNode(DATA[3]);
  cout << "In-order traversal (t1): "; 
  t1.inOrder();
  cout << endl << endl;

  cout << "Assigning t2 = t1 (tests overloaded assignment operator)"
       << endl;
  t2 = t1;
  cout << "t2 should produce the same in-order traversal as t1" << endl
       << "In-order traversal (t2): ";
  t2.inOrder();
  cout << endl << "In-order traversal (t1): ";
  t1.inOrder();
  cout << endl << endl;
  
  return 0;
}
