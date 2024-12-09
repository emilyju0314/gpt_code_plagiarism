#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0;
  int ch = getchar(), f = 1;
  while (!isdigit(ch) && (ch != '-') && (ch != EOF)) ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void rt(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10)
    rt(x / 10), putchar(x % 10 + '0');
  else
    putchar(x + '0');
}
const int maxn = 100005;
vector<int> a[maxn], dn[maxn];
int mx[maxn], n, m;
int main() {
  n = rd(), m = rd();
  for (int i = 1; i <= (int)n; i++)
    for (int j = 1; j <= (int)m; j++) a[i].push_back(rd());
  for (int i = 1; i <= (int)n; i++) dn[i].resize(m);
  for (int j = 0; j <= (int)m - 1; j++) {
    int nw = n;
    for (int i = n; i >= (int)1; i--) {
      if (i == n || a[i][j] > a[i + 1][j]) nw = i;
      dn[i][j] = nw;
    }
  }
  for (int i = 1; i <= (int)n; i++)
    for (int j = 0; j <= (int)m - 1; j++) mx[i] = max(mx[i], dn[i][j]);
  int q = rd();
  while (q--) {
    int l = rd(), r = rd();
    if (mx[l] >= r)
      puts("Yes");
    else
      puts("No");
  }
}
