#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n;
int dp[N];
struct str {
  int first, w;
  str() {}
} M[N];
bool cmp(str a, str b) { return a.first < b.first; }
void load() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &M[i].first, &M[i].w);
  }
}
vector<int> V;
int get(int first) {
  return lower_bound(V.begin(), V.end(), first) - V.begin() + 1;
}
struct fenwick {
  int tree[N * 2];
  int n;
  fenwick() {
    memset(tree, 0, sizeof(tree));
    n = 400004;
  }
  void add(int first, int val) {
    for (; first < n; first += first & -first)
      tree[first] = max(tree[first], val);
  }
  int get(int first) {
    int ans = 0;
    for (; first > 0; first -= first & -first) ans = max(ans, tree[first]);
    return ans;
  }
} F;
void solve() {
  sort(M, M + n, cmp);
  for (int i = 0; i < n; i++)
    V.push_back(M[i].first + M[i].w), V.push_back(M[i].first - M[i].w);
  sort(V.begin(), V.end());
  V.erase(unique(V.begin(), V.end()), V.end());
  dp[0] = 1;
  int sol = 1;
  int curr_max = 0;
  F.add(get(M[0].first + M[0].w), 1);
  for (int i = 1; i < n; i++) {
    int curr = F.get(get(M[i].first - M[i].w));
    dp[i] = curr + 1;
    sol = max(sol, dp[i]);
    F.add(get(M[i].first + M[i].w), dp[i]);
  }
  printf("%d\n", sol);
}
int main(void) {
  load();
  solve();
  return 0;
}
