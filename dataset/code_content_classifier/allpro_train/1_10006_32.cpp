#include <bits/stdc++.h>
using namespace std;
const int MAXN = 101;
long long f[MAXN][6];
void init() {
  memset(f, 0, sizeof f);
  for (int i = 0; i < MAXN; i++) {
    f[i][0] = 1;
    for (int j = 1; j <= min(i, 5); j++)
      f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
  }
}
int main() {
  init();
  int n;
  while (~scanf("%d", &n)) {
    cout << f[n][5] * f[n][5] * 120 << endl;
  }
  return 0;
}
