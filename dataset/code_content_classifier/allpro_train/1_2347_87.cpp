#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) cin >> v[i];
  int count = 1, mx = 1;
  for (int i = 2; i <= n; i++) {
    if (v[i] == v[i - 1]) {
      mx = max(count, mx);
      count = 1;
    } else
      count++;
  }
  cout << max(mx, count);
}
int main() {
  solve();
  return 0;
}
