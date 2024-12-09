#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 5;
int ans, n, k;
vector<int> mmp[M];
int dfs(int f, int v) {
  if (mmp[v].size() == 1) return 0;
  vector<int> tmp;
  for (int i = mmp[v].size() - 1; i >= 0; --i)
    if (mmp[v][i] != f) tmp.push_back(dfs(v, mmp[v][i]) + 1);
  sort(tmp.begin(), tmp.end());
  for (int siz; (siz = tmp.size()) > 1; ++ans, tmp.pop_back())
    if (tmp[siz - 1] + tmp[siz - 2] <= k) break;
  return tmp.back();
}
void in() {
  scanf("%d%d", &n, &k);
  for (int i = 1, a, b; i < n; ++i)
    scanf("%d%d", &a, &b), mmp[a].push_back(b), mmp[b].push_back(a);
}
void ac() {
  for (int i = 1; i <= n; ++i)
    if (mmp[i].size() > 1) dfs(0, i), printf("%d", ans + 1), exit(0);
}
int main() { in(), ac(); }
