#include <bits/stdc++.h>
using namespace std;

int main(){
  
  string s;
  cin >>s;
  int ca=0,cb=0;
  for(int i=0; i<s.size(); i++){
  	if(s[i]=='0') ca++;
    else cb++;
  }
  
  cout << min(ca,cb)*2 << endl;
  
}