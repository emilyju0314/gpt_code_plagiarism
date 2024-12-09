#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int K = 55;
int n, k;
int t[N];
double d[K][N];
double sum[N];
double rev[N];
double pref[N];
double add[N];
struct convex_hull_trick {
  int len;
  int uk;
  double k[N], b[N];
  convex_hull_trick() {
    uk = 1;
    len = 0;
  }
  void clear() {
    len = 0;
    uk = 1;
  }
  void add(double add, double coeff) {
    while (len >= 2 && (b[len] - b[len - 1]) * (k[len - 1] - coeff) <
                           (add - b[len - 1]) * (k[len - 1] - k[len]))
      --len;
    k[++len] = coeff;
    b[len] = add;
  }
  double get(double coeff) {
    uk = min(uk, len);
    while (uk + 1 <= len &&
           -coeff * k[uk] + b[uk] >= -coeff * k[uk + 1] + b[uk + 1])
      ++uk;
    return -coeff * k[uk] + b[uk];
  }
} l;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &t[i]);
    sum[i] = sum[i - 1] + double(t[i]);
    rev[i] = rev[i - 1] + (1 / double(t[i]));
    pref[i] = pref[i - 1] + sum[i] / t[i];
    add[i] = -pref[i] + sum[i] * rev[i];
  }
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= k; ++j) d[j][i] = 1000000000000000000ll;
  d[0][0] = 0;
  for (int lvl = 1; lvl <= k; ++lvl) {
    l.clear();
    for (int i = lvl; i <= n; ++i) {
      l.add(d[lvl - 1][i - 1] + add[i - 1], sum[i - 1]);
      d[lvl][i] = pref[i] + l.get(rev[i]);
    }
  }
  printf("%.4f\n", (double)d[k][n]);
  return 0;
}
