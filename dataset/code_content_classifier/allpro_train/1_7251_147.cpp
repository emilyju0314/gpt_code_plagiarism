#include<bits/stdc++.h>
using namespace std;

int main(){
  int i,j,N,M,k,p,ans=0;
  cin>>N>>M;
  vector<int> v(M,0);
  for(i=0;i<N;i++){
    cin>>k;
    for(j=0;j<k;j++){
      cin>>p;
      v[p-1]++;
    }
  }
  for(i=0;i<M;i++){
    if(v[i]==N)ans++;
  }
  cout << ans << endl;
}