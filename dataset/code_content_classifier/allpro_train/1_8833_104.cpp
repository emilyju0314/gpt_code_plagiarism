#include <bits/stdc++.h>
using namespace std;
const long long int inf = 0x3f3f3f3f3f3f3f3fll;
vector<int> adj[1000005];
vector<int> vis(1000005, false);
long long int n, m, k;
long long int mx;
map<long long int, long long int> mpp;
set<long long int> st;
long long int dp[1000005] = {0};
vector<long long int> arr;
pair<long long int, long long int> bus[1000005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i < m + 1; i++) {
    cin >> bus[i].second >> bus[i].first;
  }
  sort(bus + 1, bus + m + 1);
  for (int i = 1; i < m + 1; i++) {
    swap(bus[i].second, bus[i].first);
  }
  dp[0] = 1;
  long long int ans = 0;
  for (int i = 1; i < m + 1; i++) {
    dp[i] = dp[i - 1];
    int en = -1, sta = -1;
    int p = -1;
    for (int a = i; a >= 1; a /= 2) {
      while (p + a < i && bus[p + a].second < bus[i].second) p += a;
    }
    en = p;
    p = -1;
    for (int a = i; a >= 1; a /= 2) {
      while (p + a < i && bus[p + a].second < bus[i].first) p += a;
    }
    sta = p + 1;
    if (sta > en || sta == -1 || en == -1) continue;
    if (sta != 0) sta = dp[sta - 1];
    dp[i] = (dp[i] + dp[en] - sta) % 1000000007;
    if (bus[i].second == n) ans = (ans + dp[en] - sta) % 1000000007;
  }
  cout << (ans + 1000000007) % 1000000007 << endl;
  return 0;
}
