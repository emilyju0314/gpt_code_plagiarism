#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, n; cin >> x >> n;
  while (n--) {
    int y; cin >> y;
    x -= y;
  }
  if (x > 0) cout << "No\n";
  else cout << "Yes\n";
}