// ***********************************************************
// * Author: Samuel Lamb                                     *
// * Class: cop4530                                          *
// * Assignment: Assignemnt 3                                *
// * Filename: in2post.cpp                                   *
// * Date Created: 2/13/2020                                 *
// * References: Textbook, cplusplus,                        *
// * stack overflow, rosettacode                             *
// * Description:                                            *
// * Entering an expression into this will adjust the        *
// * expression to postfix notation and then evaluate.       *
// *                                                         *
// ***********************************************************

#include "vector"
#include "sstream"
#include "iostream"
#include "stack.h"
#include "cctype"
#include "cmath"

using namespace std;
using namespace cop4530;

bool IsValidParen(string str);
bool IsNumeric(string & s);
bool IsOperand(string str);
bool IsOperator(string str);
bool AlphaTest(string str);
void EvaluatePostfix(vector<string> &str);
string InfixToPostfix(const string& infix);

int main(void)
{
  vector <string> STLin;
  string STLinput;
  do{
    STLin.clear();
		cout << "Enter expression (Enter \"exit\" to quit program): ";
		getline(cin, STLinput);
    if (STLinput.size() > 0 && !IsValidParen(STLinput) && STLinput != "exit") 
    {
      cout << "You entered an invalid expression. Please try again\n";
      continue; 
    }
    if (STLinput == "expression")
    {
      cout << "Very funny, but try a mathematical one!" << endl;
      continue;
    }
    if (STLinput == "exit") continue;
    cout << "infix:   " << STLinput << endl;
    cout << "postfix: " << InfixToPostfix(STLinput) << endl;
    STLinput = InfixToPostfix(STLinput);
    stringstream sstream(STLinput);
    while (sstream >> STLinput)
    {
			STLin.push_back(STLinput);
    }
    EvaluatePostfix(STLin);
	}while(STLinput != "exit");
	return 0;
}

// ******************************************************************************************************************
// * Name: IsValidParen                                                                                             *                                                 
// * Description: A check to make sure the expression has valid parens                                              *    
// * Reference: Peter McGoron helped with a prototype function                                                      *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
bool IsValidParen(string str)
{
  Stack<string> checker;
  for (auto& x: str)
  {
    if (x == '(')
    {
      checker.push("(");
    }
    if (x == ')' && !checker.empty())
    {
      if (checker.top() != "(")
      {
        return false;
      }
      checker.pop();
    }
    else if (x == ')' && checker.empty())
    {
      return false;
    }
  }
  return checker.empty();
}

// ******************************************************************************************************************
// * Name: AlphaTest                                                                                                *                                                 
// * Description: A check to make sure the string entered is alphanumerical                                         *    
// * Reference: none used, other than cplusplus for isalnum function                                                *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************

bool AlphaTest(string str)
{
	for(int i = 0; i < int(str.size()); i++)
  {
		if(isalnum(str[i]) == false)
    {
			return false;
    }
  }
	return true;
}

// ******************************************************************************************************************
// * Name: IsOperand                                                                                                *                                                 
// * Description: Takes in a string and returns true if it is not an operator                                        *    
// * Reference: None used                                                                                           *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
bool IsOperand(string str)
{
	if(str != "+" &&  str != "-" && str != "*" && str != "/" && str != "(" && str != ")" && str != "^")
		return true;
	else
		return false;
}

// ******************************************************************************************************************
// * Name: IsNumeric                                                                                                *                                                 
// * Description: Takes in a string and returns true if it is numeric                                               *    
// * Reference: rosettacode                                                                                         *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
bool IsNumeric(string & str)
{
	return(strspn(str.c_str(), ".0123456789") == str.size());
}

// ******************************************************************************************************************
// * Name: IsOperator                                                                                               *                                                 
// * Description: Takes in a string and returns false if it is not an operator                                      *    
// * Reference: None used                                                                                           *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
bool IsOperator(string str)
{
  if(str == "*" || str == "/" || str == "+" || str == "-" || str == "^")
  {
    return true;
  } 
  else return false;
}

// ******************************************************************************************************************
// * Name: Operation                                                                                                *                                                 
// * Description: Performs operation on 2 values                                                                    *    
// * Reference: cplusplus (for pow function)                                                                        *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
float Operation(string op, float val_1, float val_2)
{
  if(op == "+")
    return val_2 + val_1;
  else if(op == "-")
    return val_2 - val_1;
  else if(op == "*")
    return val_2 * val_1;
  else if(op == "/")
    return val_2 / val_1;
  else if(op == "^")
    return pow(val_2,val_1); 
  else
    return 0;
}

// **************************************************************************************************************************************
// * Name: InfixToPostfix                                                                                                               *                              
// * Description: Takes the input string and converts it to postfix notation. Heavily used concepts from shunting yard algorithm.       *                                     
// * Reference: stack overflow                                                                                                          *            
// * Author: Samuel Lamb                                                                                                                *                          
// **************************************************************************************************************************************
string InfixToPostfix(const string& infix) 
{
  const string ops = "-+/*^";
  stringstream ss;
  string token;
  Stack<int> intStack;
  stringstream input(infix);
  while (getline(input, token, ' '))
  {
    if (token.empty()) 
    {
      continue;
    }
    char c = token[0];
    size_t idex = ops.find(c);
    if (idex != string::npos) {
      while (!intStack.empty()) {
        int prc2 = intStack.top() / 2;
        int prc1 = idex / 2;
        if (prc2 > prc1 || (prc2 == prc1 && c != '^'))
        {
          ss << ops[intStack.top()] << ' ';
          intStack.pop();
        }
        else break;
      }
      intStack.push(idex);
    }
    else if (c == '(') 
    {
      intStack.push(-2);
    } 
    else if (c == ')') 
    {
      while (intStack.top() != -2) 
      {
        ss << ops[intStack.top()] << ' ';
        intStack.pop();
      }
      intStack.pop();
    } 
    else 
    {
      ss << token << ' ';
    }
  }
  while (!intStack.empty()) 
  {
    ss << ops[intStack.top()] << ' ';
    intStack.pop();
  }
  return ss.str();
}

// ******************************************************************************************************************
// * Name: EvaluatePostfix                                                                                          *                                                 
// * Description: Takes a postfix expression and performs the operations required to evaluate                       *    
// * Reference: cplusplus.com                                                                                       *            
// * Author: Samuel Lamb                                                                                            *                          
// ******************************************************************************************************************
void EvaluatePostfix(vector<string> &str)
{
  Stack <string> eval;
  eval.clear();
  bool error = false;
  for (auto i = 0; i < int(str.size()); ++ i)
  {
    // cout << str[i] << endl;
    if (IsOperand(str[i]))
    {
      if(IsNumeric(str[i]))
      {
        eval.push(str[i]);
      }
      else
      {
        cout << "Cannot evaluate, the answer is the postfix\n";
        error = true;
        break;
      }
    }
    if (IsOperator(str[i]))
    {
      if (str.size() < 3)
      {
        cout << "You entered too few operands\n";
        error = true;
        break;
      }
      string op1 = eval.top();
      eval.pop();
      string op2 = eval.top();
      eval.pop();
      float val_1 = stof(op1.c_str());
      float val_2 = stof(op2.c_str());
      float val_3 = Operation(str[i],val_1,val_2);
      eval.push(to_string(val_3));
    }
  }
  if (eval.size() > 1)
  {
    cout << "Error, too few operators\n";
    error = true;
  }
  else if (eval.size() == 0)
  {
    eval.push("0");
  }
  if (error == false)
  {
    cout << "Evaluation: ";
    printf("%g", stof(eval.top())); 
    cout << endl;
  }
}