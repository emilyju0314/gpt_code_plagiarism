#include<iostream>
using namespace std;
int main(void){
  int W,H,x,y,r;
  cin>>W>>H>>x>>y>>r;
  if(x-r>=0&&x+r<=W&&y-r>=0&&y+r<=H)cout<<"Yes\n";
  else cout<<"No\n";
  return 0;
}

