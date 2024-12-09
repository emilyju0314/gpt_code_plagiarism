#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, t;
  cin >> n;
  int a[n];
  map<int, int> m;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) {
    m.clear();
    m[i] = 1;
    t = a[i - 1];
    while (!m[t]) {
      m[t] = 1;
      t = a[t - 1];
    }
    cout << t << " ";
  }
}
