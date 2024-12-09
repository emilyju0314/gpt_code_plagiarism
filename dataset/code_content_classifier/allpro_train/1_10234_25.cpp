#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long T, n, m;
long long a[maxn], b[maxn];
long long kk[50];
long long gg[50];
int main() {
  kk[0] = 1;
  for (int i = 1; i <= 39; i++) {
    kk[i] = kk[i - 1] * (long long)3;
  }
  cin >> T;
  while (T--) {
    cin >> n;
    memset(gg, 0, sizeof(gg));
    int i = 0;
    while (n) {
      gg[i++] = n % 3;
      n /= 3;
    }
    long long ans = 0;
    for (int i = 50; i >= 0; i--) {
      if (gg[i] == 2) {
        for (int j = i + 1; j <= 50; j++) {
          if (gg[j] == 0) {
            ans += kk[j];
            break;
          } else
            ans -= kk[j];
        }
        break;
      }
      ans += gg[i] * kk[i];
    }
    cout << ans << endl;
  }
  return 0;
}
