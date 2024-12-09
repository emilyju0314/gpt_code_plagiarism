#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], b[N], c[N], cnt[35];
bool solve(int n) {
  memset(cnt, 0, sizeof cnt);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
    sum += b[i];
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", c + i);
    sum += c[i];
  }
  if (sum % (2 * n)) return false;
  sum /= (2 * n);
  for (int i = 0; i < n; i++) {
    a[i] = b[i] + c[i] - sum;
    if (a[i] % n || a[i] < 0) return false;
    a[i] /= n;
    for (int j = 0; j < 32; j++) {
      cnt[j] += a[i] >> j & 1;
    }
  }
  for (int i = 0; i < n; i++) {
    long long sum1 = 0, sum2 = 0;
    for (int j = 0; j < 32; j++) {
      sum1 += (1LL << j) * ((a[i] >> j & 1) ? cnt[j] : 0);
      sum2 += (1LL << j) * ((a[i] >> j & 1) ? n : cnt[j]);
    }
    if (b[i] != sum1 || c[i] != sum2) return false;
  }
  return true;
}
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    if (solve(n)) {
      for (int i = 0; i < n; i++) {
        printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
      }
    } else {
      puts("-1");
    }
  }
  return 0;
}
