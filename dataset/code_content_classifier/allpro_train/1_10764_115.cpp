#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, x, m, t = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> x >> m;
    for (long long i = ((x + m - 1) / 4) * 4; i < x + m; i++) t ^= i;
    for (long long i = ((x - 1) / 4) * 4; i < x; i++) t ^= i;
  }
  if (t)
    cout << "tolik";
  else
    cout << "bolik";
  return 0;
}
