// Kelsey Bates
// p2.cpp
// Tests operations of the stack class

#include <iostream>
#include <iomanip>
#include "stack.h"

using namespace std;
const int SIZE = 10;
const int OVERFILL = 15;

int main()
{
  cout << endl 
       << "Welcome to my second programming assignment, where I will test"
       << endl <<  "operations of my stack class" << endl; 

  // Test constructor 
  cout << "Constructing a stack (s1) of size " << SIZE << endl << endl;
  Stack s1;

  // Test push
  cout << "Attempting to push values 0 thru " << SIZE << " onto stack" << endl
       << "only even values will be pushed" << endl;
  for (int i = 0; i <= SIZE; i++) {
    s1.push(i);
  }

  // Test copy constructor
  cout << endl 
       << "Constructing a new stack (s2) as a copy of s1 (copy constructor)"
       << endl; 
  Stack s2 = s1;
  
  // Test pop and isEmpty
  cout << "Popping all values off s1 & s2, expect to see 9 7 5 3 1"
       << " (also tests isEmpty)" << endl << "s1: "; 
  while(!s1.isEmpty())
    cout << s1.pop() << "  ";
  cout << endl
       << "s2: ";
  while(!s2.isEmpty())
    cout << s2.pop() << "  ";
  cout << endl;

  // Test resize and full
  cout << endl << "Test resize method, pushing " << OVERFILL
       << " integers into s1, which was declared as size " << SIZE << endl
       << "(also tests full)" << endl;
  for(int i = 0; i < OVERFILL; i++)
    s1.push(3);
  cout << "Popping from s1: ";
  int total = 0;
  while(!s1.isEmpty()) {
    total++;
    cout << s1.pop() << "  ";
  }
  cout << endl << "Popped " << total << " values" << endl << endl; 

  // Test overloaded assignment operator
  cout << "Pushing 3, 3, 3 to s1" << endl << "Pushing 5, 5, 5 to s2" << endl;
  for(int i = 0; i < 3; i++) {
      s1.push(3);
      s2.push(5);
  }
  cout << endl; 
  cout << "Testing overloaded assignment operator, assigning s1 = s2" << endl;
  s1 = s2;
  cout << "Popping values from s1 and s2, they should be the same" << endl
       << "s1: ";
  while (!s1.isEmpty()) 
    cout  << s1.pop() << "  "; 
  cout << endl
       << "s2: ";
  while (!s2.isEmpty()) 
    cout << s2.pop() << "  ";

  // Catch EmptyStack
  cout << endl << endl
       << "Trying to catch empty stack exception by popping from s1" << endl;
  try {
    s1.pop();
  } catch(Stack::EmptyStack) {
    cout << "Error! Cannot pop from empty stack" << endl << endl;
  }
  
  return 0;
}
