#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
const int mo = 1e9;
long long ksm(long long a, long long b) {
  if (b < 0) return 0;
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % 1000000007;
    a = a * a % 1000000007;
    b >>= 1;
  }
  return ans;
}
int t, n, a;
int cnt[27][maxn];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (register int i = 0; i <= 26; i++) {
      cnt[i][0] = 0;
    }
    for (register int i = 1; i <= n; i++) {
      scanf("%d", &a);
      cnt[a][0]++;
      cnt[a][cnt[a][0]] = i;
    }
    int maxx = 0;
    for (register int i = 1; i <= 26; i++) {
      maxx = max(cnt[i][0], maxx);
    }
    for (register int i = 1; i <= 26; i++) {
      for (register int j = 1; j <= 26; j++) {
        if (j == i || cnt[i][0] == 0 || cnt[j][0] == 0) {
          continue;
        }
        int ans = 0;
        for (register int ii = 1; ii <= cnt[i][0] / 2; ii++) {
          ans = ii * 2;
          int l = cnt[i][ii], r = cnt[i][cnt[i][0] - ii + 1], l1 = 0, r1 = 0;
          for (register int jj = 1; jj <= cnt[j][0]; jj++) {
            if (l < cnt[j][jj]) {
              l1 = jj;
              break;
            }
          }
          for (register int jj = cnt[j][0]; jj >= 1; jj--) {
            if (r > cnt[j][jj]) {
              r1 = jj;
              break;
            }
          }
          if (l1 == 0 || r1 == 0 || r1 < l1) {
            continue;
          }
          ans += r1 - l1 + 1;
          maxx = max(ans, maxx);
        }
      }
    }
    printf("%d\n", maxx);
  }
  return 0;
}
