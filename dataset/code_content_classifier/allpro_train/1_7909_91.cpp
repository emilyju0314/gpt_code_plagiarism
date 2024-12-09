#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void upmax(T& a, T b) {
  if (a < b) a = b;
}
template <class T>
inline void upmin(T& a, T b) {
  if (a > b) a = b;
}
const int maxn = 1007;
const int maxm = 200007;
const int mod = 1000000007;
const int inf = 0x7fffffff;
typedef int arr[maxn];
typedef int adj[maxm];
inline int add(int a, int b) { return ((long long)a + b) % mod; }
inline int mul(int a, int b) { return ((long long)a * b) % mod; }
inline int dec(int a, int b) { return add(a, mod - b % mod); }
inline int Pow(int a, int b) {
  int t = 1;
  while (b) {
    if (b & 1) t = mul(t, a);
    a = mul(a, a), b >>= 1;
  }
  return t;
}
template <typename Type>
inline Type RD() {
  char c = getchar();
  Type x = 0, flag = 1;
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    flag = -1;
  else
    x = c - '0';
  while (isdigit(c = getchar())) x = x * 10 + c - '0';
  return x * flag;
}
inline char rdch() {
  char c = getchar();
  while (!isalpha(c)) c = getchar();
  return c;
}
int n, m, a[maxn], k[maxn], tot;
long double f[maxn][maxn];
pair<int, int> obj[maxn];
void input() {
  n = RD<int>(), m = RD<int>();
  for (int i = 1, _ = m; i <= _; i++) {
    k[i] = RD<int>();
    for (int j = 1, _ = k[i]; j <= _; j++)
      obj[++tot] = pair<int, int>(RD<int>(), i);
  }
  sort(obj + 1, obj + tot + 1, greater<pair<int, int> >());
}
void solve() {
  int ed = n, st = n;
  while (st > 1 && obj[st - 1].first == obj[n].first) st--;
  while (ed < tot && obj[ed + 1].first == obj[n].first) ed++;
  int need = n - st + 1;
  long double p_tot = 1;
  for (int i = 1, _ = st - 1; i <= _; i++) {
    int t = obj[i].second;
    p_tot *= (a[t] + 1.0) / (k[t] - a[t]);
    a[t]++;
  }
  static long double k[maxn], a[maxn], val[maxn];
  for (int ii = st, _ = ed; ii <= _; ii++) {
    int i = ii - st + 1;
    k[i] = ::k[obj[ii].second], a[i] = ::a[obj[ii].second],
    val[i] = (a[i] + 1) / (k[i] - a[i]);
  }
  f[0][0] = p_tot;
  int len = ed - st + 1;
  for (int i = 1, _ = len; i <= _; i++)
    for (int j = 0, _ = i; j <= _; j++) {
      if (j) f[i][j] = f[i - 1][j - 1] * val[i] * j / i;
      f[i][j] += f[i - 1][j] * (i - j) / i;
    }
  printf("%.10lf\n", (double)f[len][need]);
}
int main() {
  input();
  solve();
  return 0;
}
