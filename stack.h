// Kelsey Bates
// stack.h
// Defines functionality of stack class

#ifndef STACK_H
#define STACK_H

class Stack
{
 public:
  class EmptyStack{};
  // exception thrown when user tries to pop from empty stack

  explicit Stack(int size = 50);

  Stack(const Stack& s);

  Stack& operator=(const Stack& rhs);

  ~Stack();
  
  void push(int data);
  // pre: a is an even integer
  // post: a is added to the top of the stack

  int pop();
  // pre: stack is not empty (possible EmptyStack exception)
  // post: removes and returns the top element in the stack

  bool isEmpty() const;
  // returns status of stack

 private:
  int* list; // stack
  int max; // size of stack
  int top; // top of stack

  bool full() const;
  // returns status of stack

  void resize();
  // allocates more memory for stack 
};

#endif
