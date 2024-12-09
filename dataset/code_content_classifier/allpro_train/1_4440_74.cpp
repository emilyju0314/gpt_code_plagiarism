#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
int n;
cin>>n;
int bo[n+1];
int bo1[n+1];
for(int i=1;i<=n;i++){
  bo[i]=0;
  bo1[i]=0;
}
if(n%2==1){
  int x=(n-1)/2;
for(int i=1;i<=n;i++){
  for(int j=i+1;j<=n;j++){
    if(bo[i]<x){
      cout<<1<<" ";
      bo[i]++;
    }else{
      cout<<-1<<" ";
      bo[j]++;
    }
  }
}

  }else{
    int x=(n-2)/2;
    for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
        if((i+1)==j and i%2==1){
          cout<<0<<" ";
        }else{
        if(bo[i]<x and bo1[j]<x){
          cout<<1<<" ";
          bo[i]++;
          bo1[j]++;
        }else{
          cout<<-1<<" ";
          bo1[i]++;
          bo[j]++;
        }
    }
  }

  }
  }
  cout<<endl;

}
}