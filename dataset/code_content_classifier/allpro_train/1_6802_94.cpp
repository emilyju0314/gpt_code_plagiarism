#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
template <typename T>
inline void read(T &x) {
  register char ch;
  x = 0;
  for (; !isdigit(ch = getchar());)
    ;
  for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch - '0');
}
bitset<N + N> a[N];
int n, m;
inline void Inverse() {
  for (int i = 1; i <= n; i++) {
    if (!a[i][i])
      for (int j = i + 1; j <= n; j++)
        if (a[j][i]) {
          swap(a[i], a[j]);
          break;
        }
    for (int j = 1; j <= n; j++)
      if (j != i && a[j][i]) a[j] ^= a[i];
  }
}
int x[500005], y[500005];
int main() {
  read(n);
  read(m);
  for (int i = 1; i <= m; i++) {
    read(x[i]);
    read(y[i]);
    a[x[i]][y[i]] = 1;
  }
  for (int i = 1; i <= n; i++) a[i][i + n] = 1;
  Inverse();
  for (int i = 1; i <= m; i++) puts(a[y[i]][n + x[i]] ? "NO" : "YES");
  return 0;
}
