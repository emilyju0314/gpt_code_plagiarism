#include <iostream>
using namespace std;

 
int main () 
{
  int i,a,r,t;
 while(cin>>a,a>0)
 {
  for(i=0;i<9;i++)
  {
   cin>>r;
   a=a-r;
  }
  cout<<a<<'\n';
  if(a==0)
     break;
}
   
  return 0;
}
 