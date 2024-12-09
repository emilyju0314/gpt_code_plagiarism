#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e6 + 10;
const long long inf = 1e9;
long long a[MAX], tree[MAX];
pair<long long, long long> ran[MAX];
map<long long, long long> cc;
long long ans[MAX], mod = 1e9 + 7, n;
vector<long long> ini[MAX];
void add(long long x, long long v) {
  while (x <= n) {
    (tree[x] += v) %= mod;
    x = x | (x + 1);
  }
}
long long accum(long long l) {
  long long ret = 0;
  while (l >= 0) {
    (ret += tree[l]) %= mod;
    l = (l & (l + 1)) - 1;
  }
  return ret;
}
long long query(long long l, long long r) {
  return (accum(r) - accum(l - 1) + mod) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long k, m, l, r, cont = 0;
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    cin >> ran[i].first >> ran[i].second;
    cc[ran[i].first], cc[ran[i].second];
  }
  cc[0];
  cc[n];
  for (auto it : cc) cc[it.first] = cont++;
  for (long long i = 0; i < m; i++)
    ran[i].first = cc[ran[i].first], ran[i].second = cc[ran[i].second];
  n = cc[n];
  for (long long i = 0; i < m; i++) {
    ini[ran[i].second].push_back(ran[i].first);
  }
  add(0, 1);
  for (long long i = 1; i < n + 1; i++) {
    for (long long x = 0; x < ini[i].size(); x++) {
      add(i, query(ini[i][x], i - 1) % mod);
    }
  }
  cout << query(n, n) << endl;
}
