#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  map<int,int> A,B;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    A[i+a]++;
    B[i-a]++;
  }
  int ans=0;
  for(pair<int,int> p:A)
    ans+=p.second*B[p.first];
  cout<<ans<<endl;
}