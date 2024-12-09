#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const long long INF = 1ll * 0x3f3f3f3f;
int d = 0, sang[N];
vector<pair<int, int> > a[N];
void INIT() {
  memset(sang, true, sizeof sang);
  sang[0] = sang[1] = false;
  for (int i = (2); i <= (sqrt(N)); ++i)
    for (int j = i; j <= N / i; j++) sang[j * i] = false;
  for (int i = (2); i <= (N); ++i)
    if (sang[i]) sang[++d] = i;
}
int main() {
  INIT();
  int n, m, sum = 0;
  cin >> n >> m;
  for (int i = (1); i <= (n - 2); ++i) {
    sum++;
    a[i].push_back(pair<int, int>(1, i + 1));
  }
  int ans = *upper_bound(sang + 1, sang + 1 + d, sum);
  a[n - 1].push_back(pair<int, int>(ans - sum, n));
  int cnt = 0;
  cout << ans << " " << ans << endl;
  for (int i = (1); i <= (n - 2); ++i)
    for (int j = (i + 2); j <= (n); ++j)
      if (++cnt <= m - n + 1)
        a[i].push_back(pair<int, int>(N, j));
      else
        break;
  for (int i = (1); i <= (n - 1); ++i)
    for (int j = (0); j < (a[i].size()); ++j)
      cout << i << " " << a[i][j].second << " " << a[i][j].first << endl;
  return 0;
}
