#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 5;
const int M = 5;
struct TreeNode {
  int mn;
  int mx;
  TreeNode() {
    mn = INT_MAX;
    mx = INT_MIN;
  }
};
TreeNode tree[5 * N][32];
int A[N][M];
int n, k;
void build(int node, int start, int end) {
  if (start == end) {
    int sum = 0;
    for (int j = 0; j < (1 << (k - 1)); j++) {
      sum = 0;
      for (int i = 0; i < k; i++) {
        int sign = 1;
        if (i && (j & (1 << (i - 1)))) {
          sign = -1;
        }
        sum += sign * A[start][i];
      }
      tree[node][j].mx = tree[node][j].mn = sum;
    }
  } else {
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    for (int j = 0; j < (1 << (k - 1)); j++) {
      tree[node][j].mx = max(tree[2 * node][j].mx, tree[2 * node + 1][j].mx);
      tree[node][j].mn = min(tree[2 * node][j].mn, tree[2 * node + 1][j].mn);
    }
  }
}
void update(int node, int start, int end, int idx, int val) {
  if (start == end) {
    int sum = 0;
    for (int j = 0; j < (1 << (k - 1)); j++) {
      sum = 0;
      for (int i = 0; i < k; i++) {
        int sign = 1;
        if (i && (j & (1 << (i - 1)))) {
          sign = -1;
        }
        sum += sign * A[idx][i];
      }
      tree[node][j].mx = tree[node][j].mn = sum;
    }
  } else {
    int mid = (start + end) / 2;
    if (start <= idx and idx <= mid) {
      update(2 * node, start, mid, idx, val);
    } else {
      update(2 * node + 1, mid + 1, end, idx, val);
    }
    for (int j = 0; j < (1 << (k - 1)); j++) {
      tree[node][j].mx = max(tree[2 * node][j].mx, tree[2 * node + 1][j].mx);
      tree[node][j].mn = min(tree[2 * node][j].mn, tree[2 * node + 1][j].mn);
    }
  }
}
vector<TreeNode> query(int node, int start, int end, int l, int r) {
  if (r < start or end < l) {
    return {};
  }
  if (l <= start and end <= r) {
    vector<TreeNode> ret(1 << (k - 1));
    for (int j = 0; j < (1 << (k - 1)); j++) {
      ret[j] = tree[node][j];
    }
    return ret;
  }
  int mid = (start + end) / 2;
  auto p1 = query(2 * node, start, mid, l, r);
  auto p2 = query(2 * node + 1, mid + 1, end, l, r);
  if (p1.empty()) {
    return p2;
  }
  if (p2.empty()) {
    return p1;
  }
  vector<TreeNode> ret(1 << (k - 1));
  for (int j = 0; j < (1 << (k - 1)); j++) {
    ret[j].mx = max(p1[j].mx, p2[j].mx);
    ret[j].mn = min(p1[j].mn, p2[j].mn);
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < k; j++) {
      cin >> A[i][j];
    }
  }
  build(1, 1, n);
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int idx;
      cin >> idx;
      for (int i = 0; i < k; i++) {
        cin >> A[idx][i];
      }
      update(1, 1, n, idx, 0);
    } else {
      int l, r;
      cin >> l >> r;
      auto get = query(1, 1, n, l, r);
      int ans = 0;
      for (int j = 0; j < (1 << (k - 1)); j++) {
        ans = max(ans, abs(get[j].mn - get[j].mx));
      }
      cout << ans << endl;
    }
  }
}
