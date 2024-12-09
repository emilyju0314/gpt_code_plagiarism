#include<iostream>
using namespace std;

int main()
{
  int w;
  int s;
  cin>>w;
  while(w!=-1){
    s=1150;
    if(w>30)
      s=s+10*125+10*140+(w-30)*160;
    else if(w>20)
      s=s+10*125+(w-20)*140;
    else if(w>10)
      s=s+(w-10)*125;
    s=4280-s;
    cout<<s<<'\n';
    cin>>w;
  }
  return(0);
}

