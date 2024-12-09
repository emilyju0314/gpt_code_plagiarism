#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int m;
  cin >> n >> m;
  vector<bool> goodV(n, true);
  vector<bool> goodH(n, true);
  for (int i = 0; i < m; ++i) {
    int x;
    int y;
    cin >> x >> y;
    --x;
    --y;
    goodV[x] = false;
    goodH[y] = false;
  }
  int ans = 0;
  for (int i = 1; i <= n / 2 - 1; ++i) {
    int cnt = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    if (goodV[i]) {
      ++cnt;
    }
    if (goodV[n - i - 1]) {
      ++cnt;
    }
    if (goodH[i]) {
      ++cnt;
    }
    if (goodH[n - i - 1]) {
      ++cnt;
    }
    ans += cnt;
  }
  if (n % 2 == 1) {
    int cnt = 0;
    if (goodV[n / 2]) {
      ++cnt;
    }
    if (goodH[n / 2]) {
      ++cnt;
    }
    if (cnt > 0) {
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
