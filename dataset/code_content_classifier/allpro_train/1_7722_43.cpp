#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
long long d, N;
int main() {
  int T;
  bool able;
  while (~scanf("%d", &T)) {
    while (T--) {
      scanf("%lld%lld", &N, &d);
      able = false;
      if (N >= d) {
        able = true;
      } else {
        for (int i = 1; i <= 1e5 && !able; i++) {
          if ((d + i) / (i + 1) <= N - i) {
            able = true;
          }
        }
      }
      printf("%s\n", able ? "YES" : "NO");
    }
  }
  return 0;
}
