#include <bits/stdc++.h>
using namespace std;
const int DIM = 1e6 + 7;
int v[DIM];
int val_min[DIM * 4];
int lazy[DIM * 4];
int nr_ok[DIM * 4];
void pushup(int pos) {
  nr_ok[pos] = 0;
  val_min[pos] = min(val_min[pos * 2], val_min[pos * 2 + 1]);
  if (val_min[pos * 2] == val_min[pos]) nr_ok[pos] += nr_ok[pos * 2];
  if (val_min[pos * 2 + 1] == val_min[pos]) nr_ok[pos] += nr_ok[pos * 2 + 1];
  val_min[pos] += lazy[pos];
}
void update(int pos, int l, int r, int x, int y, int val) {
  if (x <= l && r <= y) {
    lazy[pos] += val;
    val_min[pos] += val;
    return;
  }
  int mid = (l + r) / 2;
  if (x <= mid) update(pos * 2, l, mid, x, y, val);
  if (y > mid) update(pos * 2 + 1, mid + 1, r, x, y, val);
  pushup(pos);
}
void update(int pos, int l, int r, int x, int val) {
  if (l == r) {
    nr_ok[pos] = val;
    return;
  }
  int mid = (l + r) / 2;
  if (x <= mid)
    update(pos * 2, l, mid, x, val);
  else
    update(pos * 2 + 1, mid + 1, r, x, val);
  pushup(pos);
}
void change(int x, int y, int val) {
  if (x > y) swap(x, y);
  update(1, 0, v[0] - 1, x, y - 1, val);
}
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> v[i];
  v[0] = DIM - 6;
  for (int i = 0; i <= n; i++) change(v[i], v[i + 1], 1);
  for (int i = 1; i <= n; i++) update(1, 0, v[0] - 1, v[i], 1);
  while (q--) {
    int x;
    cin >> x;
    change(v[x - 1], v[x], -1);
    change(v[x], v[x + 1], -1);
    update(1, 0, v[0] - 1, v[x], 0);
    cin >> v[x];
    change(v[x - 1], v[x], 1);
    change(v[x], v[x + 1], 1);
    update(1, 0, v[0] - 1, v[x], 1);
    cout << nr_ok[1] << '\n';
  }
}
