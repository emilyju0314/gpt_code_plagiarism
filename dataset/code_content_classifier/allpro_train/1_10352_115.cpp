#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }
  int jack, emma = INT_MIN;
  for (int i = 0; i < n; i++) {
    jack = INT_MAX;
    for (int j = 0; j < m; j++) jack = min(jack, a[i][j]);
    emma = max(jack, emma);
  }
  cout << emma << endl;
  return 0;
}
