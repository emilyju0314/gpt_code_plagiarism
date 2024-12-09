#include <bits/stdc++.h>
using namespace std;

bool f[100000];
int add[100005];
signed main(){
 int q , l , r;
  for(int i=3;i<1000;i+=2){
    for(int j=i*i;j<100000;j+=i){
      f[j]=1;
    }
  }
  
  for(int i=4;i<=100000;i+=2){
    f[i]=1;
  }
  
  for(int i=3;i<=100000;i+=2){
    add[i]=add[i-1];
    if(f[i] == false && f[(i+1)/2] == false){
      add[i]+=1;
    }
    add[i+1]=add[i];
  }
  
  cin>>q;
      
  for(int i=0;i<q;i++){
    cin>>l>>r;
    cout<<add[r]-add[l-1]<<endl;
  }
  return(0);
}