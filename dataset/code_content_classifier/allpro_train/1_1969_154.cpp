#include<bits/stdc++.h>
using namespace std;


int main(){
  int x,i,m,n;
  m=0;
  cin >> x;
  n=x/100;
  if(n*5+n*100<x){
    m=0;
  }else{
    m=1;
  }
  cout << m << endl;
  return 0;

}
