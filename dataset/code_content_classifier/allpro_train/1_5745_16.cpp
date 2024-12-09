#include <bits/stdc++.h>
using namespace std;
const int MOD = 10;
const double eps = 1e-5;
const int maxN = 1e6 + 10;
const int maxM = 1;
const int inf = 1e9;
int n, m, t;
int B[maxN], p[32];
inline void init() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    for (int j = 0; j <= 30; j++)
      if ((t >> j) & 1) p[j]++;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", B + i);
  }
  sort(B, B + m);
}
inline void solve() {
  int ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = B[i]; j <= 30; j++) {
      if (p[j]) {
        p[j]--;
        for (int k = B[i]; k < j; k++) p[k]++;
        ans++;
        break;
      }
    }
  }
  printf("%d\n", ans);
}
int main() {
  init();
  solve();
  return 0;
}
