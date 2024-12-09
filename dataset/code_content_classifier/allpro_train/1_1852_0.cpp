#include <bits/stdc++.h>
using namespace std;
inline long long max_(long long a, long long b) { return (a > b) ? a : b; }
inline long long min_(long long a, long long b) { return (a < b) ? a : b; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  long long n, m;
  cin >> n >> m;
  long long k, i, x, y;
  cin >> k;
  pair<long long, long long> a[k];
  for (i = 0; i < k; i++) {
    cin >> a[i].first >> a[i].second;
  }
  long long ans = -1, j, l;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      long long tmp = 4000;
      for (l = 0; l < k; l++)
        tmp = min_(tmp, abs(i - a[l].first) + abs(j - a[l].second));
      if (ans < tmp) {
        ans = tmp;
        x = i, y = j;
      }
    }
  cout << x << " " << y;
  return 0;
}
