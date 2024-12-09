#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  int m, n, key = 0;
  int maxm = 0;
  cin >> m >> n;
  while (m--) {
    cin >> c;
    if (c == '.') {
      key = 1;
    } else {
      key++;
    }
    maxm = max(maxm, key);
  }
  if (maxm <= n) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
