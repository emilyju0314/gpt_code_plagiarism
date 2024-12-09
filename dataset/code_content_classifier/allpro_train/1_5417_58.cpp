#include <bits/stdc++.h>
using namespace std;
const int maxi = 1e6 + 10;
int n;
long long m;
vector<pair<int, int>> v[maxi];
int ob[maxi];
long long ans = 0;
int sz[maxi];
long long inv[maxi];
map<pair<int, int>, int> mp;
long long nor[maxi];
long long step(long long x, long long y, long long mo) {
  if (!y) return 1;
  long long p = step(x, y / 2, mo);
  if (y & 1) return p * p % mo * x % mo;
  return p * p % mo;
}
int phi(int x) {
  int ans = x;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) {
      ans -= ans / i;
      while (x % i == 0) x /= i;
    }
  if (x > 1) ans -= ans / x;
  return ans;
}
void dfs1(int x, int pred) {
  sz[x] = 1;
  for (auto i : v[x])
    if (i.first != pred && !ob[i.first]) {
      dfs1(i.first, x);
      sz[x] += sz[i.first];
    }
}
int find_centroid(int x, int pred, int total) {
  int mm = 0;
  int child = 0;
  for (auto i : v[x])
    if (i.first != pred && !ob[i.first]) {
      if (mm < sz[i.first]) {
        mm = sz[i.first];
        child = i.first;
      }
    }
  if (mm > total / 2) return find_centroid(child, x, total);
  return x;
}
void dfs2(int x, int pred, int parent, long long cur, int lev) {
  mp[{cur, parent}]++;
  mp[{cur, 0}]++;
  for (auto i : v[x])
    if (i.first != pred && !ob[i.first])
      dfs2(i.first, x, parent, (cur + i.second * nor[lev + 1]) % m, lev + 1);
}
void dfs3(int x, int pred, int parent, long long cur, int lev) {
  long long value = (m - cur) * inv[lev] % m;
  if (mp.count({value, 0})) ans += mp[{value, 0}] - mp[{value, parent}];
  for (auto i : v[x])
    if (i.first != pred && !ob[i.first])
      dfs3(i.first, x, parent, (cur * 10 + i.second) % m, lev + 1);
}
void decompose(int x) {
  mp.clear();
  dfs1(x, 0);
  mp[{0, 0}] = 1;
  int y = find_centroid(x, 0, sz[x]);
  for (auto i : v[y])
    if (!ob[i.first]) dfs2(i.first, y, i.first, i.second % m, 0);
  for (auto i : v[y])
    if (!ob[i.first]) dfs3(i.first, y, i.first, i.second % m, 1);
  ob[y] = 1;
  ans += mp[{0, 0}] - 1;
  for (auto i : v[y])
    if (!ob[i.first]) decompose(i.first);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    x++;
    y++;
    v[x].push_back({y, z});
    v[y].push_back({x, z});
  }
  long long cur = 1;
  long long phim = phi(m);
  for (int i = 0; i <= n; i++) {
    nor[i] = cur;
    inv[i] = step(cur, phim - 1, m);
    cur = cur * 10 % m;
  }
  decompose(1);
  cout << ans << endl;
}
