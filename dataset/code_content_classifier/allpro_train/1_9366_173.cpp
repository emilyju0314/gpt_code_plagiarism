#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
const long long max_n = 1e5 + 2;
long long n;
long long in[max_n], out[max_n];
long long res = 0;
vector<long long> gr[max_n];
void upd(long long v) {
  for (long long i : gr[v]) {
    gr[i].emplace_back(v);
    res -= in[i] * out[i];
    in[i]++;
    out[i]--;
    res += in[i] * out[i];
  }
  gr[v].clear();
  res -= in[v] * out[v];
  out[v] += in[v];
  in[v] = 0;
}
void solve() {
  long long m;
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long v1, v2;
    cin >> v1 >> v2;
    v1--;
    v2--;
    if (v1 < v2) swap(v1, v2);
    gr[v2].emplace_back(v1);
    in[v2]++;
    out[v1]++;
  }
  for (long long i = 0; i < n; i++) res += in[i] * out[i];
  cout << res << endl;
  long long q;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    long long v;
    cin >> v;
    upd(v - 1);
    cout << res << endl;
  }
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  solve();
}
