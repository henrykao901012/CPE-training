#ifndef TSTACK1_H
#define TSTACK1_H

#include <iostream>
using namespace std;

template <class T, int s>
class Stack
{
public:
   Stack<T, s>();                                  // default constructor (stack size 10)
   ~Stack<T, s>() { delete[] stackPtr; }           // destructor
   bool push(const T &);                           // push an element onto the stack
   bool pop();                                     // pop an element off the stack
   bool isEmpty() const { return top == -1; }      // utility
   bool isFull() const { return top == size - 1; } // functions
   void printStack() const;

private:
   int size;    // # of elements in the stack
   int top;     // location of the top element
   T *stackPtr; // pointer to the stack
};

// Constructor with default size 10
template <class T, int s>
Stack<T, s>::Stack()
{
   size = s > 0 ? s : 10;
   top = -1;            // Stack is initially empty
   stackPtr = new T[s]; // allocate space for elements
}

// Push an element onto the stack
// return 1 if successful, 0 otherwise
template <class T, int s>
bool Stack<T, s>::push(const T &pushValue)
{
   if (!isFull())
   {
      stackPtr[++top] = pushValue; // place item in Stack
      return true;                 // push successful
   }
   return false; // push unsuccessful
}

// Pop an element off the stack
template <class T, int s>
bool Stack<T, s>::pop()
{
   if (!isEmpty())
   {
      stackPtr[top--]; // remove item from Stack
      return true;     // pop successful
   }
   return false; // pop unsuccessful
}

template <class T, int s>
void Stack<T, s>::printStack() const
{
   if (isEmpty())
   {
      cout << "The stack is empty." << endl;
   }
   else
   {
      cout << "The stack is: ";
      for (int i = top; i >= 0; --i)
         cout << stackPtr[i]<<" ";
      cout << endl;
   }
}

#endif
