#include <bits/stdc++.h>
using namespace std;
int T;
int N;
int L[3030], R[3030], in[3030], dp[3030], dp2[6060];
vector<int> g[3030], h[3030];
vector<pair<int, int> > G[6060];
vector<int> com;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (int i = 1; i <= N + 1; i++) {
      g[i].clear();
      h[i].clear();
    }
    com.clear();
    for (int i = 1; i <= N; i++) {
      scanf("%d %d", &L[i], &R[i]);
      com.push_back(L[i]);
      com.push_back(R[i]);
    }
    N++;
    L[N] = 1;
    R[N] = 200001;
    com.push_back(L[N]);
    com.push_back(R[N]);
    sort(com.begin(), com.end());
    com.erase(unique(com.begin(), com.end()), com.end());
    for (int i = 1; i <= N; i++) {
      L[i] = lower_bound(com.begin(), com.end(), L[i]) - com.begin() + 1;
      R[i] = lower_bound(com.begin(), com.end(), R[i]) - com.begin() + 1;
    }
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++) {
        if (i == j) continue;
        if (max(L[i], L[j]) == L[j] && min(R[i], R[j]) == R[j]) {
          g[i].push_back(j);
          h[j].push_back(i);
          in[i]++;
        }
      }
    queue<int> q;
    for (int i = 1; i <= N; i++)
      if (in[i] == 0) q.push(i);
    while (!q.empty()) {
      int n = q.front();
      q.pop();
      for (int next : h[n])
        if (--in[next] == 0) q.push(next);
      for (int i = 1; i <= N * 2; i++) G[i].clear();
      for (int next : g[n]) G[R[next]].push_back({L[next] - 1, dp[next]});
      dp2[0] = 0;
      for (int i = 1; i <= N * 2; i++) {
        dp2[i] = dp2[i - 1];
        for (auto &it : G[i]) {
          int j = it.first, cost = it.second;
          dp2[i] = max(dp2[i], dp2[j] + cost);
        }
      }
      dp[n] = dp2[N * 2] + 1;
    }
    printf("%d\n", dp[N] - 1);
  }
  return 0;
}
