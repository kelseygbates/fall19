// Kelsey Bates
// p4.cpp
// Tests operations of my heap class
#include <iostream>
#include <ctime>
#include "heap.h"
#include <iomanip> 
using namespace std;

const int SIZE1 = 10;
const int SIZE2 = 20; 
const int DUPLICATES = 5; 
const int WID = 5;
const int COLS = 10; 

int main()
{
  srand(time(0)); 
  Heap h1;
  int data;
  int loopCount; 
  cout << endl 
       << "Welcome to p4, where I will test the functionality of my heap class"
       << endl << endl; 
  cout << "Inserting " << SIZE1 << " values onto heap1 (tests insert) "
       << endl; 
  for(int i = 1; i <= SIZE1; i++) {
    data = rand() % SIZE1 + 1;
    cout << setw(WID) << data;
    h1.insert(data);
    if(i % COLS == 0)
      cout << endl; 
  }
  

  cout << endl
       << "Constructing heap 2 as copy of heap1 (tests copy constructor)"
       << endl; 
  Heap h2(h1);
  
  cout << endl << endl << "Removing all values from heap1 (tests remove)"
       << endl;
  loopCount = 1; 
  while(!h1.empty()) {
    cout << setw(WID) << h1.remove();
    if(loopCount % COLS == 0)
      cout << endl; 
    loopCount++; 
  }
  
  cout << endl << "Removing all values from heap2: " << endl;
  loopCount = 1; 
  while(!h2.empty()) {
    cout << setw(WID) << h2.remove();
    if(loopCount % COLS == 0)
      cout << endl;
    loopCount++; 
  } 

  cout << endl << endl
       << "Inserting " << SIZE2 << " values onto heap1 (tests resize)"
       << endl; 
  for(int i = 1; i <= SIZE2; i++) {
    data = rand() % 20 + 1;
    cout << setw(WID) << data; 
    h1.insert(data);
    if(i % COLS == 0)
      cout << endl; 
  }

  cout << endl
       << "Removing all values from heap1, should be " << SIZE2 << " values"
       << endl;
  loopCount = 1; 
  while(!h1.empty()) {
    cout << setw(WID) << h1.remove();
    if(loopCount % COLS == 0)
      cout << endl; 
    loopCount++; 
  }

  cout << endl << "Inserting " << SIZE1 + DUPLICATES
       << " values into heap 1" << endl;
  for(int i = 1; i < SIZE1; i++) {
    data = rand() % 20 + 1;
    cout << setw(WID) << data;
    h1.insert(data);
    if(i % COLS == 0)
      cout << endl; 
  }
  for(int i = 1; i <= DUPLICATES; i++) {
    cout << setw(WID) << data; 
    h1.insert(data); 
  }
  cout << endl << endl
       << "Assigning heap2 = heap1 (tests overloaded assignment operator)"
       << endl;
  h2 = h1; 
  cout << endl << "Flushing value " << data << " from heap1 (tests flush)"; 
  h1.flush(data);
  cout << endl << endl; 
  cout << "Removing all values from heap1, should NOT contain flushed value"
       << endl;
  loopCount = 1; 
  while(!h1.empty()) {
    cout << setw(WID) << h1.remove();
    if(loopCount % COLS == 0)
      cout << endl; 
    loopCount++; 
  }

  cout << endl << endl 
       << "Removing all values from heap2, should contain flushed value"
       << endl;
  loopCount = 1; 
  while(!h2.empty()) {
    cout << setw(WID) << h2.remove();
  }
  cout << endl << endl << "Goodbye! :)" << endl << endl; 
  return 0;
}
