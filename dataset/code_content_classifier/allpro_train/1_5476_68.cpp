#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-7;
const int N = 1e6 + 10;
long long mod = 1e9 + 7;
const long long MOD = 998244353;
inline long long read() {
  long long f = 1, x = 0;
  char ch = getchar();
  for (; ch > '9' || ch < '0'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch <= '9' && ch >= '0'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
struct node {
  long long from, to, cost;
  bool operator<(const node &a) const { return cost > a.cost; }
} edge[N];
vector<node> G[N];
int n, cnt, ans, x;
int a[N], b[N];
void solve() {
  n = read(), x = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) b[i] = read(), b[i] = x - b[i];
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);
  int flag = 1;
  for (int i = 1; i <= n; i++)
    if (a[i] > b[i]) flag = 0;
  if (flag)
    printf("YES\n");
  else
    printf("NO\n");
}
int main() {
  int t = read();
  while (t--) solve();
}
