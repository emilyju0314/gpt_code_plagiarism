#include <bits/stdc++.h>
using namespace std;
int n, m, f[51], s;
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> f[i];
  }
  sort(f, f + m);
  for (int i = 0; i + n - 1 < m; i++) {
    if (i == 0 || (f[i + n - 1] - f[i]) < s) {
      s = f[i + n - 1] - f[i];
    }
  }
  cout << s;
}
