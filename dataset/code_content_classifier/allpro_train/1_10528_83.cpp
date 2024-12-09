#include <bits/stdc++.h>
const int N = 550;
using namespace std;
int n;
long long int a[N][N];
int x;
int y;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0) {
        x = i;
        y = j;
      }
    }
  }
  long long int need = 0;
  long long int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (x == i) continue;
    for (int j = 1; j <= n; j++) {
      need = need + a[i][j];
      sum = sum + a[x][j];
    }
    break;
  }
  a[x][y] = need - sum;
  if (a[x][y] <= 0) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    long long int s1 = 0;
    long long int s2 = 0;
    for (int j = 1; j <= n; j++) {
      s1 = s1 + a[i][j];
      s2 = s2 + a[j][i];
    }
    if (s1 != need || s2 != need) {
      cout << -1 << endl;
      return 0;
    }
  }
  long long int s1 = 0;
  long long int s2 = 0;
  for (int i = 1; i <= n; i++) {
    s1 += a[i][i];
    s2 += a[i][n - i + 1];
  }
  if (s1 != need || s2 != need) {
    cout << -1 << endl;
    return 0;
  }
  cout << a[x][y] << endl;
  return 0;
}
