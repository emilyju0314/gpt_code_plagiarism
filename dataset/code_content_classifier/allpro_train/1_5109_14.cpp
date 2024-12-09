#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 1e5 + 10;
vector<int> v[N];
void init() {
  int tot = 0;
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      v[j].push_back(i);
    }
    tot = max(tot, (int)v[i].size());
  }
}
int C(int n, int m) {
  int U = 1, D = 1;
  while (m) {
    U *= n++;
    D *= m--;
  }
  return U / D;
}
void solve(int n) {
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      ret++;
    }
  }
  cout << n << ' ' << ret << endl;
}
int main() {
  map<tuple<int, int, int>, int> mp;
  for (int i = 1; i < 8; i++) {
    if (((i >> 0) & 1) == 0) continue;
    for (int j = 1; j < 8; j++) {
      if (((j >> 1) & 1) == 0) continue;
      for (int k = 1; k < 8; k++) {
        if (((k >> 2) & 1) == 0) continue;
        int a = i, b = j, c = k;
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);
        mp[{a, b, c}] = 1;
      }
    }
  }
  init();
  int ncase;
  scanf("%d", &ncase);
  while (ncase--) {
    map<int, int> mc;
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    vector<int> v1, v2;
    merge(v[a].begin(), v[a].end(), v[b].begin(), v[b].end(),
          back_inserter(v1));
    merge(v[c].begin(), v[c].end(), v1.begin(), v1.end(), back_inserter(v2));
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    int sz[8];
    memset((sz), (0), sizeof(sz));
    for (auto &x : v2) {
      int f = 0;
      if (a % x == 0) f |= 1;
      if (b % x == 0) f |= 2;
      if (c % x == 0) f |= 4;
      sz[f]++;
    }
    int ans = 0;
    for (auto &t : mp) {
      int a, b, c;
      tie(a, b, c) = t.first;
      if (a == c)
        ans += C(sz[a], 3);
      else if (a == b)
        ans += C(sz[a], 2) * sz[c];
      else if (b == c)
        ans += C(sz[b], 2) * sz[a];
      else
        ans += sz[a] * sz[b] * sz[c];
    }
    printf("%d\n", ans);
  }
  return 0;
}
