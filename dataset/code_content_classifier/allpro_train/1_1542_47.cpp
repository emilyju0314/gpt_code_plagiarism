#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,i,ans=0;
  cin>>N;
  vector<int> a(N);
  for(i=0;i<N;i++)cin>>a[i];
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  for(i=0;i<N;i++){
    if(i%2)ans-=a[i];
    else ans+=a[i];
  }
  cout <<ans <<endl;
}