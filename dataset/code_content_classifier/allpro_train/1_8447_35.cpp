#include <bits/stdc++.h>
using namespace std;
char x[64][500005];
int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long long d = 0;
  for (int i = 0, to = n; i < to; ++i) {
    long long a, b, c;
    cin >> a >> b;
    d ^= b;
    c = a ^ b;
    for (int j = 0, to = 60; j < to; ++j) x[j][i] = (c >> j) & 1;
  }
  for (int j = 0, to = 60; j < to; ++j) x[j][n] = (d >> j) & 1;
  int i = 0, j = 0;
  while (i < 60 && j < n) {
    if (!x[i][j]) {
      for (int i0 = i + 1, to = 60; i0 < to; ++i0) {
        if (x[i0][j]) {
          for (int j0 = j, to = n + 1; j0 < to; ++j0) {
            swap(x[i][j0], x[i0][j0]);
          }
          break;
        }
      }
    }
    if (x[i][j]) {
      for (int i0 = i + 1, to = 60; i0 < to; ++i0) {
        if (x[i0][j]) {
          for (int j0 = j, to = n + 1; j0 < to; ++j0) {
            x[i0][j0] ^= x[i][j0];
          }
        }
      }
      i++;
    }
    j++;
  }
  int m = 60;
  for (int i = 0, to = 60; i < to; ++i) {
    bool w = true;
    for (int j = 0, to = n; j < to; ++j) {
      if (x[i][j]) {
        w = false;
        break;
      }
    }
    if (w) {
      if (x[i][n]) {
        m = -1;
        break;
      } else
        m--;
    }
  }
  if (m < 0)
    cout << "1/1" << endl;
  else
    cout << (1LL << m) - 1 << '/' << (1LL << m) << endl;
  return 0;
}
