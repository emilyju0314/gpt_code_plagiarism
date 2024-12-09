#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000000")
using namespace std;
int n, r, c, ansf = -1, anss = -1, ans = -1;
vector<int> good, sum, temp, used;
vector<vector<int> > g;
vector<string> op;
void dfs(int id, int now) {
  temp[now] = id;
  used[id] = 1;
  int pre = temp[max(-1, now - r) + 1];
  pre += good[pre] - 1;
  if (ans < (pre - id + 1)) {
    ans = pre - id + 1;
    ansf = id;
    anss = pre;
  }
  for (int i = 0; i < g[id].size(); i++) dfs(g[id][i], now + 1);
}
int main() {
  cin >> n >> r >> c;
  op.resize(n);
  temp.resize(n + 1);
  used.resize(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> op[i];
  }
  sum.resize(n, 0);
  sum[0] = -1;
  for (int i = 0; i < n; i++) {
    sum[i] += op[i].size() + 1;
    if (i < n - 1) sum[i + 1] = sum[i];
  }
  good.resize(n + 1, 0);
  for (int i = 0; i < n; i++) {
    int from = i ? sum[i - 1] + 2 : 1;
    vector<int>::iterator it =
        upper_bound(sum.begin(), sum.end(), from + c - 1);
    if (it == sum.begin() || (--it) - sum.begin() < i) continue;
    good[i] = it - sum.begin() - i + 1;
  }
  g.resize(n + 1);
  for (int i = 0; i < n; i++) {
    if (good[i] > 0) {
      g[i + good[i]].push_back(i);
    }
  }
  for (int i = n; i >= 0; i--) {
    if (used[i]) continue;
    dfs(i, 0);
  }
  if (ans != -1) {
    while (ansf <= anss) {
      for (int i = ansf; i < ansf + good[ansf]; i++) {
        if (i != ansf) cout << " ";
        cout << op[i];
      }
      ansf += good[ansf];
      cout << endl;
    }
  }
}
