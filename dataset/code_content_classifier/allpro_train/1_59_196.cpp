#include<bits/stdc++.h>
using namespace std;

int a,b;
int kq;

int main(){
  cin>>a>>b;
  if (a>9 || b>9) kq=-1;
  else kq=a*b;
  cout<<kq;
}
