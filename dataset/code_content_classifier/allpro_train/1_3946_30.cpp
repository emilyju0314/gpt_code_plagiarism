#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  long long r, c, sum = 0;
  char a[105][105];
  cin >> r >> c;
  a[r - 1][0] = '.';
  for (int i = 0; i < r; i++)
    for (int j = 1; j <= c; j++) cin >> a[i][j];
  for (int i = 1; i <= c; i++) {
    if (a[r - 1][i - 1] == '.' && a[r - 1][i] == 'B') sum++;
  }
  cout << sum << endl;
  return 0;
}
