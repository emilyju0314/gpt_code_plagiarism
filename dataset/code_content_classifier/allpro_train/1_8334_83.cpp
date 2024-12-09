#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1, c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f == 1 ? x : -x;
}
const int mod = 1e9 + 7;
inline int fix(int x) { return x + ((x >> 31) & mod); }
inline int add(int x, int y) { return fix(x + y - mod); }
inline int dec(int x, int y) { return fix(x - y); }
inline int mul(int x, int y) { return (long long)x * y % mod; }
inline void ADD(int &x, int y) { x = fix(x + y - mod); }
inline void DEC(int &x, int y) { x = fix(x - y); }
inline void MUL(int &x, int y) { x = (long long)x * y % mod; }
inline int ksm(int x, int r) {
  int ret = 1;
  for (int i = 0; (1ll << i) <= r; i++) {
    if ((r >> i) & 1) MUL(ret, x);
    MUL(x, x);
  }
  return ret;
}
inline int inv(int x) { return ksm(x, mod - 2); }
const int N = 1e6 + 4;
int n, m, top, ans, a[N], b[N], st[N], dfn[N], f[N], g[N];
char s[N];
struct node {
  int tl, tr, wl, wr;
};
vector<node> vec[N];
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++)
    if (s[i] == '1') a[++m] = i;
  if (!m) {
    cout << n << "\n";
    return (0 - 0);
  }
  for (int i = m; i > 1; i--) {
    b[i] = a[i] - a[i - 1] - 1;
    while (top && b[i] >= b[st[top]]) {
      vec[st[top]].push_back((node){i, dfn[st[top]], 0, b[st[top]]});
      if (top > 1) {
        vec[st[top - 1]].push_back(
            (node){i, dfn[st[top - 1]], b[st[top]] + 1, b[st[top - 1]]});
        dfn[st[top - 1]] = i - 1;
      }
      top--;
    }
    if (top) {
      vec[st[top]].push_back((node){i, dfn[st[top]], 0, b[st[top]]});
      dfn[st[top]] = i - 1;
    }
    st[++top] = i;
    dfn[i] = i - 1;
  }
  for (int i = top, las = 0; i; i--) {
    vec[st[i]].push_back((node){1, dfn[st[i]], las, b[st[i]]});
    las = b[st[i]] + 1;
  }
  f[1] = g[1] = 1;
  for (int i = 2; i <= m; i++) {
    for (auto v : vec[i]) {
      ADD(f[i], mul(dec(g[v.tr], g[v.tl - 1]), v.wr - v.wl + 1));
    }
    g[i] = add(g[i - 1], f[i]);
  }
  ans = mul(g[m], mul(a[1], n - a[m] + 1));
  cout << ans << "\n";
  return (0 - 0);
}
