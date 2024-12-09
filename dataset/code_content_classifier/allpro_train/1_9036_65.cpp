#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
pair<long long int, long long int> s4[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
pair<long long int, long long int> s8[8] = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
int a[100005], l[100005], r[100005];
void solve() {
  int n, m, x, y;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    l[i] = i;
    r[i] = i;
  }
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] <= a[i + 1]) {
      r[i] = r[i + 1];
    }
  }
  for (int i = 2; i <= n; i++) {
    if (a[i] <= a[i - 1]) {
      l[i] = l[i - 1];
    }
  }
  while (m--) {
    cin >> x >> y;
    if (r[x] >= l[y]) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  solve();
}
