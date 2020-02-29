// ***********************************************************
// * Author: Samuel Lamb                                     *
// * Class: cop4530                                          *
// * Assignment: Assignemnt 3                                *
// * Filename: stack.hpp                                     *
// * Date Created: 2/13/2020                                 *
// * References: Dr. Gaitros, textbook                       *
// *                                                         *
// * Description:                                            *
// *                                                         *
// *                                                         *
// *                                                         *
// ***********************************************************

// #include "stack.h"

// ******************************************************************************************************************
// * Name: Stack()                                                                                                  *                                                 
// * Description: Zero-argument constructor for the stack class                                                     *                 
// * Reference: None used                                                                                           *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
Stack<T>::Stack() 
{
  
}

// ******************************************************************************************************************
// * Name: Stack(Stack<T> && x)                                                                                     *                                                 
// * Description: Move Constructor, allowing resources in rvalue objects to be moved to lvalue                      * 
// * objects without copying.                                                                                       *                                      
// * Reference: Docs.microsoft.com                                                                                  *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
Stack<T>::Stack(Stack<T>&& x) 
{
  *this = x; 
}

// ******************************************************************************************************************
// * Name: Stack<T> & Stack<T>::operator = (const Stack<T>& b)                                                      *                                                 
// * Description: copy assignment operator=                                                                         *                                      
// * Reference: none used                                                                                           *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
Stack<T> & Stack<T>::operator = (const Stack<T>& b) // Copy assignment operator=
{
  STLV = b.STLV;
  return *this;
}

// ******************************************************************************************************************
// * Name: Stack<T>::Stack(const Stack<T>& x)                                                                       *                                                 
// * Description: copy constructor                                                                                   *                                     
// * Reference: None used                                                                                           *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
Stack<T>::Stack(const Stack<T>& x)
{
  *this = x;
}

// ******************************************************************************************************************
// * Name: ~Stack                                                                                                   *                                                 
// * Description: Class Destructor, calls clear function                                                            *                                  
// * Reference: None used                                                                                           *         
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
Stack<T>::~Stack() 
{
  STLV.clear();
}

// ******************************************************************************************************************
// * Name: Stack<T> & Stack<T>::operator = (Stack<T>&& b)                                                           *                                                 
// * Description: Move assignment operator=                                                                         *                                     
// * Reference: None used                                                                                           *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
Stack<T> & Stack<T>::operator = (Stack<T>&& b)
{
  STLV = b.STLV;
  return *this;
}

// ******************************************************************************************************************
// * Name: void Stack<T>::push(T && x)                                                                              *                                                 
// * Description: pushes onto stack, const version                                                                  *                                     
// * Reference: None used                                                                                           *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
void Stack<T>::push(const T& x)
{ 
  STLV.push_back(x);
}

// ******************************************************************************************************************
// * Name: void Stack<T>::push(T && x)                                                                              *                                                 
// * Description: pushes onto stack                                                                                 *                                     
// * Reference: None used                                                                                           *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
void Stack<T>::push(T&& x)
{ 
	STLV.push_back(x);
}

// ******************************************************************************************************************
// * Name: void Stack<T>::pop()                                                                                     *                                                 
// * Description: pops the top of the stack                                                                         *                                     
// * Reference: None used                                                                                           *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
void Stack<T>::pop()
{ 
	STLV.pop_back();
}

// ******************************************************************************************************************
// * Name: T& Stack<T>::top()                                                                                       *                                                 
// * Description: returns the top of the stack                                                                      *                                     
// * Reference: None used                                                                                           *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
T& Stack<T>::top()
{ 
	return STLV.back();
}

// ******************************************************************************************************************
// * Name: const T& Stack<T>::top() const                                                                           *                                                 
// * Description: returns the top of the stack, const version                                                       *                                     
// * Reference: None used                                                                                           *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
const T& Stack<T>::top() const
{ 
	return STLV.back();
}
	
// ******************************************************************************************************************
// * Name: size_t Stack<T>::size() const                                                                            *                                                 
// * Description: Returns size of Stack vector                                                                      *                                     
// * Reference: None used                                                                                           *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
size_t Stack<T>::size() const
{
	return STLV.size();
}

// ******************************************************************************************************************
// * Name: empty()                                                                                                  *                                                 
// * Description: returns an empty stack                                                                            *                                     
// * Reference: cplusplus.com vector functions                                                                      *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
bool Stack<T>::empty() const
{
  return STLV.empty();
}

// ******************************************************************************************************************
// * Name: Clear()                                                                                                  *                                                 
// * Description: Clears the stack, returning a container of size 0.                                                *                                      
// * Reference: cplusplus.com vector functions                                                                      *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
void Stack<T>::clear()
{
  STLV.clear();
}

// ******************************************************************************************************************
// * Name: void Stack<T>::print(std::ostream& os, char ofc) const                                                   *                                                                                                 
// * Description: is a print function                                                                               *                                      
// * Reference: None used                                                                                           *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
void Stack<T>::print(std::ostream& os, char ofc) const
{ 
  for(auto i = STLV.begin(); i != STLV.end(); ++i)
  {
    os << *i << ofc;
  }
}

// ******************************************************************************************************************
// * Name: getSTLV                                                                                                  *                                                 
// * Description: Retreives the STLV vector                                                                         *                                    
// * Reference:                                                                                                     *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
std::vector<T> Stack<T>::getSTLV() const
{ 
	return STLV;
}

// ******************************************************************************************************************
// * Name: std::ostream & operator << (std::ostream& os, const Stack<T>& a)                                         *                                                 
// * Description: os operator                                                                                       *    
// *                                                                                                                *
// * Reference: None used                                                                                           *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
std::ostream & operator << (std::ostream& os, const Stack<T>& a)
{ 
	a.print(os);
	return os;
}

// ******************************************************************************************************************
// * Name: bool operator != (const Stack<T>& a, const Stack<T>& b)                                                  *                                                 
// * Description: Equal function                                                                                    *    
// *                                                                                                                *
// * Reference: cplusplus.com                                                                                       *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
bool operator == (const Stack<T>& a, const Stack<T>& b)
{ 
  // return (a == b);
  if (a.size() != b.size()) 
  {return false;}
  else
  {return true;}
}

// ******************************************************************************************************************
// * Name: bool operator != (const Stack<T>& a, const Stack<T>& b)                                                  *                                                 
// * Description: Not Equal function                                                                                *    
// *                                                                                                                *
// * Reference: None used                                                                                           *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
bool operator != (const Stack<T>& a, const Stack<T>& b)
{ 
	return !(a == b);
}

// ******************************************************************************************************************
// * Name: bool operator <= (const Stack<T>& a, const Stack<T>& b)                                                  *                                                 
// * Description: Less than or equal function                                                                       *    
// *                                                                                                                *
// * Reference: None used                                                                                           *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
template <typename T>
bool operator <= (const Stack<T>& a, const Stack<T>& b)
{ 
	return a.getSTLV() <= b.getSTLV();
}