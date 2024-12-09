#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int pre[maxn], sz[maxn], rk[maxn];
vector<long long> v;
map<int, int> mp;
int find(int x) { return pre[x] == x ? x : pre[x] = find(pre[x]); }
void unit(int x, int y) {
  int a = find(x);
  int b = find(y);
  if (a != b) {
    if (rk[a] < rk[b])
      pre[a] = b, sz[b] += sz[a];
    else {
      pre[b] = a, sz[a] += sz[b];
      if (rk[a] == rk[b]) ++rk[a];
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) pre[i] = i, sz[i] = 1;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    unit(i, x);
  }
  for (int i = 1; i <= n; ++i) {
    int x = find(i);
    if (!mp[x]) {
      mp[x] = 1;
      v.emplace_back(sz[x]);
    }
  }
  sort(v.begin(), v.end());
  if (v.size() >= 2) {
    v[v.size() - 2] += v[v.size() - 1];
    v[v.size() - 1] = 0;
  }
  long long ans = 0;
  for (int i = 0; i < v.size(); ++i) ans += v[i] * v[i];
  printf("%lld\n", ans);
  return 0;
}
