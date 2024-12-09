#include <bits/stdc++.h>
using namespace std;
void initialize(int start, vector<int>& stree, vector<int>& level, int l,
                int u) {
  if (int((stree).size()) - 1 < start) stree.resize(start + 1);
  if (l == u)
    stree[start] = level[l];
  else {
    initialize(2 * start, stree, level, l, (u + l) / 2);
    initialize(2 * start + 1, stree, level, (u + l) / 2 + 1, u);
    stree[start] = stree[start * 2] + stree[start * 2 + 1];
  }
  return;
}
int rmq(int start, vector<int>& stree, vector<int>& level, int i, int j, int l,
        int u) {
  if (i > j) swap(i, j);
  if (j < l || i > u) return 0;
  if (l >= i && u <= j) return stree[start];
  int t1 = rmq(2 * start, stree, level, i, j, l, (u + l) / 2);
  int t2 = rmq(2 * start + 1, stree, level, i, j, (u + l) / 2 + 1, u);
  return t1 + t2;
}
void updatetree(int start, vector<int>& stree, vector<int>& level, int index,
                int value, int l, int u) {
  if (l == u) {
    level[index] = value;
    stree[start] = value;
    return;
  }
  if (index <= (l + u) / 2)
    updatetree(2 * start, stree, level, index, value, l, (l + u) / 2);
  else
    updatetree(2 * start + 1, stree, level, index, value, (l + u) / 2 + 1, u);
  stree[start] = stree[start * 2] + stree[start * 2 + 1];
  return;
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int> > pos(1e5 + 1);
  for (int i = 0; i <= int((a).size()) - 1; i++) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  long long ans = 0, zero = 0;
  int p = 0, q, b, nt;
  vector<int> stree, deck(n, 0);
  initialize(1, stree, deck, 0, n - 1);
  for (int i = 1; i <= int((pos).size()) - 1; i++) {
    nt = int((pos[i]).size());
    if (nt) {
      nt = int((pos[i]).size());
      sort((pos[i]).begin(), (pos[i]).end());
      b = int(lower_bound((pos[i]).begin(), (pos[i]).end(), p) -
              pos[i].begin());
      q = (pos[i][(b + nt - 1) % nt] + 1) % n;
      if (p >= q) {
        ans += q + n - p;
        if (q) zero += rmq(1, stree, deck, 0, q - 1, 0, n - 1);
        zero += rmq(1, stree, deck, p, n - 1, 0, n - 1);
      } else {
        ans += q - p;
        zero += rmq(1, stree, deck, p, q - 1, 0, n - 1);
      }
      for (int j = 0; j <= int((pos[i]).size()) - 1; j++)
        updatetree(1, stree, deck, pos[i][j], 1, 0, n - 1);
      p = q;
    }
  }
  cout << ans - zero;
  return 0;
}
