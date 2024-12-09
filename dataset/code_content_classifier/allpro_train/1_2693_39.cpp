#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int main() {
  int n, b, a, s[N], ans = 0;
  scanf("%d %d %d", &n, &b, &a);
  for (int i = 0; i < n; i++) scanf("%d", &s[i]);
  int ini = a;
  for (int i = 0; i < n; i++) {
    if (s[i] == 1 && i == 0) {
      if (a) {
        a -= 1;
        ans++;
      }
    } else if (s[i] == 0) {
      if (a) {
        a -= 1;
        ans++;
      } else if (b) {
        b -= 1;
        ans++;
      }
    } else {
      if (b && a + 1 <= ini) {
        b -= 1;
        ans++;
        a += 1;
      } else if (a) {
        a -= 1;
        ans++;
      }
    }
  }
  printf("%d", ans);
  return 0;
}
