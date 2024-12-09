#include <bits/stdc++.h>
using namespace std;
template <int Sx, int Sy>
struct FenwickTree2D {
  map<int, int> arr[Sx + 1];
  int szx, szy;
  FenwickTree2D() : szx(Sx), szy(Sy) {}
  void add(int i, int j, int val) {
    for (int ii = i; ii <= szx; ii += (ii & -ii)) {
      for (int jj = j; jj <= szy; jj += (jj & -jj)) {
        arr[ii][jj] += val;
      }
    }
  }
  long long query(int i, int j) {
    long long sum = 0;
    int ii = i;
    for (int ii = i; ii; ii -= (ii & -ii)) {
      for (int jj = j; jj; jj -= (jj & -jj)) {
        if (arr[ii].count(jj)) sum += arr[ii][jj];
      }
    }
    return sum;
  }
  long long query(int i1, int j1, int i2, int j2) {
    return query(i2, j2) - query(i1 - 1, j2) - query(i2, j1 - 1) +
           query(i1 - 1, j1 - 1);
  }
};
const int N = 100000 + 10;
int n, m;
int A[N];
int pre[N];
set<int> shape_pos[N];
FenwickTree2D<N, N> ft;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  ft.szx = n;
  ft.szy = n;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  for (int i = 1; i <= n; ++i) {
    shape_pos[A[i]].insert(i);
    if (pre[A[i]]) {
      ft.add(pre[A[i]], i, i - pre[A[i]]);
    }
    pre[A[i]] = i;
  }
  int t, a, b;
  for (int i = 0; i != m; ++i) {
    cin >> t >> a >> b;
    if (t == 1) {
      auto it = shape_pos[A[a]].find(a);
      auto itn = next(it, 1);
      auto itp = prev(it, 1);
      if (itn != shape_pos[A[a]].end()) ft.add(*it, *itn, -(*itn - *it));
      if (it != shape_pos[A[a]].begin()) ft.add(*itp, *it, -(*it - *itp));
      if (itn != shape_pos[A[a]].end() && it != shape_pos[A[a]].begin())
        ft.add(*itp, *itn, *itn - *itp);
      shape_pos[A[a]].erase(it);
      A[a] = b;
      shape_pos[A[a]].insert(a);
      it = shape_pos[A[a]].find(a);
      itn = next(it, 1);
      itp = prev(it, 1);
      if (itn != shape_pos[A[a]].end()) ft.add(*it, *itn, *itn - *it);
      if (it != shape_pos[A[a]].begin()) ft.add(*itp, *it, *it - *itp);
      if (itn != shape_pos[A[a]].end() && it != shape_pos[A[a]].begin())
        ft.add(*itp, *itn, -(*itn - *itp));
    } else {
      cout << ft.query(a, a, b, b) << '\n';
    }
  }
  return 0;
}
