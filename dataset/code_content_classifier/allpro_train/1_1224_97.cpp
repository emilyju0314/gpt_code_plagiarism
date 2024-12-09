#include <bits/stdc++.h>
using namespace std;
using INT = long long;
using pii = pair<int, int>;
int flag[2001000], p[2001000], vst[2001000], ct[2001000], Vst[2001000],
    ctt[2001000];
const int mod = 1e9 + 7;
int power(int a, int n, int ans = 1) {
  for (; n; n >>= 1, a = (INT)a * a % mod)
    if (n & 1) ans = (INT)ans * a % mod;
  return ans;
}
void pre() {
  for (int i = 2; i < 2001000; i++) {
    if (flag[i]) continue;
    flag[i] = i;
    for (INT j = (INT)i * i; j < 2001000; j += i) {
      flag[j] = i;
    }
  }
}
bool cmp(int u, int v) { return u > v; }
void oper(int u) {
  while (u > 1) {
    int v = flag[u];
    int c = 0;
    while (u % v == 0) u /= v, c++;
    if (c == vst[v])
      ctt[v]++;
    else if (c > vst[v])
      vst[v] = c, ctt[v] = 1;
  }
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  pre();
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i];
  sort(p + 1, p + n + 1, cmp);
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    if (vst[p[i]])
      oper(p[i] - 1);
    else
      oper(p[i]);
  }
  for (int i = 1; i <= 2000000; i++) {
    if (vst[i]) {
      ans = (INT)ans * power(i, vst[i]) % mod;
    }
  }
  int Flag = 0;
  for (int i = 1; i <= n; i++) {
    int u = p[i];
    if (Vst[u]) u--;
    Vst[u] = 1;
    Flag = 1;
    while (u > 1) {
      int v = flag[u];
      int c = 0;
      while (u % v == 0) c++, u /= v;
      if (c == vst[v] and ctt[v] == 1) Flag = 0;
    }
    if (Flag) break;
  }
  cout << (ans + Flag) % mod << endl;
  return 0;
}
