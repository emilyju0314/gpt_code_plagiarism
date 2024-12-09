#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int NN = 2102020;
int sa[NN];
vector<int> trip[2];
int n, m1, m2, t, nn;
int dp[NN][2];
vector<int> mov;
vector<pii> shot;
int is_trip(int u, int id) {
  int it = lower_bound(trip[id].begin(), trip[id].end(), u) - trip[id].begin();
  if (it == trip[id].size()) return 0;
  if (trip[id][it] == u) return 1;
  return 0;
}
void smax(int &u, int v) {
  if (u < v) u = v;
}
int last = 2e9 + 1;
int calc(int u, int id) {
  assert(mov.size() < NN);
  assert(shot.size() < NN);
  if (u == 0) {
    if (!id) return 0;
    mov.push_back(0);
    return 0;
  }
  int f = is_trip(sa[u], id);
  int len = sa[u] - sa[u - 1];
  if (dp[u - 1][id] >= 0 and dp[u - 1][id] + len - 1 >= f * t and
      dp[u][id] == dp[u - 1][id] - f * t + len) {
    if (f) {
      last = min(last - t, sa[u] - 1);
      shot.push_back({last, id});
    }
    return calc(u - 1, id);
  }
  if (sa[u] != n + 1) mov.push_back(sa[u]);
  return calc(u, id ^ 1);
}
int main() {
  cin >> n >> m1 >> m2 >> t;
  for (int i = 0; i < m1; i++) {
    int first;
    scanf("%d", &first);
    trip[0].push_back(first);
    sa[nn++] = first;
    sa[nn++] = first + 1;
  }
  for (int i = 0; i < m2; i++) {
    int first;
    scanf("%d", &first);
    trip[1].push_back(first);
    sa[nn++] = first;
    sa[nn++] = first + 1;
  }
  sa[nn++] = 0;
  sort(sa, sa + nn);
  nn = unique(sa, sa + nn) - sa;
  sa[nn] = n + 1;
  memset(dp, -1, sizeof dp);
  dp[0][0] = dp[0][1] = 0;
  for (int i = 0; i < nn; i++) {
    int dis = sa[i + 1] - sa[i];
    for (int j = 0; j < 2; j++) {
      int st = is_trip(sa[i + 1], j);
      if (dp[i][j] < 0) continue;
      if (dp[i][j] + dis - 1 < t * st) continue;
      smax(dp[i + 1][j], dp[i][j] - t * st + dis);
      if (not is_trip(sa[i + 1], j ^ 1)) {
        smax(dp[i + 1][j ^ 1], min(t, dp[i][j] - t * st + dis));
      }
    }
  }
  if (dp[nn][0] < 0 and dp[nn][1] < 0) {
    puts("No");
    return 0;
  }
  puts("Yes");
  if (dp[nn][0] >= 0)
    calc(nn, 0);
  else if (dp[nn][1] >= 0)
    calc(nn, 1);
  reverse(mov.begin(), mov.end());
  reverse(shot.begin(), shot.end());
  cout << mov.size() << endl;
  for (auto u : mov) printf("%d ", u);
  puts("");
  cout << shot.size() << endl;
  for (auto u : shot) printf("%d %d\n", u.first, u.second + 1);
  return 0;
}
