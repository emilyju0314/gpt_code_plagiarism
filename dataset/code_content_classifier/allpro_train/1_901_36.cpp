#include <bits/stdc++.h>
using namespace std;
int n, m, i;
long long lft, rght, mid, sol, a[100005], b[100005];
bool check(long long val) {
  int i1 = 1, i2 = 1;
  long long current, dist, inter;
  while (i1 <= n && i2 <= m) {
    current = a[i1];
    if (current - val > b[i2]) {
      return false;
    } else if (current + val < b[i2]) {
      i1++;
      continue;
    } else if (current <= b[i2])
      dist = current + val;
    else {
      inter = current - b[i2];
      dist = max(val - inter * 2 + current, (val - inter) / 2 + current);
    }
    while (i2 <= m && b[i2] <= dist) i2++;
    i1++;
  }
  return i2 == m + 1;
}
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= m; i++) cin >> b[i];
  lft = 0;
  rght = abs(a[1] - b[1]) + abs(b[m] - b[1]);
  while (lft <= rght) {
    mid = (lft + rght) / 2;
    if (check(mid)) {
      sol = mid;
      rght = mid - 1;
    } else
      lft = mid + 1;
  }
  cout << sol << "\n";
  return 0;
}
