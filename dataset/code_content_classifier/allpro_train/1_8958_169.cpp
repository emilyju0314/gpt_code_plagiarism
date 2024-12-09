#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return x * f;
}
int n, p, q, c[200005], a[200005], b[200005], last;
void change(int x, int k) {
  while (x <= n) {
    c[x] += k;
    x += x & -x;
  }
}
int query(int x) {
  int res = 0;
  while (x) {
    res += c[x];
    x -= x & -x;
  }
  return res;
}
bool vis[200005];
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    p = read();
    a[n - i] += (p - query(p + 1));
    change(p + 1, 1);
  }
  memset(c, 0, sizeof(c));
  for (int j = 1; j <= n; j++) {
    q = read();
    a[n - j] += (q - query(q + 1));
    change(q + 1, 1);
  }
  for (int i = 0; i < n; i++) {
    a[i] += last, last = 0;
    if (a[i] > i) a[i] -= (i + 1), last = 1;
  }
  memset(c, 0, sizeof(c));
  for (int i = n - 1; i >= 0; i--) {
    int l = 1, r = n, mid, x = a[i] + 1;
    while (l < r) {
      mid = (l + r) >> 1;
      if (x > mid - query(mid))
        l = mid + 1;
      else
        r = mid;
    }
    change(l, 1);
    printf("%d ", l - 1);
  }
  return 0;
}
