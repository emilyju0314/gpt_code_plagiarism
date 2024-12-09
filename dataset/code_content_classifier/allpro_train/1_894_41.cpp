#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n = 0;
  cin >> n;
  int a[n];
  long long int res[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    res[i] = 0LL;
  }
  for (int i = 0; i < n - 1; i++) {
    if (i) res[i] = res[i - 1];
    int t = 0;
    for (t = 0; i + (1 << t) < n; t++)
      ;
    t--;
    a[i + (1 << t)] += a[i];
    res[i] += a[i];
  }
  for (int i = 0; i < n - 1; i++) cout << res[i] << '\n';
  return 0;
}
