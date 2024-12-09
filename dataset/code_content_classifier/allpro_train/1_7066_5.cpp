#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
long double x;
long double y;
int cost[300005], ans[300005];
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> cost[i];
  }
  priority_queue<pair<int, int> > ms;
  for (int i = 1; i <= k; ++i) {
    ms.push(make_pair(cost[i], i));
  }
  long long cst = 0;
  for (int i = k + 1; i <= n; ++i) {
    ms.push(make_pair(cost[i], i));
    ans[ms.top().second] = i;
    cst += 1LL * (i - ms.top().second) * (ms.top().first);
    ms.pop();
  }
  for (int i = n + 1; i <= n + k; ++i) {
    ans[ms.top().second] = i;
    cst += 1LL * (i - ms.top().second) * (ms.top().first);
    ms.pop();
  }
  cout << cst << endl;
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
}
int main() {
  solve();
  return 0;
}
