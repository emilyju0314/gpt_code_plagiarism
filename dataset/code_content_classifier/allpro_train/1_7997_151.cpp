#include <bits/stdc++.h>
using namespace std;
const int max_n = 2e5 + 25;
struct Fenwick {
  struct node {
    long long add, sum;
  } tree[max_n];
  void update(long long idx, long long val) {
    for (long long i = idx; i < max_n; i += i & -i) {
      tree[i].sum += val * (i - idx + 1);
      tree[i].add += val;
    }
  }
  long long sum(long long idx) {
    long long ret = tree[idx].sum;
    for (long long i = idx - (idx & -idx); i; i -= i & -i)
      ret += tree[i].sum + tree[i].add * (idx - i);
    return ret;
  }
} BIT;
long long q, t, pos, val, n = 1;
int main() {
  for (cin >> q; q--;) {
    cin >> t;
    if (t == 1) {
      cin >> pos >> val;
      BIT.update(1, val);
      BIT.update(pos + 1, -val);
    } else if (t == 2) {
      cin >> val;
      n++;
      BIT.update(n, val);
      BIT.update(n + 1, -val);
    } else {
      val = BIT.sum(n) - BIT.sum(n - 1);
      BIT.update(n, -val);
      BIT.update(n + 1, +val);
      n--;
    }
    cout << fixed << setprecision(10) << (1. * BIT.sum(n) - BIT.sum(0)) / n
         << endl;
  }
  return 0;
}
