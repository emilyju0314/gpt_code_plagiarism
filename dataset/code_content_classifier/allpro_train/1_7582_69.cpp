#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
struct obj {
  int p, a = 0, i;
  bool operator<(const obj &s) const {
    if (p != s.p) return p > s.p;
    if (a != s.a) return a < s.a;
    return i < s.i;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<obj> pc(n), sk(m);
  for (int i = (0); i < (n); i++) cin >> pc[i].p, pc[i].i = i;
  for (int i = (0); i < (m); i++) cin >> sk[i].p, sk[i].i = i;
  vector<int> a(m), b(n);
  int c = 0, u = 0;
  sort(begin(pc), end(pc));
  set<obj> q(begin(sk), end(sk));
  for (const auto &x : pc) {
    if (q.empty()) break;
    auto y = *begin(q);
    while (y.p > x.p) {
      q.erase(begin(q));
      y.p = (y.p + 1) / 2;
      y.a++;
      q.insert(y);
      y = *begin(q);
    }
    if (y.p < x.p) continue;
    q.erase(begin(q));
    c++, u += y.a;
    a[y.i] = y.a, b[x.i] = y.i + 1;
  }
  cout << c << " " << u << "\n";
  for (int i = (0); i < (m); i++) cout << a[i] << " \n"[i + 1 == m];
  for (int i = (0); i < (n); i++) cout << b[i] << " \n"[i + 1 == n];
}
