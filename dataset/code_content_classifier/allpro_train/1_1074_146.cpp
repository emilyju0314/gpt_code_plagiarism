#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (m * 3 > n) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 1; i <= m; i++) cout << i << " " << i << " ";
  for (int i = 1; i <= m; i++) cout << i << " ";
  for (int i = 1; i <= n - 3 * m; i++) cout << "1 ";
  return 0;
}
