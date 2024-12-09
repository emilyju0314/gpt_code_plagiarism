#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using pii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vlli = vector<long long int>;
using vpii = vector<pair<int, int>>;
int n, t, d, p, ans, ansCnt;
vector<tuple<int, int, int, int>> data;
int dp[101][2005];
vi ansList;
int solve(int idx, int T) {
  if (idx >= n) return 0;
  if (dp[idx][T] != -1) return dp[idx][T];
  dp[idx][T] = solve(idx + 1, T);
  int d, t, p;
  tie(d, t, p, ignore) = data[idx];
  if (T + t < d) dp[idx][T] = max(dp[idx][T], solve(idx + 1, T + t) + p);
  return dp[idx][T];
}
void resconstruct(int idx, int T) {
  int d, t, p, x;
  tie(d, t, p, x) = data[idx];
  if (idx == n - 1) {
    if (T + t < d) ansList.push_back(x), ansCnt++;
    return;
  }
  if (idx + 1 < n && dp[idx][T] == dp[idx + 1][T])
    resconstruct(idx + 1, T);
  else
    ansList.push_back(x), ansCnt++, resconstruct(idx + 1, T + t);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t >> d >> p;
    data.push_back(make_tuple(d, t, p, i + 1));
  }
  memset(dp, -1, sizeof dp);
  sort((data).begin(), (data).end());
  ans = solve(0, 0);
  resconstruct(0, 0);
  cout << ans << '\n';
  cout << ansCnt << '\n';
  for (int i = 0; i < ansList.size(); i++) cout << ansList[i] << " ";
}
