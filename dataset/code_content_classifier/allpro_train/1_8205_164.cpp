#include<iostream>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  if(a<6)b=0;
  else if(a<13)b/=2;
  cout<<b<<endl;
}