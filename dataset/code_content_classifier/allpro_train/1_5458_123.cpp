#include <bits/stdc++.h>
const int M = 400005;
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0, w = 1;
  while (c > '9' || c < '0') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * w;
}
int n, m;
struct Fly {
  int l, r;
} p[M];
int fir[M];
int Maxt;
int sum[M];
inline bool Cmp(Fly a, Fly b) { return a.l < b.l; }
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) p[i].l = read(), p[i].r = read();
  sort(p + 1, p + n + 1, Cmp);
  for (int i = 2; i <= n; i++) sum[i] = sum[i - 1] + p[i].l - p[i - 1].r;
  for (int i = 1; i <= n; i++) {
    int st = p[i].l;
    int l = i, r = n, Ans = i;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (sum[mid] - sum[i] < m)
        l = mid + 1, Ans = mid;
      else
        r = mid - 1;
    }
    int temp = abs(m - (sum[Ans] - sum[i]) + p[Ans].r);
    Maxt = max(Maxt, temp - p[i].l);
  }
  cout << Maxt << endl;
  return 0;
}
