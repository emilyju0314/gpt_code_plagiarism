#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,c = "Yes";
  cin >> s;
  for(int i=0;i<s.size();i++){
    if(i%2==0&&s.at(i)=='L')
      c = "No";
    if(i%2==1&&s.at(i)=='R')
      c = "No";
  }
  cout << c << endl;
}