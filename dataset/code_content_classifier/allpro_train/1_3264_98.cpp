#include<iostream>
using namespace std ;
int main()
{
  int W,S;
  cin>>S>>W;
  if(W>=S)
  {
    cout<<"unsafe";
  }
  else cout<<"safe";
}