#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,cnt=0;
  string s;
  cin>>n>>s;
  for(int i=0;i<s.size()-2;i++) {
    if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C') cnt++;
  }
  cout<<cnt<<endl;
}
