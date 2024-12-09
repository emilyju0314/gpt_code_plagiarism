#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll H,N,A,B; cin>>H>>N;
  vector<ll> Z(H+1,1e8+1);
  while(N!=0){
    N--;
    cin>>A>>B;
    for(int i=1; i<=H; i++){
      if(i<=A) Z[i]=min(Z[i],B);
      else Z[i]=min(Z[i],Z[i-A]+B);
    }
  }
  cout<<Z[H]<<endl;
}