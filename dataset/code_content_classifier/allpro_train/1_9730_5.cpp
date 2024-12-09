#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200;
int n;
int a[MAXN][MAXN];
bool f[MAXN][MAXN];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  for (int i = 1; i <= n; i++) f[i][i] = true;
  for (int i = 1; i <= n; i++) f[i][n - i + 1] = true;
  for (int i = 1; i <= n; i++) {
    f[i][n / 2 + 1] = true;
    f[n / 2 + 1][i] = true;
  }
  int s = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (f[i][j]) s += a[i][j];
  cout << s << endl;
}
