// Kelsey Bates
// stack.cpp
// Implementation of stack.h
#include "stack.h"

Stack::Stack(int size)
{
  if(size < 3)
    size = 10;
  max = size;
  list = new int[max];
  top = 0;
}

Stack::Stack(const Stack& s)
{
  max = s.max;
  list = new int[max];
  top = s.top;
  for(int i = 0; i < top; i++)
    list[i] = s.list[i];
}

Stack& Stack::operator=(const Stack& other)
{
  if(this != &other) {
    delete [] list;
    max = other.max;
    list = new int[max];
    top = other.top;
    for (int i = 0; i < top; i++) 
      list[i] = other.list[i];
  }
  return *this;
}

Stack::~Stack()
{
  delete [] list; 
}

void Stack::push(int data)
{
  if (data % 2 != 0) {
    if(full())
      resize();
    list[top] = data;
    top++;
  }
}

int Stack::pop()
{
  if(isEmpty())
    throw EmptyStack();
  else {
    top--;
    return list[top];
  } 
}

bool Stack::isEmpty() const
{
  return top == 0;
}

bool Stack::full() const
{
  return top == max; 
}

void Stack::resize()
{
  int* temp;
  int larger = static_cast<int>(max * 1.5);
  temp = new int[larger];
  for (int i = 0; i < top; i++)
    temp[i] = list[i];
  delete [] list;
  list = temp;
  max = larger; 
}
