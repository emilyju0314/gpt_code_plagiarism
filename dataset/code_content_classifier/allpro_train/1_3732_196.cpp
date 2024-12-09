#include <bits/stdc++.h>
using namespace std;
const int Max = 2e6 + 10;
const int Mod = 1e9 + 7;
const long long int Inf = 1LL << 62;
char ty[Max];
int x[Max];
int y[Max];
int main() {
  int n;
  scanf("%d", &n);
  int y1 = 0, x1 = 0;
  for (int i = 1; i <= n; i++) {
    getchar();
    scanf("%c %d %d", &ty[i], &x[i], &y[i]);
    if (x[i] < y[i]) swap(x[i], y[i]);
    if (ty[i] == '+') {
      x1 = max(x1, x[i]);
      y1 = max(y1, y[i]);
    } else {
      if (x[i] >= x1 && y[i] >= y1) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
  }
  return 0;
}
