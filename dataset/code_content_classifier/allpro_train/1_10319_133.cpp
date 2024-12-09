#include <bits/stdc++.h>
using namespace std;
int n, m;
int hh[22];
bool check(int x) {
  while (x != 0) {
    if (hh[x % 10]) return 0;
    hh[x % 10] = 1;
    x /= 10;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = n; i <= m; i++) {
    if (check(i)) {
      cout << i;
      return 0;
    }
    memset(hh, 0, sizeof(hh));
  }
  cout << -1;
  return 0;
}
