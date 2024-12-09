#include <bits/stdc++.h>
using namespace std;
int a[400005];
int r[400005];
int MaxVal;
int tree[400005];
int read(int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}
void update(int idx, int val) {
  while (idx <= MaxVal) {
    tree[idx] += val;
    idx += (idx & -idx);
  }
}
int Id[400005];
int n;
void up(int v) {
  if (!v) return;
  if (v == n) return;
  int c;
  c = read(v) - read(v - 1);
  update(v, -c);
  if (Id[v] > Id[v + 1]) {
    update(v, +1);
  }
}
int main() {
  int i, j, k, q, c, t, x, y;
  cin >> n;
  MaxVal = n + 2;
  for (i = (1); i <= (n); i++) {
    cin >> a[i];
    Id[a[i]] = i;
  }
  for (i = (1); i <= (n - 1); i++) {
    if (Id[i] > Id[i + 1]) {
      update(i, +1);
    }
  }
  cin >> q;
  for (k = (1); k <= (q); k++) {
    cin >> t;
    cin >> x >> y;
    if (t == 1) {
      c = 1 + read(y - 1) - read(x - 1);
      cout << c << endl;
    } else {
      swap(Id[a[x]], Id[a[y]]);
      swap(a[x], a[y]);
      up(a[x]);
      up(a[x] - 1);
      up(a[y]);
      up(a[y] - 1);
    }
  }
}
