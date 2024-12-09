#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e9 + 5;
const long long INF = (long long)1e18 + 5;
const int N = 2e5 + 5;
pair<int, int> b[N];
int a[N], tmp[N];
int n, m;
bool ok(int d) {
  vector<int> last(n, -1);
  for (int i = 0; i < (int)(m); i++) {
    if (b[i].first <= d) last[b[i].second] = max(last[b[i].second], b[i].first);
  }
  for (int i = 0; i < (int)(n); i++) tmp[i] = a[i];
  vector<vector<int>> g(N);
  for (int i = 0; i < (int)(n); i++) {
    if (last[i] == -1) continue;
    g[last[i]].push_back(i);
  }
  int cnt = 0;
  for (int i = 0; i <= d; ++i) {
    cnt++;
    if (i > N) continue;
    for (auto it : g[i]) {
      if (tmp[it] <= cnt) {
        cnt -= tmp[it];
        tmp[it] = 0;
      } else {
        tmp[it] -= cnt;
        cnt = 0;
        break;
      }
    }
  }
  int cnt2 = 0;
  for (int i = 0; i < (int)(n); i++) cnt2 += tmp[i];
  return 2 * cnt2 <= cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < (int)(n); i++) {
    cin >> a[i];
  }
  for (int i = 0; i < (int)(m); i++) {
    cin >> b[i].first >> b[i].second;
    b[i].first--;
    b[i].second--;
  }
  int l = 0, r = 4e5;
  while (r - l > 1) {
    int md = (l + r) >> 1;
    if (ok(md))
      r = md;
    else
      l = md;
  }
  for (int i = l; i < (int)(r + 1); i++) {
    if (ok(i)) {
      cout << i + 1 << '\n';
      return 0;
    }
  }
  return 0;
}
