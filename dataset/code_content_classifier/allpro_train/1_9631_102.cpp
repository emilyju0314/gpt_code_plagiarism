#include <bits/stdc++.h>
using namespace std;
int m, n, k, t, a[200100], dp[200100];
vector<pair<int, int> > v[200100];
int Get(int i, int Max) {
  int Maxx = 0, k = -1;
  while (1) {
    for (auto j : v[i])
      if (j.second > Max) k = max(k, j.first);
    i++;
    if (k < i) break;
  }
  return k;
}
int main() {
  cin >> m >> n >> k >> t;
  for (int i = 0; i < m; i++) cin >> a[i];
  while (k--) {
    int l, r, d;
    cin >> l >> r >> d;
    v[l].push_back({r, d});
  }
  sort(a, a + m, greater<int>());
  int Start = 0, End = m - 1, Ans = -1;
  while (Start <= End) {
    int mid = (Start + End) / 2;
    memset(dp, -1, sizeof(dp));
    int T = t;
    for (int i = 1; i <= n; i++) {
      int j = Get(i, a[mid]);
      if (j != -1) {
        T -= (j - i + 1) * 2;
        i = j;
      }
    }
    if (T - (n + 1) >= 0)
      Ans = mid, Start = mid + 1;
    else
      End = mid - 1;
  }
  cout << Ans + 1;
  return 0;
}
