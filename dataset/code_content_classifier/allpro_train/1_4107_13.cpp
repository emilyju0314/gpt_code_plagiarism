#include <bits/stdc++.h>
using namespace std;
char BUFFER[100000 + 5];
bool readn(int &n) { return scanf("%d", &n) == 1; }
bool readl(long long &n) { return scanf("%I64d", &n) == 1; }
bool readd(double &n) { return scanf("%lf", &n) == 1; }
bool reads(string &s) {
  s = "";
  int n = scanf("%s", BUFFER);
  if (n == 1) s = BUFFER;
  return n == 1;
}
bool readln(string &s) {
  char *valid = gets(BUFFER);
  if (valid) s = BUFFER;
  return ((bool)valid);
}
const int maxn = 105;
int A[maxn][maxn];
int main() {
  int i, j, m0, m1, n, m, k, ans = 1e9, val, a, b, s0, s1, mask;
  cin >> n >> m >> k;
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) cin >> A[i][j];
  if (m > k) {
    for (m0 = 0; m0 < m; ++m0) {
      val = 0;
      for (m1 = 0; m1 < m; ++m1)
        if (m0 != m1) {
          s0 = s1 = 0;
          for (i = 0; i < n; ++i)
            if (A[i][m0] == A[i][m1])
              s0++;
            else
              s1++;
          val += min(s0, s1);
        }
      ans = min(ans, val);
    }
  } else {
    for (mask = 0; mask < (1 << (m)); ++mask) {
      val = 0;
      for (i = 0; i < n; ++i) {
        m0 = m1 = s0 = s1 = 0;
        for (j = 0; j < m; ++j) {
          if ((((mask) & (1 << (j))) != 0)) {
            if (A[i][j] == 0)
              s0++;
            else
              s1++;
          } else {
            if (A[i][j] == 0)
              m0++;
            else
              m1++;
          }
        }
        val += min(m0 + s1, s0 + m1);
      }
      ans = min(ans, val);
    }
  }
  if (ans > k) ans = -1;
  cout << ans << endl;
  return 0;
}
