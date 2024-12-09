#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
const int maxn = 3e5 + 5;
int a[maxn], ans[maxn];
vector<int> down, up;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  down.push_back(1e9);
  up.push_back(-1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    if (a[i] < down.back() && a[i] > up.back()) {
      if (a[i] < a[i + 1])
        up.push_back(a[i]);
      else
        down.push_back(a[i]), ans[i] = 1;
    } else if (a[i] < down.back())
      down.push_back(a[i]), ans[i] = 1;
    else if (a[i] > up.back())
      up.push_back(a[i]);
    else {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  return 0;
}
