#include <bits/stdc++.h>
using namespace std;
const int K = 30;
const int N = 1e6 + 10;
int n, cnt[5], second;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    cnt[x]++;
    second += x;
  }
  if (second <= 2 || second == 5) return cout << -1, 0;
  int ans = 0;
  ans += min(cnt[1], cnt[2]);
  if (cnt[1] <= cnt[2]) {
    cnt[2] -= cnt[1];
    cnt[3] += cnt[1];
    cnt[1] = 0;
    cnt[3] += (cnt[2] / 3) * 2;
    ans += (cnt[2] / 3) * 2;
    cnt[2] %= 3;
    if (cnt[2] == 2)
      ans += 2;
    else if (cnt[2] == 1) {
      if (cnt[4] >= 1)
        ans++;
      else
        ans += 2;
    }
  } else {
    cnt[1] -= cnt[2];
    cnt[3] += cnt[2];
    cnt[2] = 0;
    ans += (cnt[1] / 3) * 2;
    cnt[3] += cnt[1] / 3;
    cnt[1] %= 3;
    if (cnt[3] >= cnt[1])
      ans += cnt[1];
    else
      ans += 2;
  }
  cout << ans;
  return 0;
}
