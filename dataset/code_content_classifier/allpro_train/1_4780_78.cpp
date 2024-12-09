#include <bits/stdc++.h>
using namespace std;
const long long MXN = 2e5 + 10;
long long q, n, ans, x;
long long A[MXN], B[MXN], dp[MXN];
vector<long long> vec, Ind[MXN];
map<long long, long long> Nxt;
inline int GetId(int x) {
  return lower_bound(vec.begin(), vec.end(), x) - vec.begin();
}
void solve() {
  cin >> n, vec.clear(), Nxt.clear();
  for (int i = 0; i < n; i++)
    cin >> A[i], B[i] = A[i], vec.push_back(A[i]), Ind[i].clear();
  sort(vec.begin(), vec.end()),
      vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
  for (int i = 0; i < vec.size() - 1; i++) Nxt[vec[i]] = vec[i + 1];
  for (int i = 0; i < n; i++) Ind[GetId(A[i])].push_back(i);
  dp[n - 1] = ans = 1;
  for (int j = n - 2; ~j; j--) {
    dp[j] = 1;
    if (GetId(A[j]) + 1 < (int)vec.size()) {
      long long ind = GetId(A[j]) + 1,
                nxt = upper_bound(Ind[ind].begin(), Ind[ind].end(), j) -
                      Ind[ind].begin();
      long long t = (long long)Ind[ind].size() - nxt + 1;
      if (Ind[ind][0] >= j) t = max(t, dp[Ind[ind].back()] + t - 1);
      dp[j] = max(dp[j], t);
    }
    if (j != Ind[GetId(A[j])].back()) {
      long long ind = GetId(A[j]);
      long long nxt = *upper_bound(Ind[ind].begin(), Ind[ind].end(), j);
      dp[j] = max(dp[j], 1 + dp[nxt]);
    }
    ans = max(ans, dp[j]);
  }
  cout << n - ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> q;
  while (q--) solve();
  return 0;
}
