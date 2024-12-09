#include <bits/stdc++.h>
using namespace std;
template <class n, class second>
ostream &operator<<(ostream &p, pair<n, second> x) {
  return p << "<" << x.first << ", " << x.second << ">";
}
template <class n>
auto operator<<(ostream &p, n y) ->
    typename enable_if<!is_same<n, string>::value,
                       decltype(y.begin(), p)>::type {
  int o = 0;
  p << "{";
  for (auto c : y) {
    if (o++) p << ", ";
    p << c;
  }
  return p << "}";
}
void dor() { cerr << '\n'; }
template <class n, class... second>
void dor(n p, second... y) {
  cerr << p << " ";
  dor(y...);
}
template <class n, class second>
void mini(n &p, second y) {
  if (p > y) p = y;
}
template <class n, class second>
void maxi(n &p, second y) {
  if (p < y) p = y;
}
const int MXN = 2e5 + 5;
bool have[MXN];
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); ++i) have[i] = 0;
  for (int i = (1); i <= (int)(n); ++i) {
    int a;
    scanf("%d", &a);
    a = (a + i) % n;
    if (a < 0) a += n;
    have[a] = 1;
  }
  bool ok = 1;
  for (int i = 0; i < (int)(n); ++i)
    if (have[i] == 0) ok = 0;
  puts(ok ? "YES" : "NO");
}
int main() {
  int z;
  scanf("%d", &z);
  while (z--) solve();
}
