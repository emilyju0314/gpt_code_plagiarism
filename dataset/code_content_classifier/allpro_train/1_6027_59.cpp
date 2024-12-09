#include <bits/stdc++.h>
using namespace std;
long long n, t, i, m, a = 0, j, r, c, c1, p, q;
int main() {
  cin >> n;
  vector<int> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (i = 2; i < n; i++) {
    p = v[i] - v[i - 1];
    q = v[i - 1] - v[i - 2];
    if (p != q) {
      a++;
    }
  }
  if (a == 0) {
    r = v[1] - v[0];
    c = v[0] + (n)*r;
    cout << c;
  } else {
    cout << v[n - 1];
  }
}
