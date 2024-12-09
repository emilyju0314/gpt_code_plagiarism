#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,x=1,y=1; cin>>n;
  for(int i=0;i<n;i++){
    int a; cin>>a;
    x*=3;
    if(a%2==0){
      y*=2;
    }else{
      y*=1;
    }
  }
  cout<<x-y<<endl;
}