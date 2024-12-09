#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, l, r, t = 10;
  cin >> n >> m;
  int a[n], b[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int j = 0; j < m; j++) {
    cin >> b[j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] == b[j] && b[j] < t) t = a[i];
    }
  }
  if (t < 10) {
    cout << t << endl;
  } else {
    k = a[0];
    l = b[0];
    for (int i = 0; i < n; i++) {
      if (a[i] < k) k = a[i];
    }
    for (int j = 0; j < m; j++) {
      if (b[j] < l) l = b[j];
    }
    if (k == l) {
      cout << k;
    }
    if (k > l) {
      r = k + l * 10;
      cout << r << endl;
    }
    if (k < l) {
      r = l + k * 10;
      cout << r << endl;
    }
  }
}
