#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
template <typename T>
inline void read(T &x) {
  x = 0;
  char ch = getchar();
  bool f = false;
  while (!isdigit(ch)) {
    if (ch == '-') {
      f = true;
    }
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  x = f ? -x : x;
  return;
}
template <typename T>
inline void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 ^ 48);
  return;
}
map<int, int> m[N];
int n, z, cnt, p[N], f[N], s[N];
int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    int v, c, l, r;
    read(v), read(c), read(l), read(r);
    if (r + c < N && (!l || m[l].find(r + c) != m[l].end())) {
      int u = m[l][r + c];
      f[i] = f[u] + v, p[i] = u;
      if (!r && f[i] > f[z]) z = i;
      if (f[i] > f[m[l + c][r]]) m[l + c][r] = i;
    }
  }
  while (z) s[cnt++] = z, z = p[z];
  write(cnt), putchar('\n');
  for (; cnt--;) write(s[cnt]), putchar('\n');
  return 0;
}
