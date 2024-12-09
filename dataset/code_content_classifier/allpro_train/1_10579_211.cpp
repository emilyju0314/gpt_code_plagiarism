#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 10;
int a[maxn];
int used[maxn];
int ans[maxn];
int main() {
  int tip = 1;
  int cnt = 0;
  a[cnt++] = 1;
  while (tip < 1e4) {
    tip *= 3;
    a[cnt++] = tip;
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    for (int i = 0; i < cnt; i++) used[i] = 0;
    int n;
    scanf("%d", &n);
    int n1 = n;
    for (int i = cnt - 1; i >= 0; i--) {
      if (a[i] <= n) {
        n -= a[i];
        used[i] = 1;
      }
      if (n == 0) {
        break;
      }
    }
    if (n == 0)
      cout << n1 << endl;
    else {
      while (1) {
        n = n1 + 1;
        n1++;
        for (int i = cnt - 1; i >= 0; i--) {
          if (a[i] <= n) {
            n -= a[i];
            used[i] = 1;
          }
          if (n == 0) break;
        }
        if (n == 0) {
          cout << n1 << endl;
          break;
        }
      }
    }
  }
  return 0;
}
