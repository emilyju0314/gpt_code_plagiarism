#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T sqr(const T& a) {
  return a * a;
}
template <class T>
inline void updMin(T& a, const T& b) {
  if (b < a) a = b;
}
template <class T>
inline void updMax(T& a, const T& b) {
  if (b > a) a = b;
}
const int maxm = 7000 + 100;
const int maxn = 7000 + 100;
int t[maxm];
int l[maxm];
int r[maxm];
int x[maxm];
int sz;
const int maxValue = 1000000;
int cntLeft[maxValue + 1][14], cntRight[maxValue + 1][14];
bool isDeg2[maxValue + 1];
set<int> s;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int k = 1;
  while (k <= maxValue) {
    isDeg2[k] = true;
    k <<= 1;
  }
  for (int i = 1; i <= maxValue; ++i) {
    cntLeft[i][0] = cntRight[i - 1][0] + 1;
    cntRight[i][0] = cntLeft[i][0];
    if (isDeg2[i]) ++cntRight[i][0];
  }
  int nn = 1;
  while (nn <= n) nn <<= 1;
  for (k = 1; k < 14; ++k) {
    for (int i = 1; i <= maxValue; ++i) {
      cntLeft[i][k] = cntLeft[cntLeft[i][k - 1]][k - 1];
      cntRight[i][k] = cntRight[cntRight[i][k - 1]][k - 1];
    }
  }
  for (int i = 0; i < m; ++i) {
    int tmp;
    scanf("%d", &tmp);
    if (tmp == 1) {
      scanf("%d%d%d%d", &t[sz], &l[sz], &r[sz], &x[sz]);
      ++sz;
    } else {
      int level, v;
      scanf("%d%d", &level, &v);
      s.clear();
      for (int j = 0; j < sz; ++j) {
        if (t[j] < level) continue;
        if (t[j] == level) {
          if (l[j] <= v && v <= r[j]) s.insert(x[j]);
          continue;
        }
        int d = t[j] - level;
        int left0 = v, right0 = v;
        int deg = 0;
        while (d) {
          if (deg >= 14) {
            cout << "WTF?\n";
            exit(0);
          }
          if (d & 1) {
            left0 = cntLeft[left0][deg];
            right0 = cntRight[right0][deg];
          }
          d >>= 1;
          ++deg;
        }
        if ((left0 >= l[j] && left0 <= r[j]) ||
            (right0 >= l[j] && right0 <= r[j]) ||
            (l[j] >= left0 && l[j] <= right0) ||
            (r[j] >= left0 && r[j] <= right0)) {
          s.insert(x[j]);
        }
      }
      int ans = s.size();
      printf("%d\n", ans);
    }
  }
  return 0;
}
