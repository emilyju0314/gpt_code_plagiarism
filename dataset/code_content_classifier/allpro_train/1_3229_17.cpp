#include <bits/stdc++.h>
using namespace std;
const int Mx = 1e3 + 5;
const long long INF = 1LL << 62;
int n, m;
long long car[Mx][Mx], row[Mx] = {0}, col[Mx] = {0};
long long Min_x = INF, Min_y = INF, tmp;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> car[i][j];
      row[i] += car[i][j];
      col[j] += car[i][j];
    }
  int x, y;
  for (int i = 0; i <= n; i++) {
    int pos = i * 4;
    tmp = 0LL;
    for (int j = 2; j < 4 * n; j += 4)
      tmp += (pos - j) * (pos - j) * row[j / 4];
    if (Min_x > tmp) {
      x = i;
      Min_x = tmp;
    }
  }
  for (int i = 0; i <= m; i++) {
    int pos = i * 4;
    tmp = 0LL;
    for (int j = 2; j < 4 * m; j += 4)
      tmp += (pos - j) * (pos - j) * col[j / 4];
    if (Min_y > tmp) {
      y = i;
      Min_y = tmp;
    }
  }
  cout << Min_x + Min_y << endl;
  cout << x << " " << y << endl;
  return 0;
}
