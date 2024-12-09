#include <bits/stdc++.h>
using namespace std;
long long q;
unordered_map<long long, long long> mp;
long long price(long long a, long long b) {
  if (a == b) return 0;
  if (a > b) swap(a, b);
  return price(a, b / 2) + mp[b];
}
void upd(long long v, long long u, long long w) {
  if (u == v) return;
  if (v > u) swap(u, v);
  mp[u] += w;
  upd(v, u / 2, w);
}
int32_t main() {
  cin >> q;
  while (q--) {
    long long op;
    cin >> op;
    if (op == 1) {
      long long v, u, w;
      cin >> v >> u >> w;
      upd(v, u, w);
    } else {
      long long v, u;
      cin >> v >> u;
      cout << price(u, v) << endl;
    }
  }
}
