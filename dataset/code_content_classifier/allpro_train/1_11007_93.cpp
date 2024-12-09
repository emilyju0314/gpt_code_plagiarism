#include <bits/stdc++.h>
using namespace std;
int n, num, T, R = 100;
struct Tree {
  int v = 0, cnt = 0;
};
Tree tree[400];
void update(int node, int l, int r, int u) {
  if (l == r && l == u) {
    tree[node].v += num;
    tree[node].cnt++;
    return;
  }
  int mid = (l + r) / 2;
  if (u <= mid) {
    update(node * 2, l, mid, u);
  } else {
    update(node * 2 + 1, mid + 1, r, u);
  }
  tree[node].v = tree[node * 2].v + tree[node * 2 + 1].v;
  tree[node].cnt = tree[node * 2].cnt + tree[node * 2 + 1].cnt;
}
int fnd(int node, int l, int r, int sum, int cnt) {
  int mid = (l + r) / 2;
  if (l > r) return cnt;
  if (l == r) {
    return cnt + min(sum / l, tree[node].cnt);
  }
  if (tree[node].v <= sum) return cnt + tree[node].cnt;
  if (tree[node * 2].v <= sum) {
    int newsum = sum - tree[node * 2].v;
    int newcnt = cnt + tree[node * 2].cnt;
    return fnd(1 + node * 2, mid + 1, r, newsum, newcnt);
  } else {
    return fnd(node * 2, l, mid, sum, cnt);
  }
}
int main() {
  scanf("%d %d", &n, &T);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &num);
    int x = T - num;
    int FF = fnd(1, 1, R, x, 0);
    printf("%d ", i - 1 - FF);
    update(1, 1, R, num);
  }
}
