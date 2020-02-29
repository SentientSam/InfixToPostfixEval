#include "vector"
#include "sstream"
#include "iostream"
#include "stack.h"
#include "cctype"
using namespace std;
using namespace cop4530;
bool IsValidParen(string str);
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
int main(void)
{
  string string1 = "2.5";
  float answer = stof(string1);
  cout << answer << endl;
  cout << answer * 2 << endl;
  float lol = 4.00 / 10.00;
  cout << lol << endl;
  // string STLinput;
  // do{
    
	// 	cout << "Enter string (Enter \"exit\" to quit program): ";
	// 	getline(cin, STLinput);
  //   if (IsValidParen(STLinput))
  //   {
  //     cout << "Working\n";
  //   }
  //   else if (!IsValidParen(STLinput))
  //   {
  //     cout << "Rip\n";
  //   }
	// }while(STLinput != "exit");
	// return 0;
}