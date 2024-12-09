#include <bits/stdc++.h>
using namespace std;
template <class T>
inline int size(T x) {
  return x.size();
}
int n;
int a[2000];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << a[0] << endl;
    cout << 1 << endl;
    exit(0);
  }
  int t[1005][1005] = {};
  int w[1005][1005] = {};
  for (int i = 0; i < 1005; i++) {
    t[n][i] = a[i];
    t[n - 1][i] = max(a[i], a[n - 1]);
  }
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      t[i][j] = 1000000005;
      int x;
      x = t[i + 2][j] + max(a[i], a[i + 1]);
      if (x < t[i][j]) {
        t[i][j] = x;
        w[i][j] = j;
      }
      x = t[i + 2][i] + max(a[j], a[i + 1]);
      if (x < t[i][j]) {
        t[i][j] = x;
        w[i][j] = i;
      }
      x = t[i + 2][i + 1] + max(a[j], a[i]);
      if (x < t[i][j]) {
        t[i][j] = x;
        w[i][j] = i + 1;
      }
    }
  }
  cout << t[1][0] << endl;
  int i = 1, j = 0;
  while (true) {
    if (i == n) {
      cout << j + 1 << endl;
      break;
    }
    if (i == n - 1) {
      cout << j + 1 << " " << n << endl;
      break;
    }
    if (w[i][j] == i) {
      cout << j + 1 << " " << i + 2 << endl;
    } else if (w[i][j] == i + 1) {
      cout << j + 1 << " " << i + 1 << endl;
    } else {
      cout << i + 1 << " " << i + 2 << endl;
    }
    j = w[i][j];
    i += 2;
  }
}
