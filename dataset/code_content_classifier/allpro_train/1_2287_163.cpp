#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  set<int> x, y;
  x.insert(1);
  x.insert(n);
  y.insert(1);
  y.insert(n);
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    x.insert(a);
    y.insert(b);
  }
  if (n % 2) {
    if (x.find(n / 2 + 1) == x.end())
      y.insert(n / 2 + 1);
    else
      x.insert(n / 2 + 1);
  }
  cout << 2 * n - x.size() - y.size();
  return 0;
}
