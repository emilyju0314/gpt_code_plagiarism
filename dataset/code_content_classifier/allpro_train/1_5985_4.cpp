#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  int f = 0;
  x = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  if (f) x = -x;
}
const int N = 513;
int x[N], y[N], K, n, m, ans;
long long a[N][N], b[N][N];
int main() {
  read(K), n = 1 << K;
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (n); j++) read(a[i][j]);
  read(m);
  for (int i = (1); i <= (m); i++) read(x[i]), read(y[i]);
  for (int k = 0; k < (K); k++) {
    swap(a, b), memset(a, 0, sizeof a);
    for (int c = (1); c <= (m); c++)
      for (int i = 0; i < (n); i++)
        for (int j = 0; j < (n); j++)
          a[(i + x[c]) & (n - 1)][(j + y[c]) & (n - 1)] ^= b[i][j];
    for (int c = (1); c <= (m); c++)
      x[c] = (x[c] << 1) & (n - 1), y[c] = (y[c] << 1) & (n - 1);
  }
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (n); j++) ans += (a[i][j] > 0);
  cout << ans << endl;
  return 0;
}
