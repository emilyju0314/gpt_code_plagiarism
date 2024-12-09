#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
int n, q;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct seg {
  int l, r, tag;
  bool operator<(const seg &rhs) const { return r < rhs.r; }
} ask[maxn];
int c[maxn], p[maxn], a[maxn], b[maxn], num[maxn], just[maxn], ans[maxn];
void add(int x, int val) {
  while (x <= n) {
    c[x] ^= val;
    x += (x & (-x));
  }
}
int sum(int x) {
  int ans = 0;
  while (x > 0) {
    ans ^= c[x];
    x -= (x & (-x));
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    b[i] = a[i];
    num[i] = num[i - 1] ^ b[i];
  }
  scanf("%d", &q);
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= q; i++) {
    ask[i].l = read();
    ask[i].r = read();
    ask[i].tag = i;
  }
  sort(ask + 1, ask + q + 1);
  int cnt = 1;
  for (int i = 1; i <= n; i++) {
    int now = lower_bound(b + 1, b + n + 1, a[i]) - b - 1;
    if (just[now] != 0) {
      add(just[now], a[i]);
      just[now] = i;
      add(i, a[i]);
    } else {
      just[now] = i;
      add(i, a[i]);
    }
    while (ask[cnt].r == i && cnt <= q) {
      ans[ask[cnt].tag] = sum(ask[cnt].r) ^ sum(ask[cnt].l - 1) ^
                          (num[ask[cnt].r] ^ num[ask[cnt].l - 1]);
      cnt++;
    }
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
