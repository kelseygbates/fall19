// Kelsey Bates
// heap.cpp
// Implementation of heap.h
#include "heap.h"

Heap::Heap()
{
  max = 15; 
  heap = new int[max];
  size = 0; 
}

Heap::Heap(const Heap& other)
{
  max = other.max;
  heap = new int[max];
  size = other.size;
  for(int i = 1; i <= size; i++)
    heap[i] = other.heap[i];
}

Heap& Heap::operator=(const Heap& other)
{
  if(this != &other) {
    delete[] heap;
    max = other.max;
    heap = new int[max];
    size = other.size;
    for(int i = 1; i <= size; i++)
      heap[i] = other.heap[i];
  }
  return *this; 
}

Heap::~Heap()
{
  delete [] heap; 
}

void Heap::insert(int data)
{
  int hole = size + 1;
  if(hole >= max)
    resize(); 
  if(hole == 1) { 
    heap[hole] = data;
    size++;
  } else if(hole < max) { 
    while(hole >= 1 && data < heap[hole/2]) {
      heap[hole] = heap[hole/2]; 
      hole = hole/2; 
    } 
    heap[hole] = data;
    size++;
  }
}

int Heap::remove()
{
  if(empty())
    throw EmptyHeap();
  else {
    int del = heap[1];
    heap[1] = heap[size];
    size--;
    percolateDown(1);
    return del;
  }
}

void Heap::flush(int data)
{
  int index = getIndex(data); 
  while(index != -1) {
    index = getIndex(data);
    heap[index] = heap[size];
    size--;
    percolateDown(index); 
    percolateUp(index);
    index = getIndex(data); 
  }
}

bool Heap::empty()
{
  return size == 0; 
}

void Heap::percolateDown(int index)
{
  int temp = heap[index];
  while((index*2 <= size && temp > heap[index*2])
        || (index*2+1 <= size && temp > heap[index*2+1]) ) {
    if(index*2+1 <= size && heap[index*2+1] <= heap[index*2]) {
      heap[index] = heap[index*2+1];
      index = index*2+1;
    } else {
      heap[index] = heap[index*2];
      index = index*2; 
    }
  }
  heap[index] = temp; 
}

void Heap::percolateUp(int index)
{
  int temp = heap[index];
  while(index >= 1 && heap[index] < heap[index/2]) {
    heap[index] = heap[index/2];
    index = index/2; 
  }
  heap[index] = temp; 
}

void Heap::resize()
{
  int* temp;
  int larger = static_cast<int>(max * 2);
  temp = new int[larger];
  for(int i = 1; i <= size; i++)
    temp[i] = heap[i];
  delete[] heap; 
  heap = temp; 
  max = larger; 
}

int Heap::getIndex(int value)
{
  for(int i = 1; i <= size; i++) {
    if(heap[i] == value)
      return i; 
  }
  return -1; 
}
