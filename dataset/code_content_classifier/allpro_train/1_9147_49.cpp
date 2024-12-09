#include <bits/stdc++.h>
using namespace std;
int A[3010], N;
struct Node {
  int mx, p;
  Node() { p = mx = 0; }
  Node(int pos) {
    p = pos;
    mx = A[p];
  }
};
Node st[12010];
Node join(Node p1, Node p2) { return p1.mx > p2.mx ? p1 : p2; }
void create(int n = 1, int l = 0, int r = N) {
  if (l == r)
    st[n] = Node(l);
  else {
    int m = (l + r) / 2;
    create(2 * n, l, m);
    create(2 * n + 1, m + 1, r);
    st[n] = join(st[2 * n], st[2 * n + 1]);
  }
}
Node query(int x, int y, int n = 1, int l = 0, int r = N) {
  if (x <= l && r <= y)
    return st[n];
  else {
    int m = (l + r) / 2;
    if (y <= m) return query(x, y, 2 * n, l, m);
    if (x > m) return query(x, y, 2 * n + 1, m + 1, r);
    return join(query(x, y, 2 * n, l, m), query(x, y, 2 * n + 1, m + 1, r));
  }
}
int main() {
  int n;
  cin >> n;
  N = n - 1;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  A[N] = a[N].first;
  for (int i = 0; i + 1 < n; i++) A[i] = a[i].first - a[i + 1].first;
  create();
  int m1 = -1, m2, m3;
  int i1, i2, i3;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int s1 = i + 1, s2 = j - i;
      if (s1 < s2) swap(s1, s2);
      if (s2 * 2 < s1) continue;
      s2 *= 2, s1 = (s1 + 1) / 2;
      if (s1 > s2 || j + s1 >= n) continue;
      Node Q = query(j + s1, min(n - 1, j + s2));
      if (A[i] > m1) m1 = A[i], m2 = -1;
      if (A[i] == m1) {
        if (A[j] > m2) m2 = A[j], m3 = -1;
        if (A[j] == m2) {
          if (Q.mx > m3) m3 = Q.mx, i1 = i, i2 = j, i3 = Q.p;
        }
      }
    }
  }
  for (int i = 0; i <= i1; i++) A[i] = 1;
  for (int i = i1 + 1; i <= i2; i++) A[i] = 2;
  for (int i = i2 + 1; i <= i3; i++) A[i] = 3;
  for (int i = i3 + 1; i < n; i++) A[i] = -1;
  vector<int> anw(n);
  for (int i = 0; i < n; i++) anw[a[i].second] = A[i];
  for (int i = 0; i < n; i++) {
    if (i) cout << ' ';
    cout << anw[i];
  }
  cout << endl;
}
