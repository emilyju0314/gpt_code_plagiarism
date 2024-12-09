#include <bits/stdc++.h>
using namespace std;
int n, x[1100], b[1100];
bool ok(int len) {
  for (int i = 1; i <= len; i++) b[i] = 100000;
  int now = 0;
  for (int i = n; i; i--) {
    now++;
    if (now > len) now = 1;
    if (!b[now]) return false;
    b[now] = min(b[now] - 1, x[i]);
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  sort(x + 1, x + n + 1);
  for (int i = 1; i <= n; i++)
    if (ok(i)) {
      printf("%d\n", i);
      break;
    }
}
