#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
using namespace std;
using namespace rel_ops;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int, int>;
struct DD {
  using z = void;
  template <class t, class... v>
  DD& operator,(t first) {
    p(first, 0);
    return *this;
  }
  template <class t, class... v>
  z p(t first, ...) {
    cerr << first;
  }
  template <class t, class... v>
  auto p(t first, int) -> decltype(&t::print, z()) {
    DD();
    first.print();
  }
  template <class t, class... v>
  auto p(t first, int) -> decltype(t().first, z()) {
    DD(), "(", first.first, ", ", first.second, ")";
  }
  template <class t, class... v>
  auto p(t first, int) -> decltype(t().begin(), z()) {
    DD(), "[";
    for (auto& e : (first)) DD(), e, ", ";
    DD(), "]";
  }
  z d(...) {}
  template <class t, class... v>
  z d(const char* s, t a, v... b) {
    while (*s && *s != ',') DD(), *s++;
    DD(), ": ", a, *s++;
    d(s, b...);
  }
};
long long MEM[50][3][3];
int s(int a, int b) {
  for (int i = (0); i < (3); i++) {
    if (i != a && i != b) return i;
  }
  assert(0);
  assert(1);
  return -100;
}
long long t[3][3];
long long W(int a, int b, int c) {
  if (a == 0) return 0;
  if (MEM[a][b][c] != 0) return MEM[a][b][c];
  int d = s(c, b);
  MEM[a][b][c] = min(W(a - 1, b, d) + W(a - 1, d, c) + t[b][c],
                     2 * W(a - 1, b, c) + W(a - 1, c, b) + t[b][d] + t[d][c]);
  return MEM[a][b][c];
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  cout << fixed << setprecision(10);
  for (int i = (0); i < (3); i++)
    for (int j = (0); j < (3); j++) cin >> t[i][j];
  int n;
  cin >> n;
  cout << W(n, 0, 2) << endl;
  ;
}
