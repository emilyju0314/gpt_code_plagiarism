#include <bits/stdc++.h>
using namespace std;
const int maxn = 1234;
int ai[maxn];
int n, A, B, C, T;
void init() {
  for (int i = 1; i <= n; i++) scanf("%d", &ai[i]);
}
long long ans;
void play() {
  ans = 0;
  for (int i = 1; i <= n; i++) {
    int MAX = 0;
    for (int j = ai[i]; j <= T; j++) {
      int jiange = j - ai[i];
      int rc = jiange * C;
      int de = A - B * jiange;
      MAX = max(MAX, de + rc);
    }
    ans += MAX;
  }
}
void pri() { printf("%lld\n", ans); }
int main() {
  while (scanf("%d%d%d%d%d", &n, &A, &B, &C, &T) != EOF) {
    init();
    play();
    pri();
  }
  return 0;
}
