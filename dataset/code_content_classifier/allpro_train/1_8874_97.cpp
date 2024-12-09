#include <bits/stdc++.h>
using namespace std;
void bad(string mes = "Impossible") {
  cout << mes;
  exit(0);
}
template <typename T>
string bin(T x, int st = 2) {
  string ans = "";
  while (x > 0) {
    ans += char('0' + x % st);
    x /= st;
  }
  reverse(ans.begin(), ans.end());
  return ans.empty() ? "0" : ans;
}
template <typename T>
T input() {
  T ans = 0, m = 1;
  char c = ' ';
  while (!((c >= '0' && c <= '9') || c == '-')) {
    c = getchar();
  }
  if (c == '-') m = -1, c = getchar();
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + (c - '0'), c = getchar();
  }
  return ans * m;
}
template <typename T>
void read(T& a) {
  a = input<T>();
}
template <typename T>
void read(T& a, T& b) {
  read(a), read(b);
}
template <typename T>
void read(T& a, T& b, T& c) {
  read(a, b), read(c);
}
template <typename T>
void read(T& a, T& b, T& c, T& d) {
  read(a, b), read(c, d);
}
void reads(string& second) {
  string ans = "";
  char c = '\n';
  while (c == '\n' || c == ' ') c = getchar();
  while (c != '\n' && c != ' ' && c) ans += c, c = getchar();
  second = ans;
}
const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 3e3 + 10, base = 1e9 + 7;
const long long llinf = 1e18 + 1;
template <typename T>
T binpow(T n, T second) {
  if (second <= 0) return 1LL;
  if (second % 2 == 0) {
    T b = binpow(n, second / 2);
    return (1LL * b * b) % base;
  } else {
    return (1LL * binpow(n, second - 1) * n) % base;
  }
}
vector<int> g[maxn];
int d[maxn][maxn], p[maxn][maxn];
set<pair<pair<int, int>, int> > bd;
pair<int, int> Q[maxn * maxn];
int saf, fsajsf;
inline void push(pair<int, int> x) { Q[fsajsf++] = x; }
inline pair<int, int> pop() { return Q[saf++]; }
inline bool empty() { return saf == fsajsf; }
int main() {
  int n, m, k;
  read(n, m, k);
  for (int i = 0; i < m; i++) {
    int first, t;
    read(first, t);
    g[first].push_back(t);
    g[t].push_back(first);
  }
  for (int i = 0; i < k; i++) {
    int first, t, second;
    read(first, t, second);
    bd.insert(make_pair(make_pair(first, t), second));
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) {
      d[i][j] = inf;
    }
  d[0][1] = 0;
  push(make_pair(0, 1));
  pair<int, int> tmp;
  while (!empty()) {
    tmp = pop();
    int a = tmp.first, b = tmp.second;
    for (int i = 0; i < g[b].size(); i++) {
      int to = g[b][i];
      if (!bd.count(make_pair(make_pair(a, b), to)) && d[b][to] > d[a][b] + 1) {
        d[b][to] = d[a][b] + 1;
        p[b][to] = a;
        push(make_pair(b, to));
      }
    }
  }
  int ans = inf;
  int b, c = n;
  for (int i = 0; i <= n; i++)
    if (d[i][n] < ans) {
      ans = d[i][n];
      b = i;
    }
  if (ans == inf) bad("-1");
  vector<int> res;
  res.push_back(n);
  while (b != 0) {
    res.push_back(b);
    int a = p[b][c];
    c = b;
    b = a;
  }
  printf("%d\n", ans);
  for (int i = res.size() - 1; i >= 0; i--) printf("%d ", res[i]);
  return 0;
}
