// Kelsey Bates
// heap.h
// Functionality of a min heap 

#ifndef HEAP_H
#define HEAP_H

class Heap
{
 public:
  class EmptyHeap{};
  // Exception class thrown when user tries to remove from empty heap 
  
  explicit Heap();
  // Constructor 

  Heap(const Heap& other);
  // Copy constructor
  
  Heap& operator=(const Heap& other);
  // Overloaded assignment operator
  
  ~Heap();
  // Destructor 
  
  void insert(int data);
  // Pre: None
  // Post: Inserts data into the heap, maintaining min heap order property

  int remove();
  // Pre: Heap is not empty 
  // Post: Removes and returns the minimum element in the heap, maintaining
  // min heap order property. If the user tries to remove from an empty heap,
  // exception class EmptyHeap{} will be thrown 

  void flush(int data);
  // Pre: None
  // Post: Removes all instances of data from the min heap, maintaining the
  // min heap order property
  
  bool empty(); 
  // Pre: None
  // Post: Returns true if the heap is empty, false otherwise 
  
 private:
  int max;   // default is 15, increases as needed
  int size;  // current size of the heap 
  int *heap; // heap array
  
  void percolateDown(int index);
  // Maintains heap order property by swapping elements with it's children
  // if the children are smaller 

  void percolateUp(int index);
  // Maintains heap order property by swapping elements with its parent if
  // the parent is smaller
  
  void resize();
  // Increases the maximum size of the heap by a factor of 2 
  
  int getIndex(int value);
  // Returns index value, returns -1 if value is not found 
};

#endif 
