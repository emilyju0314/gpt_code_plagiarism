
#include<iostream>
#include<string>
using namespace std;
int main(){
  int f,i,m;
  string s;
  for(cin>>f;cin>>s;f?puts(f-2?"A":"B"):puts("NA")){
    f=0;
    for(i=1;s[0]+s[1]==101 & (m=s.find(35))!=string::npos & s[m-i]==s[m+i];)
      m-++i-1 | m+i-s.size()+1 | s[m+i]-'~'||(f=1);
    for(i=2;s[0]+s[1]==156 & s[i]==81 & s[i+1]==61;)
      ++++i-s.size()+2 | s[i]+s[i+1]-252 || (f=2);
  }
}