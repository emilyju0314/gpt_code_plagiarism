#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 1 && m == 1) {
    cout << "YES\n";
    cout << 1 << endl;
    return 0;
  }
  if ((n == 1 && m == 2) || (n == 1 && m == 3) || (n == 2 && m == 1) ||
      (n == 3 && m == 1) || (n == 2 && m == 2) || (n == 2 && m == 3) ||
      (n == 3 && m == 2)) {
    cout << "NO\n";
    return 0;
  }
  if (n == 3 && m == 3) {
    cout << "YES\n";
    cout << 6 << ' ' << 1 << ' ' << 8 << '\n'
         << 7 << ' ' << 5 << ' ' << 3 << '\n'
         << 2 << ' ' << 9 << ' ' << 4 << endl;
    return 0;
  }
  cout << "YES\n";
  if (n == 1) {
    for (int i = 1; i < m; i += 2) {
      cout << i + 1 << ' ';
    }
    for (int i = 0; i < m; i += 2) {
      cout << i + 1 << ' ';
    }
    cout << endl;
    return 0;
  }
  if (m == 1) {
    for (int i = 1; i < n; i += 2) {
      cout << i + 1 << '\n';
    }
    for (int i = 0; i < n; i += 2) {
      cout << i + 1 << '\n';
    }
    cout << endl;
    return 0;
  }
  vector<vector<int> > vt(n, vector<int>(m));
  if (n < m) {
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        for (int j = 0; j < m - (m / 2); j++) {
          vt[i][j] = i * m + (j + 1 + (m / 2));
        }
        for (int j = 0; j < (m / 2); j++) {
          vt[i][(m - (m / 2)) + j] = i * m + (j + 1);
        }
      } else {
        for (int j = 0; j < m; j++) {
          vt[i][j] = i * m + (j + 1);
        }
      }
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < m; j += 2) {
        swap(vt[i][j], vt[i - 1][j]);
      }
    }
  } else {
    for (int i = 0; i < m; i++) {
      if (i % 2 == 0) {
        for (int j = 0; j < n - (n / 2); j++) {
          vt[j][i] = ((n / 2) + j) * m + (i + 1);
        }
        for (int j = 0; j < (n / 2); j++) {
          vt[(n - (n / 2)) + j][i] = j * m + (i + 1);
        }
      } else {
        for (int j = 0; j < n; j++) {
          vt[j][i] = j * m + (i + 1);
        }
      }
    }
    for (int i = 0; i < n; i += 2) {
      for (int j = 1; j < m; j++) {
        swap(vt[i][j], vt[i][j - 1]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << vt[i][j] << ' ';
    }
    cout << '\n';
  }
}
