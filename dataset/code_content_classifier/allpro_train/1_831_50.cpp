#include <bits/stdc++.h>
using namespace std;
struct Qwa {
  long long cost;
  int cnt[4];
};
int main(int argc, char**) {
  if (argc > 1) {
    freopen("debug/in.txt", "r", stdin);
    freopen("debug/out.txt", "w", stdout);
  }
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> wc[4];
  for (int k = 1; k < 4; ++k) wc[k].reserve(n);
  for (int i = 0; i < n; ++i) {
    int w, c;
    cin >> w >> c;
    wc[w].push_back(c);
  }
  for (int k = 1; k < 4; ++k)
    sort((wc[k]).begin(), (wc[k]).end(), greater<int>());
  vector<Qwa> dp(m + 1);
  fill(dp[0].cnt, dp[0].cnt + 4, 0);
  long long maxCost = 0;
  for (int j = 1; j < m + 1; ++j) {
    long long cost = 0;
    int wBest = 0;
    for (int w = 1; w < 4 && j - w >= 0; ++w) {
      Qwa q = dp[j - w];
      int cnt = q.cnt[w];
      if (wc[w].size() > cnt) {
        long long wCost = q.cost + wc[w][cnt];
        if (wCost >= cost) {
          cost = wCost;
          wBest = w;
        }
      }
    }
    if (cost) {
      dp[j] = dp[j - wBest];
      dp[j].cost = cost;
      ++dp[j].cnt[wBest];
      maxCost = max(maxCost, cost);
    }
  }
  {
    Qwa q1 = dp[m - 1];
    if (q1.cnt[1] && wc[2].size() > q1.cnt[2]) {
      long long cost = q1.cost - wc[1][q1.cnt[1] - 1] + wc[2][q1.cnt[2]];
      maxCost = max(maxCost, cost);
    }
  }
  if (m > 1) {
    Qwa q2 = dp[m - 2];
    if (q2.cnt[1] && wc[3].size() > q2.cnt[3]) {
      long long cost = q2.cost - wc[1][q2.cnt[1] - 1] + wc[3][q2.cnt[3]];
      maxCost = max(maxCost, cost);
    }
  }
  cout << maxCost << endl;
}
