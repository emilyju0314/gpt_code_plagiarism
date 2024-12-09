#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
const long long MOD = 1e9 + 7;
const long long N = 2e5 + 10;
const long long INF = 1e9 + 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<long long> v(n);
  set<int> s;
  set<int> tree;
  map<int, int> dist;
  queue<long long> q;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    dist[v[i]] = 0;
    s.insert(v[i]);
    tree.insert(v[i]);
    q.push(v[i]);
  }
  long long ans = 0;
  while (not q.empty()) {
    if (m <= 0) break;
    long long f = q.front();
    q.pop();
    if (s.find(f - 1) == s.end() && m > 0) {
      dist[f - 1] = dist[f] + 1;
      ans += dist[f - 1];
      s.insert(f - 1);
      q.push(f - 1);
      m--;
    }
    if (s.find(f + 1) == s.end() && m > 0) {
      dist[f + 1] = dist[f] + 1;
      ans += dist[f + 1];
      s.insert(f + 1);
      q.push(f + 1);
      m--;
    }
  }
  cout << ans << endl;
  for (long long c : s) {
    if (tree.find(c) == tree.end()) {
      cout << c << ' ';
    }
  }
  return 0;
}
