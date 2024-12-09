#include <bits/stdc++.h>
using namespace std;
const int N = 200000, M = 200;
bitset<N> fc[M], b;
int n, num[N], T, bel[N];
long long a[N], c[N];
void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d", &a[i]);
    long long tmp = a[i];
    for (int j = 1; tmp; ++j, tmp >>= 1)
      if (tmp & 1) ++num[j];
  }
  c[1] = 1;
  for (int i = 2; i <= 60; ++i) c[i] = c[i - 1] << 1;
}
inline void set_fc(int x) {
  b[0] = 1;
  for (int i = 1; i <= n; ++i) a[i] & c[x] ? b[i] = 1 : b[i] = 0;
}
inline void check_fc() {
  for (int i = 1, j = 1, k = 1; i <= T && j <= n; ++i) {
    while (!b[k] && k <= n) ++k;
    if (k > n) return;
    while (!fc[i][j] && j <= n) ++j;
    if (j == k) b ^= fc[i];
  }
  if (b[0] && b.count() == 1 || (!b.count())) return;
  int k = 1;
  while (!b[k] && k <= n) ++k;
  for (int i = 1, j = 1; i <= T && j <= n; ++i) {
    while (!fc[i][j] && j <= n) ++j;
    if (j > k) {
      for (int _i = ++T; _i >= i + 1; --_i) fc[_i] = fc[_i - 1];
      fc[i] = b;
      return;
    }
  }
  fc[++T] = b;
}
void print() {
  memset(bel, 255, sizeof bel);
  for (int i = T; i; --i) {
    for (int j = n; j; --j)
      if (bel[j] != -1 && fc[i][j]) {
        if (bel[j] == 1) fc[i][0] = !fc[i][0];
        fc[i][j] = 0;
      }
    if (fc[i][0])
      for (int j = n; j; --j)
        if (fc[i][j]) {
          fc[i][0] = !fc[i][0];
          bel[j] = 1;
          fc[i][j] = 0;
          break;
        }
    for (int j = n; j; --j)
      if (fc[i][j]) bel[j] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (bel[i] == -1) bel[i] = 0;
    printf("%d ", bel[i] + 1);
  }
}
void solve() {
  for (int i = 60; i; --i)
    if (num[i] && (num[i] & 1) == 0) set_fc(i), check_fc();
  for (int i = 60; i; --i)
    if (num[i] & 1) set_fc(i), check_fc();
}
int main() {
  init();
  solve();
  print();
  return 0;
}
