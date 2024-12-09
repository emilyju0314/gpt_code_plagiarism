#include <bits/stdc++.h>
using namespace std;
inline int add(int a, int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
  return a;
}
inline int mul(int a, int b) { return (a * 1ll * b) % 1000000007; }
inline int power(int a, int b) {
  int rt = 1;
  while (b > 0) {
    if (b & 1) rt = mul(rt, a);
    a = mul(a, a);
    b >>= 1;
  }
  return rt;
}
void solve() {
  map<int, int> mp;
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; ++i) {
    cin >> a[i];
    mp[a[i]] = 1;
  }
  set<int> s;
  for (long long int i = 0; i < n; ++i) {
    for (long long int j = 0; j < n; ++j) {
      if (i != j) {
        s.insert(a[i] ^ a[j]);
      }
    }
  }
  for (auto i : s) {
    bool d = true;
    for (long long int j = 0; j < n; ++j) {
      if (mp[a[j] ^ i]) {
      } else {
        d = false;
        break;
      }
    }
    if (d) {
      cout << i << "\n";
      return;
    }
  }
  cout << "-1\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
