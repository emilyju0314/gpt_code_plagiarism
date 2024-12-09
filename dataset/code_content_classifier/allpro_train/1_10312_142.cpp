#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 1;
int dem[maxn];
int main() {
  int n, k, x, ans = 0, ma = 0;
  cin >> n >> k;
  for (int i = 1; i <= (int)(n); ++i) {
    cin >> x;
    if (x == k)
      ans++;
    else
      dem[x] = max(dem[x], ans) + 1;
    ma = max(ma, dem[x] - ans);
  }
  cout << ans + ma;
}
