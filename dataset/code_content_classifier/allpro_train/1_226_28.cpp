#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(int n,vector<pair<int,ll>> a) {
  sort(a.begin(),a.end());
  ll sol=0;
  priority_queue<ll> pq;
  for (auto &it : a) {
    int i=it.first;
    ll x=it.second;
    if ((int) pq.size()<i) {
      pq.push(-x);
      sol+=x;
    } else {
      ll y=-pq.top();
      if (x>y) {
        pq.pop();
        pq.push(-x);
        sol+=x-y;
      }
    }
  }
  return sol;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    int n;
    cin>>n;
    vector<pair<int,ll>> a,b;
    ll sol=0;
    for (int i=1;i<=n;i++) {
      int k,l,r;
      cin>>k>>l>>r;
      if (l>=r) {
        sol+=r;
        a.push_back({k,l-r});
      } else {
        sol+=l;
        if (k!=n) {
          b.push_back({n-k,r-l});
        }
      }
    }
    sol+=solve(n,a);
    sol+=solve(n,b);
    cout<<sol<<"\n";
  }
  return 0;
}
