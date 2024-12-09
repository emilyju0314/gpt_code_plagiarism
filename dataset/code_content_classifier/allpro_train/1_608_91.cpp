#include <bits/stdc++.h>
using namespace std;
int a[1004], n, t[21][21];
int main() {
  int tmp;
  scanf("%d", &n);
  for (int i = 1; i <= n * n; i++) {
    scanf("%d", &tmp);
    a[tmp]++;
  }
  int one = 0, two = 0, odd;
  bool flag = false;
  int half = n / 2 + n % 2, pos = 1;
  int x = half, y = 1;
  for (int i = 1; i <= 1000; i++) {
    tmp = a[i] % 4;
    if (tmp == 3) {
      if (n % 2 == 0) {
        flag = true;
        break;
      } else {
        tmp = 1;
      }
    }
    if (tmp == 1) {
      if ((n % 2 && one >= 1) || (n % 2 == 0)) {
        flag = true;
        break;
      }
      one++;
      t[half][half] = i;
      a[i]--;
    }
    tmp = a[i] % 4;
    if (tmp == 2) {
      if ((n % 2 == 0) || (n % 2 && two >= (half - 1) * 2)) {
        flag = true;
        break;
      }
      two++;
      a[i] -= 2;
      if (x == half && y == half) x--;
      if (x == half) {
        t[n - y + 1][x] = t[y][x] = i;
        y++;
      } else if (y == half) {
        t[y][x] = t[y][n - x + 1] = i;
        x--;
      }
    }
  }
  if (two % 2) flag = true;
  if (flag) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  if (n % 2) {
    for (int i = half, j = 1; j < half; j++) {
      if (t[i][j]) continue;
      while (!a[pos]) pos++;
      t[i][j] = t[i][n - j + 1] = pos;
      a[pos] -= 2;
    }
    for (int i = 1, j = half; i < half; i++) {
      if (t[i][j]) continue;
      while (!a[pos]) pos++;
      t[i][j] = t[n - i + 1][j] = pos;
      a[pos] -= 2;
    }
  }
  for (int i = 1; i <= half; i++) {
    for (int j = 1; j <= half; j++) {
      if (t[i][j]) continue;
      while (!a[pos]) pos++;
      a[pos] -= 4;
      t[i][j] = t[n - i + 1][j] = t[i][n - j + 1] = t[n - i + 1][n - j + 1] =
          pos;
    }
  }
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j < n; j++) {
      cout << t[i][j] << ' ';
    }
    cout << t[i][j] << endl;
  }
  return 0;
}
