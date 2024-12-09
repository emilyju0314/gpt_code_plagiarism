#include <bits/stdc++.h>
using namespace std;
int main(){
  int X;
  cin>>X;
  int ans=1;
for(int i=2;i<32;i++){
  int N=i*i;
  for(int j=2;j<10;j++){
    if(N<=X){
      ans=max(ans,N);
    }
    else break;
    N=N*i;
  }
}
  cout<<ans<<endl;
}