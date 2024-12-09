#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_NM = 1000;
int n, m, q;
char mat[1 + MAX_NM + 1][1 + MAX_NM + 1];
int sum[1 + MAX_NM + 1][1 + MAX_NM + 1];
long long query(long long x, long long y) {
  if (x == 0 || y == 0) {
    return 0;
  }
  int xParity = x / n % 2;
  int yParity = y / m % 2;
  int xyParity = __builtin_popcount((x / n) ^ (y / m)) % 2;
  long long oldX = x;
  long long oldY = y;
  x = x % n;
  y = y % m;
  long long answer = 0;
  long long all = 0;
  if (xParity && yParity) {
    answer += sum[n][m];
    answer += x * m - sum[x][m];
    answer += n * y - sum[n][y];
    answer += sum[x][y];
    all = (n + x) * (m + y);
  } else if (xParity) {
    answer += n * y - sum[n][y];
    answer += sum[x][y];
    all = (n + x) * y;
  } else if (yParity) {
    answer += x * m - sum[x][m];
    answer += sum[x][y];
    all = x * (m + y);
  } else {
    answer += sum[x][y];
    all = x * y;
  }
  if (xyParity) {
    answer = all - answer;
  }
  answer += (oldX * oldY - all) / 2;
  return answer;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%s", &mat[i][1]);
    for (int j = 1; j <= m; j++) {
      mat[i][j] -= '0';
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i][j];
    }
  }
  for (int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1--;
    y1--;
    long long answer =
        +query(x2, y2) - query(x2, y1) - query(x1, y2) + query(x1, y1);
    printf("%lld\n", answer);
  }
  return 0;
}
