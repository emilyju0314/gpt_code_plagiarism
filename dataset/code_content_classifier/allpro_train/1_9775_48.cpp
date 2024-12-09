#include<bits/stdc++.h>
using namespace std;
typedef long long int l;
int main(){
  string s;cin>>s;
  l a=0,k=1<<(s.size()-1),t=k;
  for(l i=s.size()-1;i>=0;i--) a+=(s[i]-'0')*k,k=k*5+t/2;
  cout<<a<<endl;
}