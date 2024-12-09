#include <bits/stdc++.h>
using namespace std;
int main(){
  int b,r,g,c,s,t;
  while(cin>>b>>r>>g>>c>>s>>t,t){
    int a=100,d;
    t-=s+b*5+r*3;
    a+=(b+r)*15+c*2+(b*5+r*3)*13+g*7;
    cout<<a-t*3<<endl;
  }
}