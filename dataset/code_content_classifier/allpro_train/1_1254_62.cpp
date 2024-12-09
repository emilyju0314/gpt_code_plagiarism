#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:666000000")
using namespace std;
const int inf = (1 << 30) - 1;
const long double eps = 1e-9;
const long double pi = fabs(atan2(0.0, -1.0));
void ML(const bool v) {
  if (v) return;
  int *ass;
  for (;;) {
    ass = new int[2500000];
    for (int i = 0; i < 2500000; i++) ass[i] = rand();
    cerr << ass[rand() % 2500000];
  }
}
void TL(const bool v) {
  if (v) return;
  int *ass;
  ass = new int[250];
  for (;;) {
    for (int i = 0; i < 250; i++) ass[i] = rand();
  }
}
void PE(const bool v) {
  if (v) return;
  puts("ass 1 2 3 4 5 6 fuck");
  exit(0);
}
vector<vector<int> > g;
int aps[100500];
int n;
void LoAd() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &aps[i]);
  g.resize(n + 1);
  for (int f, t, i = 1; i < n; i++) {
    scanf("%d%d", &f, &t);
    g[f].push_back(t);
    g[t].push_back(f);
  }
}
long long gcd(long long a, long long b) {
  while (0 != b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long lcm(long long a, long long b) {
  long long res = a / gcd(a, b) * b;
  ML(res >= 0);
  return min(100000000LL, res);
}
long long d[100500];
int sum[100500];
void dfs1(const int v, const int p) {
  if (1 == g[v].size() && v != 1) {
    sum[v] = aps[v];
    d[v] = 1;
    return;
  }
  for (auto it = g[v].begin(); it != g[v].end(); it++)
    if (*it != p) {
      dfs1(*it, v);
    }
  d[v] = 1;
  for (auto it = g[v].begin(); it != g[v].end(); it++)
    if (*it != p) {
      d[v] = lcm(d[v], d[*it]);
      sum[v] += sum[*it];
    }
  d[v] *= (g[v].size() - (1 == v ? 0 : 1));
}
long long cnt[100500];
long long res = 0;
void dfs2(const int v, const int p) {
  if (1 == g[v].size() && v != 1) {
    cnt[v] = sum[v];
    return;
  }
  for (auto it = g[v].begin(); it != g[v].end(); it++)
    if (*it != p) dfs2(*it, v);
  long long m = LLONG_MAX;
  int k = 0;
  long long tsum = 0;
  for (auto it = g[v].begin(); it != g[v].end(); it++)
    if (*it != p) {
      m = min(m, cnt[*it]);
      k++;
      tsum += cnt[*it];
    }
  long long t = d[v] / k;
  long long x = m / t * t;
  res += tsum - x * k;
  cnt[v] = x * k;
}
void SoLvE() {
  dfs1(1, -1);
  dfs2(1, -1);
  cout << res;
}
int main() {
  srand((int)time(NULL));
  LoAd();
  SoLvE();
  return 0;
}
