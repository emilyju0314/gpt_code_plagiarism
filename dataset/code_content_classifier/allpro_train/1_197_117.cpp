#include <bits/stdc++.h>
using namespace std;
int T[50], J, m, n, i, j, k, l, r, K, K0, x, y, first, second, xx, yy;
int D[4001][4001];
long long A = 0;
int main() {
  cin >> n >> x >> y;
  m = (x > y ? x : y);
  D[0][0] = 1;
  for (i = 1; i <= m; i++)
    for (j = i; j <= m; j++)
      D[i][j] = (D[i][j - 1] + D[i - 1][j - 1]) % 1000000009ll;
  for (i = 2; i < n; i++)
    for (j = i; j < n; j++)
      A = (A + (long long)D[j - i + 1][y] * D[n - j + i - 1][x]) % 1000000009ll;
  for (i = 1; i <= x; i++) A = (A * i) % 1000000009ll;
  for (i = 1; i <= y; i++) A = (A * i) % 1000000009ll;
  cout << A << endl;
  return 0;
}
