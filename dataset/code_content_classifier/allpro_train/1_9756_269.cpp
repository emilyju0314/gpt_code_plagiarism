#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int n;
int tc;
struct node {
  int cnt;
  node* L;
  node* R;
  node(int _cnt = 0, node* _L = NULL, node* _R = NULL) {
    L = _L;
    R = _R;
    cnt = _cnt;
  }
  node* insert(int l, int r, int idx, int val);
};
node* null = new node();
node* node ::insert(int l, int r, int idx, int val) {
  if (l == r) {
    return new node(this->cnt + val, NULL, NULL);
  }
  int mid = (l + r) / 2;
  if (idx <= mid) {
    return new node(this->cnt + val, this->L->insert(l, mid, idx, val),
                    this->R);
  }
  return new node(this->cnt + val, this->L,
                  this->R->insert(mid + 1, r, idx, val));
}
node* root[N];
int vis[N];
int query(node* root, int l, int r, int ql, int qr) {
  if (l > qr || r < ql) {
    return 0;
  }
  if (ql <= l && r <= qr) {
    return root->cnt;
  }
  int mid = (l + r) / 2;
  return query(root->L, l, mid, ql, qr) + query(root->R, mid + 1, r, ql, qr);
}
int find(int pos, int k) {
  int low = 1;
  int high = n;
  node* root = ::root[pos];
  if (root->cnt <= k) {
    return 0;
  }
  int ans = 0;
  while (low < high) {
    int mid = (low + high) / 2;
    if (root->R->cnt > k) {
      low = mid + 1;
      root = root->R;
    } else {
      k -= root->R->cnt;
      high = mid;
      root = root->L;
    }
  }
  return low;
}
void solve(int k) {
  int idx = n;
  int ans = 0;
  while (idx > 0) {
    idx = find(idx, k);
    ans++;
  }
  printf("%d ", ans);
}
int main() {
  scanf("%d", &n);
  ;
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &a[i]);
    ;
  }
  null->L = null->R = null;
  root[0] = null;
  for (int i = 1; i < n + 1; i++) {
    root[i] = root[i - 1];
    if (vis[a[i]]) {
      root[i] = root[i]->insert(1, n, vis[a[i]], -1);
      root[i] = root[i]->insert(1, n, i, 1);
    } else {
      root[i] = root[i]->insert(1, n, i, 1);
    }
    vis[a[i]] = i;
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    solve(i);
  }
  cout << endl;
}
