#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 15, M = 26;
long long mod[2] = {(long long)1e9 + 7, (long long)1e9 + 9}, inv[2];
long long sum[N][2][M];
long long mypow(long long x, long long cc, long long m) {
  long long ret = 1;
  while (cc) {
    if (cc & 1) {
      ret = (ret * x) % m;
    }
    cc >>= 1;
    x = (x * x) % m;
  }
  return ret;
}
void add(long long &r, long long b, long long m) { r = ((r + b) + m) % m; }
void cal(const string &s, long long m, int bit) {
  int n = s.size(), i, j;
  long long cur = 1;
  for (i = 1; i <= n; ++i) {
    for (j = 0; j < M; ++j) sum[i][bit][j] = sum[i - 1][bit][j];
    int u = s[i - 1] - 'a';
    add(sum[i][bit][u], cur, m);
    cur = (cur * 2) % m;
  }
}
int occupy[M], match[M];
void solve() {
  int n, m;
  cin >> n >> m;
  string s, tt;
  cin >> s >> tt;
  cal(s, mod[0], 0);
  cal(s, mod[1], 1);
  inv[0] = mypow(2, mod[0] - 2, mod[0]);
  inv[1] = mypow(2, mod[1] - 2, mod[1]);
  int i, j, u;
  pair<pair<long long, long long>, int> v[M], t[M];
  memset(v, 0, sizeof(v));
  long long c[2] = {1, 1};
  for (i = 0; i < M; ++i) v[i].second = i;
  for (i = 0; i < m; ++i) {
    u = tt[i] - 'a';
    v[u].first.first = (v[u].first.first + c[0]) % mod[0];
    v[u].first.second = (v[u].first.second + c[1]) % mod[1];
    c[0] = (c[0] * 2) % mod[0];
    c[1] = (c[1] * 2) % mod[1];
  }
  sort(v, v + M);
  reverse(v, v + M);
  int r, x, y;
  c[0] = 1, c[1] = 1;
  vector<int> ret;
  for (i = 1; i + m - 1 <= n; ++i) {
    r = i + m - 1;
    for (j = 0; j < M; ++j) {
      t[j].first.first =
          ((sum[r][0][j] - sum[i - 1][0][j] + mod[0]) * c[0]) % mod[0],
      t[j].first.second =
          ((sum[r][1][j] - sum[i - 1][1][j] + mod[1]) * c[1]) % mod[1];
      t[j].second = j;
    }
    c[0] = (c[0] * inv[0]) % mod[0];
    c[1] = (c[1] * inv[1]) % mod[1];
    sort(t, t + M);
    bool is = 1;
    reverse(t, t + M);
    for (j = 0; j < M; ++j)
      if (t[j].first != v[j].first) {
        is = 0;
        break;
      }
    memset(match, -1, sizeof(match));
    if (is) {
      for (j = 0; j < M; ++j) {
        if (t[j].first == make_pair(0LL, 0LL)) break;
        x = t[j].second, y = v[j].second;
        if ((match[x] == -1 && match[y] == -1)) match[x] = y, match[y] = x;
        if (match[x] != y || match[y] != x) {
          is = 0;
          break;
        }
      }
    }
    if (is) ret.push_back(i);
  }
  cout << ret.size() << endl;
  for (i = 0; i < (int)ret.size(); ++i) printf("%d ", ret[i]);
  cout << endl;
}
int main() { solve(); }
