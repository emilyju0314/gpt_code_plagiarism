#include <bits/stdc++.h>
using namespace std;
inline int gcd(int a, int b) {
  while (1) {
    a = a % b;
    if (a == 0) return b;
    b = b % a;
    if (b == 0) return a;
  }
}
const int maxN = 1000;
const int inf = 1e9;
int n;
int s[2], c[2], a, b, d;
inline void init() {
  s[0] = s[1] = c[0] = c[1] = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &a, &b, &d);
    a = (a + 1) % 2;
    s[a] += b;
    c[a] += 10;
  }
}
inline void solve() {
  for (int i = 0; i < 2; i++) {
    if (s[i] >= ceil((double)c[i] / 2))
      printf("LIVE\n");
    else
      printf("DEAD\n");
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  init();
  solve();
  return 0;
}
