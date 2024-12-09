#include <bits/stdc++.h>
using namespace std;
int n, x, y;
long long ans;
int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return x;
}
struct xx {
  int l, r;
} a[100010];
bool cmp(xx a, xx b) { return a.l < b.l; }
multiset<int> s;
multiset<int>::iterator it;
int main() {
  n = read();
  x = read();
  y = read();
  for (int i = 1; i <= n; i++) {
    a[i].l = read();
    a[i].r = read();
  }
  sort(a + 1, a + n + 1, cmp);
  s.insert(-999999);
  for (int i = 1; i <= n; i++) {
    it = s.upper_bound(a[i].l);
    it--;
    if (*it == -999999) {
      ans += (x + (long long)y * (a[i].r - a[i].l));
      s.insert(a[i].r + 1);
    } else {
      int g = *it;
      if (x > (long long)(a[i].l - g + 1) * y) {
        s.erase(it);
        s.insert(a[i].r + 1);
        ans +=
            (long long)(a[i].l - g + 1) * y + (long long)(a[i].r - a[i].l) * y;
      } else {
        s.insert(a[i].r + 1);
        ans += x + (long long)(a[i].r - a[i].l) * y;
      }
    }
    ans %= 1000000007;
  }
  cout << ans;
  return 0;
}
