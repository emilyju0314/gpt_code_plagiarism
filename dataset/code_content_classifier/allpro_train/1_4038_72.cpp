#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long MOD = 1000000007;
inline long long read() {
  char ch = getchar();
  long long x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long i, j, k, l, n, m, maxx, minn, ans, x, y, flag, cc, a[5011], sum, i1,
    jj, k1;
int main() {
  cin >> n;
  for (int i = (1); i < (n + 1); i++) {
    a[i] = read();
    a[i] += a[i - 1];
  }
  for (int i = (1); i < (n + 1); i++) {
    long long sum1 = -100000000, sum2 = -100000000, p, p2;
    for (int j = (0); j < (i + 1); j++)
      if (2 * a[j] - a[i] > sum1) {
        p = j;
        sum1 = 2 * a[j] - a[i];
      }
    for (int k = (i); k < (n + 1); k++)
      if (2 * a[k] - a[i] - a[n] > sum2) {
        p2 = k;
        sum2 = 2 * a[k] - a[i] - a[n];
      }
    if (sum1 + sum2 > sum) {
      sum = sum1 + sum2;
      i1 = p;
      jj = i;
      k1 = p2;
    }
  }
  cout << i1 << " " << jj << " " << k1 << endl;
  return 0;
}
