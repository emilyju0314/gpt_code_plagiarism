#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 5;
std::vector<int> vt;
vector<pair<int, int> > ht;
std::vector<int> tree[4 * M];
void merge(int x, int y, int z) {
  int n1 = tree[y].size();
  int n2 = tree[z].size();
  int i = 0, j = 0;
  while (i < n1 && j < n2) {
    if (tree[y][i] > tree[z][j]) {
      tree[x].push_back(tree[z][j]);
      j++;
    } else {
      tree[x].push_back(tree[y][i]);
      i++;
    }
  }
  while (i < n1) {
    tree[x].push_back(tree[y][i]);
    i++;
  }
  while (j < n2) {
    tree[x].push_back(tree[z][j]);
    j++;
  }
}
void build(int i, int s, int e) {
  if (s == e) {
    tree[i].push_back(ht[s].second);
    return;
  }
  int m = (s + e) / 2;
  build(2 * i, s, m);
  build(2 * i + 1, m + 1, e);
  merge(i, 2 * i, 2 * i + 1);
  return;
}
int query(int i, int s, int e, int l, int r, int x) {
  if (s > r || l > e) return 0;
  if (s >= l && e <= r) {
    return (int)(tree[i].end() -
                 lower_bound(tree[i].begin(), tree[i].end(), x));
  }
  int m = (s + e) / 2;
  return query(2 * i, s, m, l, r, x) + query(2 * i + 1, m + 1, e, l, r, x);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, i, x, x1, x2;
  cin >> n >> m;
  if (m == 0) {
    cout << 0 << "\n";
    return 0;
  }
  vt.push_back(1);
  for (i = 0; i < n; i++) {
    cin >> x;
    vt.push_back(x);
  }
  vt.push_back(1000000000);
  sort(vt.begin(), vt.end());
  for (i = 0; i < m; i++) {
    cin >> x1 >> x2 >> x;
    ht.push_back(make_pair(x1, x2));
  }
  sort(ht.begin(), ht.end());
  build(1, 0, m - 1);
  int ans = 1e9;
  for (i = 1; i < vt.size(); i++) {
    int p =
        (upper_bound(ht.begin(), ht.end(), make_pair((int)1, (int)1000000001)) -
         ht.begin());
    p--;
    int x = query(1, 0, m - 1, 0, p, vt[i]);
    ans = min(ans, i - 1 + x);
  }
  cout << ans << "\n";
  return 0;
}
