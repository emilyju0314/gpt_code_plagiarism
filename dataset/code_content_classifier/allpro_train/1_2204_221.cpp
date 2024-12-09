#include <bits/stdc++.h>
using namespace std;
set<int> x, y;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    x.insert(a);
    y.insert(b);
  }
  cout << min(x.size(), y.size());
  return 0;
}
