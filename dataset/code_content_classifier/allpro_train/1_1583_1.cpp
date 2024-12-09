#include <bits/stdc++.h>
using namespace std;
const int maxn = 110000, maxN = 1100;
vector<int> G[maxN];
int n, N, m;
struct Tcxx {
  int v, x;
  Tcxx(int _v = 0, int _x = 0) { v = _v, x = _x; }
} A[maxN];
long long C(int n, int m) {
  long long Fc = 1;
  int i;
  if (n < m) return 0;
  for (i = n - m + 1; i <= n; ++i) Fc *= i;
  for (i = 1; i <= m; ++i) Fc /= i;
  return Fc;
}
namespace Ninit {
map<int, int> Mp;
int B[maxn];
bool islucky(int x) {
  for (; x; x /= 10)
    if (x % 10 != 4 && x % 10 != 7) return false;
  return true;
}
void init() {
  int i;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d", B + i);
    if (islucky(B[i])) {
      if (!Mp.count(B[i])) Mp[B[i]] = m++;
      A[++N] = Tcxx(Mp[B[i]], i), G[Mp[B[i]]].push_back(i);
    }
  }
  A[0].x = 0, A[N + 1].x = n + 1;
}
}  // namespace Ninit
namespace Nsolve {
long long ans;
bool U[maxN];
set<int> T;
void solve() {
  set<int>::iterator p, q, t;
  vector<int>::iterator k;
  int i, j;
  long long res;
  for (j = 0, i = 1; i <= n; ++i) {
    for (; A[j + 1].x <= i; ++j)
      ;
    ans += C(i + 1, 3) - C(A[j].x + 1, 3);
  }
  for (i = 1; i <= N; ++i) {
    memset(U, 0, sizeof U);
    T.clear(), T.insert(0);
    res = C(A[i].x + 1, 3) - C(A[i - 1].x + 1, 3);
    for (j = i; j <= N; ++j) {
      if (!U[A[j].v]) {
        U[A[j].v] = true;
        for (k = G[A[j].v].begin(); k != G[A[j].v].end(); ++k)
          if (*k < A[i].x) {
            T.insert(*k), q = t = p = T.find(*k), ++t, --q;
            if (t == T.end())
              res += (A[i].x - A[i - 1].x) * C(*p - *q, 2) +
                     (C(A[i].x - *p + 1, 3) - C(A[i - 1].x - *p + 1, 3)) -
                     (C(A[i].x - *q + 1, 3) - C(A[i - 1].x - *q + 1, 3));
            else
              res += (A[i].x - A[i - 1].x) *
                     (C(*t - *p, 2) + C(*p - *q, 2) - C(*t - *q, 2));
          }
      }
      ans += res * (A[j + 1].x - A[j].x);
    }
  }
  cout << ans << endl;
}
}  // namespace Nsolve
int main() {
  Ninit::init();
  Nsolve::solve();
  return 0;
}
