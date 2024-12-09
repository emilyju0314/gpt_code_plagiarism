#include <bits/stdc++.h>
using namespace std;
struct obj {
  long long ind;
  long long x;
};
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, k;
  cin >> n >> k;
  vector<obj> a(n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i].x;
    a[i].ind = i;
  }
  vector<vector<long long>> indxx(n);
  for (long long i = 0; i < n; ++i) {
    indxx[a[i].x].push_back(a[i].ind);
  }
  if (indxx[0].size() > 1) {
    cout << "-1";
    return 0;
  }
  long long el = 0;
  for (long long i = 1; i < n; ++i) {
    if (indxx[i].size() > (indxx[i - 1].size() * (k - el))) {
      cout << "-1";
      return 0;
    }
    el = 1;
  }
  vector<vector<long long>> adj(n);
  long long p = 0, c = 1, pi = 0, ci = 0, e = 0;
  el = 0;
  while (e < n - 1) {
    long long cnt = 0;
    while ((e < n - 1) && (cnt < (k - el)) && (ci < indxx[c].size())) {
      adj[indxx[p][pi]].push_back(indxx[c][ci]);
      ++e;
      ++ci;
      ++cnt;
    }
    if (ci < indxx[c].size()) {
      ++pi;
      continue;
    } else {
      ++p, pi = 0, ++c, ci = 0;
    }
    el = 1;
  }
  cout << n - 1 << "\n";
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < adj[i].size(); ++j) {
      cout << i + 1 << " " << adj[i][j] + 1 << "\n";
    }
  }
  return 0;
}
