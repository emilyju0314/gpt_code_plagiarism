#include<iostream>
#include<cstdio>
using namespace std;


int solve(int a,int b,int n){
  int ans=0;
  a%=b;
  a*=10;
  for(int i=0;i<n;i++){
    ans+=a/b;
    a%=b;
    a*=10;
  }
  return ans;
}

int main(){
  int a,b,c;
  while(cin>>a>>b>>c){
    cout<<solve(a,b,c)<<endl;
  }
}