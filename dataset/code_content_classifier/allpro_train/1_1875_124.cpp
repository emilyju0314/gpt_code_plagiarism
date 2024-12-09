#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 2;
const long long inf = 1e18 + 43;
const int mod = 1e9 + 7;
const int maxlog = 20;
vector<int> tof;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  int n;
  cin >> n;
  int cnt = 0, cnt0 = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int y = sqrt(x);
    if (x == 0) {
      cnt0++;
      cnt++;
      continue;
    }
    if (y * y == x) {
      cnt++;
      continue;
    }
    int diff1 = x - y * y;
    int diff2 = (y + 1) * (y + 1) - x;
    diff1 = min(diff1, diff2);
    tof.push_back(diff1);
  }
  sort(tof.begin(), tof.end());
  int need = cnt - n / 2;
  if (cnt >= n / 2) {
    int x = cnt - cnt0;
    int ans = 0;
    ans += min(need, x);
    need -= ans;
    ans += 2 * need;
    cout << ans;
    return 0;
  }
  int x = n / 2 - cnt;
  long long ans = 0;
  for (int i = 0; i < x; i++) ans += (long long)(tof[i]);
  cout << ans;
  return 0;
}
