#include <bits/stdc++.h>
using namespace std;
int tree[4 * 1000000];
int update(int i, int j, int pos, int cur, int key, int* time) {
  int mid = (i + j) / 2, r;
  if (i == j && j == pos)
    tree[cur] = key;
  else if (pos <= mid) {
    r = update(i, mid, pos, 2 * cur, key, time);
    if (tree[2 * cur + 1] == -1)
      tree[cur] = r;
    else
      tree[cur] = *time % 2 ? r | tree[2 * cur + 1] : r ^ tree[2 * cur + 1];
    (*time)++;
  } else {
    r = update(mid + 1, j, pos, 2 * cur + 1, key, time);
    if (tree[2 * cur] == -1)
      tree[cur] = r;
    else
      tree[cur] = *time % 2 ? r | tree[2 * cur] : r ^ tree[2 * cur];
    (*time)++;
  }
  return tree[cur];
}
int main() {
  int n, m, pi, bi;
  int v[1000000];
  memset(tree, -1, sizeof(tree));
  cin >> n >> m;
  int t = 0;
  n = 2 << n - 1;
  for (int i = 1; i <= n; i++) {
    t = 1;
    cin >> v[i];
    update(1, n, i, 1, v[i], &t);
  }
  while (m--) {
    t = 1;
    cin >> pi >> bi;
    update(1, n, pi, 1, bi, &t);
    cout << tree[1] << endl;
  }
  return 0;
}
