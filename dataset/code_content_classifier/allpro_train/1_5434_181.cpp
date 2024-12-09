#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n,k[100005];
  bool ev=true;
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>k[i];
    if(k[i]%2==1){ev=false;}
  }
  if(ev){cout<<"second"<<endl;}
  else{cout<<"first"<<endl;}
}