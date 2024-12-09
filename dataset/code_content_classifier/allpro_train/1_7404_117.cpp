#include <bits/stdc++.h>
using namespace std;
int n, a[100005], v[100005], x;
char s[100005];
int main() {
  scanf("%d%s", &n, s);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  x = 0;
  v[0] = 1;
  while (x >= 0 && x < n) {
    if (s[x] == '<') {
      x -= a[x];
    } else {
      x += a[x];
    }
    if (x < 0 || x >= n) {
      puts("FINITE");
      break;
    }
    if (v[x]) {
      puts("INFINITE");
      break;
    }
    v[x] = 1;
  }
  return 0;
}
