#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
int n, cir[N];
vector<int> adj[N];
bool mark[N], flag;
bool contain(int base, int num) {
  for (int i = 0; i < adj[cir[base]].size(); i++)
    if (adj[cir[base]][i] == cir[num]) return true;
  return false;
}
void bt(int k);
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) {
    int u, v;
    scanf("%d%d", &v, &u);
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    if (adj[i].size() != 4) {
      cout << -1 << '\n';
      return 0;
    }
    sort(adj[i].begin(), adj[i].end());
  }
  cir[0] = 0;
  mark[0] = true;
  for (int i = 0; i < adj[0].size(); i++) {
    cir[1] = adj[0][i];
    mark[cir[1]] = true;
    bt(1);
    if (flag) break;
    mark[cir[1]] = false;
  }
  if (!flag) printf("-1");
  printf("\n");
  return 0;
}
void bt(int k) {
  if (k == n - 1) {
    if (contain(0, n - 1) && contain(0, n - 2) && contain(1, n - 1) && !flag) {
      for (int i = 0; i < n; i++) printf("%d ", cir[i] + 1);
      flag = true;
    }
    return;
  }
  int s = 0, r = 0;
  while (s < adj[k - 1].size() && r < adj[k].size()) {
    if (adj[cir[k - 1]][s] == adj[cir[k]][r]) {
      if (!mark[adj[cir[k]][r]]) {
        cir[k + 1] = adj[cir[k - 1]][s];
        mark[cir[k + 1]] = true;
        bt(k + 1);
        mark[cir[k + 1]] = false;
      }
      r++, s++;
    } else if (adj[cir[k - 1]][s] < adj[cir[k]][r])
      s++;
    else
      r++;
  }
}
