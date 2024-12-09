#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,sum=0;
  cin>>a>>b>>c;
  for(int i=a;i<=b;i++){
    if(c%i==0)sum++;
  }
  cout<<sum<<endl;
}