#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 200000 + 10;
const long long inf = ~0ULL >> 1;
int N, M;
long long sum = 0;
struct PII {
  int fir, sec;
  PII() {}
  PII(int _f, int _s) { fir = _f, sec = _s; }
  bool operator<(const PII &p) const {
    return (fir > p.fir) || (fir == p.fir && sec < p.sec);
  }
} p[N_MAX];
namespace Ninit {
void init() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; ++i) {
    scanf("%d%d", &p[i].fir, &p[i].sec);
    sum += p[i].fir;
  }
}
}  // namespace Ninit
namespace Nwork {
bool used[N_MAX];
long long min(long long a, long long b) { return a < b ? a : b; }
bool cmp(PII a, PII b) { return a.sec < b.sec; }
long long solve(int scr) {
  if (scr > N) return inf;
  int pts = 0, tot = 0;
  long long ret = 0;
  memset(used, 0, sizeof(used));
  for (int i = 1; i <= N; ++i)
    if (p[i].fir >= scr - 1) ++tot;
  tot -= M - 1;
  for (int i = 1; i <= N && pts < tot; ++i)
    if (p[i].fir == scr || p[i].fir == scr - 1) {
      ret += p[i].sec;
      used[i] = 1;
      ++pts;
    }
  for (int i = 1; i <= N && pts < scr; ++i)
    if (!used[i]) {
      ret += p[i].sec;
      used[i] = 1;
      ++pts;
    }
  return ret;
}
void main() {
  sort(p + 1, p + N + 1);
  long long ret = inf;
  int scr = p[M].fir;
  sort(p + 1, p + N + 1, cmp);
  for (int i = 0; i <= 2; ++i) ret = min(ret, solve(scr + i));
  printf("%I64d\n", ret == inf ? -1 : ret);
}
}  // namespace Nwork
int main() {
  Ninit::init();
  Nwork::main();
  return 0;
}
