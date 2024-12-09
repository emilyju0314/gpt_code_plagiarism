#include <bits/stdc++.h>
#pragma optimize("O3")
using namespace std;
const long long MOD = 1e9 + 9;
const long long INF = 1e9 + 7;
const int base = 2e5 + 1;
const long long MAX = 1e15 + 1;
const double EPS = 1e-9;
const double PI = acos(-1.);
const int MAXN = 2 * 1e5 + 47;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
pair<long long, long long> t[MAXN];
map<int, int> ind, vx;
void add(int x, long long val) {
  for (int j = x; j < MAXN; j = j | (j + 1)) {
    t[j].first += val;
    t[j].second++;
  }
}
long long get(int x) {
  long long res = 0;
  for (int j = x; j >= 0; j = (j & (j + 1)) - 1) {
    res += t[j].first;
  }
  return res;
}
long long cnt(int x) {
  long long res = 0;
  for (int j = x; j >= 0; j = (j & (j + 1)) - 1) {
    res += t[j].second;
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  vector<long long> x(n), v(n);
  for (long long i = (0); i < (n); ++i) scanf("%lld", &x[i]);
  for (long long i = (0); i < (n); ++i) {
    scanf("%lld", &v[i]);
    vx[x[i]] = v[i];
  }
  sort(v.begin(), v.end());
  sort(x.begin(), x.end());
  long long res = 0;
  for (long long i = (0); i < (n); ++i) ind[v[i]] = i;
  for (long long i = (0); i < (n); ++i) {
    int cur = ind[vx[x[i]]];
    res += x[i] * cnt(cur) - get(cur);
    add(cur, x[i]);
  }
  cout << res;
  return 0;
}
