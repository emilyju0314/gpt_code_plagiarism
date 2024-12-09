#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

int main()
{
  string str;

  while(!cin.eof()){
    getline(cin, str);
    if(str == ".") break;
    bool f = true;
    stack<char> stk;
    for(int i = 0; i < str.size(); i++){
      if(str[i] == '(' || str[i] == '[') stk.push(str[i]);
      else if(str[i] == ']'){
	if(stk.empty()){
	  f = false;
	  break;
	} else if(stk.top() == '[') stk.pop();
	else break;
      } else if(str[i] == ')'){
	if(stk.empty()){
	  f = false;
	  break;
	} else if(stk.top() == '(') stk.pop();
	else break;
      }
    }

    cout << ((stk.empty() && f)? "yes" : "no") << endl;
  }

  return 0;
}