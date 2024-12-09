#include <bits/stdc++.h>
using namespace std;
int tree[5000000] = {0};
int lazy[5000000] = {0};
void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff) {
  if (lazy[si] != 0) {
    tree[si] += lazy[si];
    if (ss != se) {
      lazy[si * 2 + 1] += lazy[si];
      lazy[si * 2 + 2] += lazy[si];
    }
    lazy[si] = 0;
  }
  if (ss > se || ss > ue || se < us) return;
  if (ss >= us && se <= ue) {
    tree[si] += diff;
    if (ss != se) {
      lazy[si * 2 + 1] += diff;
      lazy[si * 2 + 2] += diff;
    }
    return;
  }
  int mid = (ss + se) / 2;
  updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff);
  updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff);
  tree[si] = max(tree[si * 2 + 1], tree[si * 2 + 2]);
}
void updateRange(int n, int us, int ue, int diff) {
  updateRangeUtil(0, 0, n - 1, us, ue, diff);
}
int getSumUtil(int ss, int se, int qs, int qe, int si) {
  if (lazy[si] != 0) {
    tree[si] += lazy[si];
    if (ss != se) {
      lazy[si * 2 + 1] += lazy[si];
      lazy[si * 2 + 2] += lazy[si];
    }
    lazy[si] = 0;
  }
  if (ss > se || ss > qe || se < qs || tree[si] <= 0) return -1;
  if (ss == se) return ss;
  int mid = (ss + se) / 2;
  if (tree[2 * si + 1] + lazy[2 * si + 1] > 0) {
    return getSumUtil(ss, mid, qs, qe, 2 * si + 1);
  }
  return getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
}
int getSum(int n, int qs, int qe) {
  if (qs < 0 || qe > n - 1 || qs > qe) {
    printf("Invalid Input");
    return -1;
  }
  return getSumUtil(0, n - 1, qs, qe, 0);
}
int main() {
  std::ios::sync_with_stdio(false);
  int T;
  T = 1;
  while (T--) {
    int q, i, j, a, b, c, ans, Q;
    cin >> q;
    Q = q;
    int op[q + 1];
    while (Q--) {
      cin >> a >> b;
      if (b == 0) {
        updateRange(q, q - a, q - 1, -1);
      } else {
        cin >> c;
        op[q - a] = c;
        updateRange(q, q - a, q - 1, 1);
      }
      ans = getSum(q, 0, q - 1);
      if (ans == -1)
        cout << -1 << endl;
      else
        cout << op[ans] << endl;
    }
  }
  return 0;
}
