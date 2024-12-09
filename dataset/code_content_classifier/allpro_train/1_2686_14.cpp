#include <bits/stdc++.h>
using namespace std;
struct segment_tree {
  public:
    int n, ht, N;
    vector<int> dat;
    segment_tree(int sz) {
      n = sz;
      ht = 1;
      N = 1;
      while (N < n) {
        ht++;
        N <<= 1;
      }
      dat.resize(2 * N, 0);
    }
    segment_tree(vector<int> v) {
      n = v.size();
      ht = 1;
      N = 1;
      while (N < n) {
        ht++;
        N <<= 1;
      }
      dat.resize(2 * N);
      for (int i = 0; i < n; i++) {
        dat[N + i] = v[i];
      }
      for (int i = N - 1; i >= 1; i--) {
        dat[i] = dat[2 * i] + dat[2 * i + 1];
      }
    }
    void add (int i, int x) {
      i += N;
      dat[i] += x;
      i >>= 1;
      for (; i; i >>= 1) {
        dat[i] = dat[2 * i] + dat[2 * i + 1];
      }
    }
    int getSum (int l, int r, int k = 1, int L = 0, int R = -1) {
      if (R == -1) R = N;
      if (R <= l || r <= L) {
        return 0;
      } else if (l <= L && R <= r) {
        return dat[k];
      } else {
        int C = (L + R) >> 1;
        return getSum(l, r, 2 * k, L, C) + getSum(l, r, 2 * k + 1, C, R);
      }
    }
};
int main() {
  int n, q;
  cin >> n >> q;
  segment_tree sgt(n + 1);
  while (q--) {
    int c;
    cin >> c;
    if (c == 0) {
      int s, t, x;
      cin >> s >> t >> x;
      sgt.add(--s, x);
      sgt.add(t, -x);
    } else {
      int i;
      cin >> i;
      cout << sgt.getSum(0, i) << '\n';
    }
  }
  return 0;
}
