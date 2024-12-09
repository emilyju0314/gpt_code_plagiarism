#include <bits/stdc++.h>
using namespace std;
int n, q;
int num[50];
int str[] = {1,         2,        4,        8,         16,        32,
             64,        128,      256,      512,       1024,      2048,
             4096,      8192,     16384,    32768,     65536,     131072,
             262144,    524288,   1048576,  2097152,   4194304,   8388608,
             16777216,  33554432, 67108864, 134217728, 268435456, 536870912,
             1073741824};
map<int, int> S;
int sum[50];
int ans = 0;
int cnt = 0;
void doit(int t) {
  memset(num, 0, sizeof(num));
  cnt = 0;
  while (t > 0) {
    num[cnt] = t % 2;
    t /= 2;
    cnt++;
  }
}
void solveit() {
  ans = 0;
  int now = 1;
  for (int i = cnt - 1; i >= 0; i--) {
    if (num[i] > 0) {
      if (sum[i] >= num[i]) {
        ans += num[i];
      } else {
        if (i == 0) {
          ans = -1;
          break;
        } else {
          num[i] -= sum[i];
          ans += sum[i];
          num[i - 1] += (num[i] * 2);
        }
      }
    }
  }
}
int main() {
  memset(sum, 0, sizeof(sum));
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    S[t]++;
  }
  for (int i = 0; i < 31; i++) {
    sum[i] = S[str[i]];
  }
  for (int i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    doit(t);
    solveit();
    printf("%d\n", ans);
  }
  return 0;
}
