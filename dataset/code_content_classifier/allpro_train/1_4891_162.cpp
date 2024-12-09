#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 7;
const int MAXN = (int)5e3 + 7;
int n;
int c[MAXN][MAXN];
int a[MAXN];
int second[MAXN];
int main() {
  c[0][0] = 1;
  for (int i = 1; i <= 4000; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % INF;
  }
  cin >> n;
  a[1] = 1;
  second[1] = 1;
  a[2] = 3;
  second[2] = 4;
  a[3] = 10;
  second[3] = 14;
  for (int i = 4; i <= n; i++) {
    for (int j = 2; j < i; j++) {
      int sum = second[j - 1];
      a[i] += 1ll * sum * c[i][j] % INF;
      a[i] %= INF;
    }
    for (int j = 0; j < i; j++) a[i] += c[i][j], a[i] %= INF;
    second[i] = second[i - 1] + a[i];
    second[i] %= INF;
  }
  cout << a[n];
  return 0;
}
