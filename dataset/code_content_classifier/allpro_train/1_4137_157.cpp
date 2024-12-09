#include<iostream>
#include<string>
using namespace std;

int main()
{
  int a,b;
  string ans;
  cin>>a>>b;

  if(a+b==15) ans='+';
  else if(a*b==15) ans='*';
  else ans='x';

  cout<<ans<<endl;
}