#include <bits/stdc++.h>
using namespace std;
int n, i, x, y, d[44000];
bool flag;
int main() {
  cin >> n;
  flag = false;
  for (i = 0; i < n; i++) {
    cin >> x >> y;
    d[x + 22000] = x + y + 22000;
    if (d[x + y + 22000] == x + 22000) flag = true;
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}