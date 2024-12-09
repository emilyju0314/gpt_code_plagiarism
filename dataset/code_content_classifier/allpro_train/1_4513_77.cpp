#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  bool b = 0;
  char c;
  while (!isdigit(c = getchar()) && c != '-')
    ;
  if (c == '-') c = getchar(), b = 1;
  x = c - 48;
  while (isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - 48;
  if (b) x = -x;
}
template <typename T>
inline void wrip(T x) {
  if (x > 9) wrip(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
inline void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  wrip(x);
  putchar(' ');
}
template <typename T>
inline void writeln(T x) {
  if (x < 0) putchar('-'), x = -x;
  wrip(x);
  putchar('\n');
}
inline char readch() {
  char c;
  do c = getchar();
  while (c == '\n' || c == ' ');
  return c;
}
inline void reads(string &s) {
  char c;
  while ((c = getchar()) == ' ' || c == '\n')
    ;
  s = c;
  while ((c = getchar()) != ' ' && c != '\n') s += c;
}
inline void getlines(string &s) {
  char c;
  while ((c = getchar()) == '\n')
    ;
  s = c;
  while ((c = getchar()) != '\n') s += c;
}
const long double pi = acos(-1);
const int inf = 1e9;
const int mod = 1e9 + 7, N = 15e5;
int n, m, check, num;
int adj[50][50], a[N], col[N];
long long res, ans, cnt[N];
vector<pair<int, int> > lst;
void Init() {
  m = 0;
  for (int i = 1; i <= n; i++)
    if (cnt[i])
      a[i] = ++m;
    else
      res *= 2;
  for (int i = 1; i <= n; i++) cnt[i] = 0;
  n = m;
  for (auto p : lst)
    adj[a[p.first]][a[p.second]] = 1, adj[a[p.second]][a[p.first]] = 1;
}
void Dfs(int u) {
  for (int v = 1; v <= n; v++)
    if (adj[u][v]) {
      if (!col[v]) {
        col[v] = 3 - col[u];
        Dfs(v);
      }
      if (col[u] == col[v]) check = 0;
    }
}
void Try(int x) {
  if (x > m) {
    int mask = 0;
    for (int i = 1; i <= m; i++)
      if (!a[i])
        for (int j = m + 1; j <= n; j++)
          if (adj[i][j]) mask |= 1 << j - m - 1;
    cnt[mask]++;
    return;
  }
  a[x] = 1;
  Try(x + 1);
  for (int i = 1; i < x; i++)
    if (adj[x][i] && !a[i]) return;
  a[x] = 0;
  Try(x + 1);
}
void TRY(int x) {
  if (x > n) {
    int mask = 0;
    for (int i = m + 1; i <= n; i++)
      if (a[i]) mask |= 1 << i - m - 1;
    ans -= 2 * cnt[mask];
    return;
  }
  a[x] = 1;
  TRY(x + 1);
  for (int i = m + 1; i < x; i++)
    if (adj[x][i] && !a[i]) return;
  a[x] = 0;
  TRY(x + 1);
}
int main() {
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    lst.push_back(pair<int, int>(u, v));
    cnt[u]++, cnt[v]++;
  }
  check = res = 1;
  Init();
  if (n == 0) return cout << 0, 0;
  for (int i = 1; i <= n; i++)
    if (!col[i]) {
      num++;
      col[i] = 1;
      Dfs(i);
    }
  ans = (1LL << n) - (1LL << num) + (1LL << num) * check + 2;
  for (int i = 1; i <= n; i++) a[i] = 0;
  m = n / 2;
  Try(1);
  int Nmask = 1 << n - m;
  for (int j = 0; j < n - m; j++)
    for (int i = 0; i < Nmask; i++)
      if ((i >> j & 1)) cnt[i] += cnt[i ^ (1 << j)];
  TRY(m + 1);
  cout << res * ans;
}
