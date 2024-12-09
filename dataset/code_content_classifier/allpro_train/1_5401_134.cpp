#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, p = 1, q;
  cin >> n >> m;
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    cin >> q;
    ans += (q - p + n) % n;
    p = q;
  }
  cout << ans;
}
