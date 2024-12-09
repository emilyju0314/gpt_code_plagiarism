#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long i, j, x, n, m, l, r;
  cin >> n >> m;
  vector<long long> v;
  for (i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  for (i = 0; i < m; i++) {
    cin >> l >> r >> x;
    long long c = 0;
    if (x < l || x > r) {
      cout << "Yes\n";
      continue;
    }
    for (j = l - 1; j < r; j++) {
      if (v[j] < v[x - 1]) {
        c++;
      }
    }
    if (c == (x - l)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
