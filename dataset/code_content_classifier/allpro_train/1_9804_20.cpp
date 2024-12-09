#include <bits/stdc++.h>
using namespace std;
const int K = 16, N = 5010;
int n[K], a[K][N], dp[1 << K], par[1 << K], mark, k;
map<long long, int> mp;
pair<int, long long> cyc[1 << K];
pair<int, int> ans[K];
long long sum[K], SUM;
void addcycle(int id, long long x) {
  mark = 0;
  int i = id;
  long long j = x;
  while ((mark & (1 << i)) == 0) {
    mark ^= (1 << i);
    long long s = SUM - (sum[i] - j);
    if (mp.find(s) == mp.end()) return;
    i = mp[s], j = s;
  }
  if (i != id || x != j) return;
  cyc[mark] = {id, x};
}
void PrintCyc(int mask) {
  mark = 0;
  int i = cyc[mask].first;
  long long j = cyc[mask].second;
  while ((mark & (1 << i)) == 0) {
    mark ^= (1 << i);
    long long s = SUM - (sum[i] - j);
    ans[mp[s]] = {s, i + 1};
    i = mp[s], j = s;
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 0; i < (1 << K); i++) cyc[i] = {-1, -1};
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> n[i];
    for (int j = 0; j < n[i]; j++) {
      cin >> a[i][j];
      SUM += a[i][j];
      sum[i] += a[i][j];
      mp[a[i][j]] = i;
    }
  }
  if (SUM % k != 0) return cout << "No\n", 0;
  SUM /= k;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n[i]; j++) {
      addcycle(i, a[i][j]);
    }
  }
  int X = (1 << k) - 1;
  dp[0] = 1;
  for (int i = 0; i <= X; i++)
    if (cyc[i] != make_pair(-1, -1ll)) {
      int mask = X ^ i;
      for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
        dp[sub ^ i] |= dp[sub];
        if (dp[sub]) par[sub ^ i] = sub;
      }
      dp[i] = 1;
      par[i] = 0;
    }
  if (!dp[X]) return cout << "No\n", 0;
  cout << "Yes\n";
  while (X) {
    int Z = X ^ par[X];
    X = par[X];
    PrintCyc(Z);
  }
  for (int i = 0; i < k; i++)
    cout << ans[i].first << " " << ans[i].second << "\n";
}
