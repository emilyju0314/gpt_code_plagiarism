#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAX = 500005;
int arr[MAX];
int tree[8 * MAX];
void build(int node, int a, int b) {
  if (a == b) {
    tree[node] = MOD;
    return;
  }
  build(2 * node, a, (a + b) / 2);
  build(2 * node + 1, (a + b) / 2 + 1, b);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
void update(int node, int a, int b, int i, int value) {
  if (a > i || b < i) {
    return;
  }
  if (a == b) {
    tree[node] = value;
    return;
  }
  update(2 * node, a, (a + b) / 2, i, value);
  update(2 * node + 1, (a + b) / 2 + 1, b, i, value);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
int query(int node, int a, int b, int i, int j) {
  if (a > j || b < i) {
    return MOD;
  }
  if (i <= a && b <= j) {
    return tree[node];
  }
  int x = query(2 * node, a, (a + b) / 2, i, j);
  int y = query(2 * node + 1, (a + b) / 2 + 1, b, i, j);
  return min(x, y);
}
vector<pair<int, int> > queries[MAX];
map<int, int> lastocc;
int ans[MAX];
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  build(1, 1, n);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < q; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    queries[y].push_back(make_pair(x, i));
  }
  for (int i = 1; i < n + 1; i++) {
    int lst = lastocc[arr[i]];
    if (lst != 0) {
      update(1, 1, n, lst, i - lst);
    }
    for (pair<int, int> j : queries[i]) {
      ans[j.second] = query(1, 1, n, j.first, i);
    }
    lastocc[arr[i]] = i;
  }
  for (int i = 0; i < q; i++) {
    if (ans[i] != MOD) {
      cout << ans[i] << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
