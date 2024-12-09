#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int n, m, mx, s;
  cin >> n >> m;
  const int N = n;
  const int M = m;
  mx = max(N, M);
  int a[mx][mx], b[mx][mx];
  int mas[mx];
  int mass[mx];
  s = 0;
  for (int i = 0; i < mx; ++i) {
    mas[i] = 0;
    mass[i] = 0;
  }
  for (int i = 0; i < mx * mx; ++i) {
    a[i / mx][i % mx] = 0;
    b[i / mx][i % mx] = 0;
  }
  for (int i = 0; i < N; ++i) {
    for (int k = 0; k < M; ++k) {
      cin >> a[i][k];
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int k = 0; k < M; ++k) {
      cin >> b[i][k];
    }
  }
  for (int i = 0; i < mx; ++i) {
    if (s == 0) {
      for (int k = 0; k < i + 1; ++k) {
        mas[k] = a[k][i - k];
        mass[k] = b[k][i - k];
      }
      sort(mas, mas + mx);
      sort(mass, mass + mx);
      for (int k = 0; k < mx; ++k) {
        if (mas[k] != mass[k]) {
          s = 1;
          break;
        }
      }
    }
  }
  int mxx = mx - 1;
  for (int i = 0; i < mx; ++i) {
    if (s == 0) {
      for (int k = 0; k < i + 1; ++k) {
        mas[k] = a[mxx - k][mxx - (i - k)];
        mass[k] = b[mxx - k][mxx - (i - k)];
      }
      sort(mas, mas + mx);
      sort(mass, mass + mx);
      for (int k = 0; k < mx; ++k) {
        if (mas[k] != mass[k]) {
          s = 1;
          break;
        }
      }
    }
  }
  if (s == 1) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  return 0;
}
