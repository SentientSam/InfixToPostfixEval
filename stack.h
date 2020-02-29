// ***********************************************************
// * Author: Samuel Lamb                                     *
// * Class: cop4530                                          *
// * Assignment: Assignemnt 3                                *
// * Filename: stack.h                                       *
// * Date Created: 2/13/2020                                 *
// * References: Previous projects, cplusplus                *
// *                                                         *
// * Description:                                            *
// * Header file for the Stack vector class                  *
// * Definitions and descriptions can be seen in the         *
// * stach.hpp definition file                               *
// ***********************************************************

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <sstream>
#include <cstring>
#include <initializer_list>
#include <vector> // Useful

namespace cop4530
{
  template <typename T>
  class Stack
  {
    public:
        void push(const T& x);
        void push(T && x);
        void pop();
        T& top();
        const T& top() const;
        size_t size() const;
        bool empty() const;
        void clear();
        void print(std::ostream& os, char ofc = ' ') const;
        std::vector<T> getSTLV() const;

        Stack();
        Stack(Stack <T> &&);
        Stack<T> & operator = (const Stack<T>&);
        Stack(const Stack<T>&);
        ~Stack();
        Stack<T> & operator = (Stack<T> &&);
  
    private:
        std::vector<T> STLV;
  };

  template <typename T>
  std::ostream& operator << (std::ostream& os, const Stack<T>& a);
  template <typename T>
  bool operator == (const Stack<T>&, const Stack<T>&); 
  template <typename T>
  bool operator != (const Stack<T>&, const Stack<T>&);
  template <typename T>
  bool operator <= (const Stack<T>&, const Stack<T>&);
  #include "stack.hpp"
}
#endif