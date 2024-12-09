#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, RT = 200;
int p[N];
int fr[N];
bool dp[N];
int cnt[N];
int mn[N], mx[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int odd = 0;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) {
    if (p[i] == -1) continue;
    int cur = i, cnt = 0;
    while (true) {
      cnt++;
      int nw = p[cur];
      p[cur] = -1;
      cur = nw;
      if (cur == i) break;
    }
    fr[cnt]++;
    if (cnt % 2) odd++;
  }
  dp[0] = 1;
  for (int i = 1; i <= RT; i++) {
    if (fr[i] == 0) continue;
    int y = (fr[i] + 1) * i;
    for (int x = 0; x < N; x++) cnt[x] = dp[x];
    for (int x = i; x < N; x++) {
      cnt[x] += cnt[x - i];
      int val = cnt[x];
      if (x - y >= 0) val -= cnt[x - y];
      dp[x] = val;
    }
  }
  bitset<N> bs;
  for (int i = 0; i < N; i++) bs[i] = dp[i];
  for (int i = RT + 1; i <= n; i++) {
    while (fr[i]) {
      bs = bs | (bs << i);
      fr[i]--;
    }
  }
  int pr = n - odd;
  assert(pr % 2 == 0);
  for (int i = 0; i <= pr / 2; i++) mx[i] = 2 * i;
  for (int i = pr / 2 + 1; i <= n; i++) mx[i] = min(n, mx[i - 1] + 1);
  for (int i = 0; i <= n; i++) mn[i] = i + !bs[i];
  cout << mn[k] << " " << mx[k] << endl;
}
