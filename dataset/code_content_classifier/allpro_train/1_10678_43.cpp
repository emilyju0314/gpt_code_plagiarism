#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s = 0, a = 0, i, x;
  cin >> n;
  vector<int> v;
  for (i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
    s += x;
  }
  if (s % 2 != 0) {
    cout << 0;
  } else {
    x = 0;
    int y = s;
    for (i = 0; i < n - 1; i++) {
      x += v[i];
      y -= v[i];
      if (x == y) {
        a++;
      }
    }
    cout << a;
  }
}
