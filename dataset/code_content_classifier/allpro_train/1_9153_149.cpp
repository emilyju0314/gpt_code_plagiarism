#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n,k;
  cin >> n >> k;
  vector<int> v(n);
  rep(i,n) cin >> v[i];
  k=min(k,200);
  rep(i,k){
    vector<int> vec(n+1,0);
    rep(i,n){
      int x=v[i];
      int y=max(0,i-x);
      int z=min(n,i+x+1);
      vec[y]++; vec[z]--;
    }
    int now=0;
    rep(i,n){
      now+=vec[i];
      v[i]=now;
    }
  }
  rep(i,n) cout << v[i] << endl;
}