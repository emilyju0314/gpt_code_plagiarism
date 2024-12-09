#include <bits/stdc++.h>
using namespace std;
inline int rit() {
  int f = 0, key = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') key = -1;
  } while (ch < '0' || ch > '9');
  do {
    f = f * 10 + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  return f * key;
}
int n, k;
struct st {
  int sz, mn[10], mx[10];
  st() : sz(1) {}
  bool operator<(const st &rhs) const {
    for (int i = 0; i < (k); i++) {
      if (mx[i] > rhs.mn[i]) return false;
    }
    return true;
  }
};
set<st> s;
int32_t main(void) {
  n = rit(), k = rit();
  for (int i = 0; i < (n); i++) {
    st A;
    for (int j = 0; j < (k); j++) {
      int x;
      x = rit();
      A.mx[j] = A.mn[j] = x;
    }
    auto x = s.lower_bound(A);
    auto y = s.upper_bound(A);
    while (x != y) {
      A.sz += x->sz;
      for (int h = 0; h < (k); h++) {
        A.mn[h] = min(A.mn[h], x->mn[h]);
        A.mx[h] = max(A.mx[h], x->mx[h]);
      }
      x = s.erase(x);
    }
    s.insert(A);
    cout << s.rbegin()->sz << "\n";
  }
  return 0;
}
