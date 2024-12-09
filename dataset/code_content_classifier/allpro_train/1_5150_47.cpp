#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 1) ok = true;
  }
  if (ok)
    cout << -1 << endl;
  else
    cout << 1 << endl;
}
