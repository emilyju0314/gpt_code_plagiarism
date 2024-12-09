#include <bits/stdc++.h>
using namespace std;
long long n, t[100001], ans;
double w;
long long lowbit(long long x) { return x & (-x); }
struct rua {
  double x, v;
  long long id;
} _[100001];
void change(long long x) {
  while (x <= n) t[x]++, x += lowbit(x);
}
int sum(long long k) {
  long long res = 0;
  while (k > 0) res += t[k], k -= lowbit(k);
  return res;
}
bool cmp(rua a, rua b) { return fabs(a.x * b.v) < fabs(a.v * b.x); }
int main() {
  scanf("%I64d%lf", &n, &w), w += 1e-6;
  for (long long i = 1; i <= n; i++)
    scanf("%lf%lf", &_[i].x, &_[i].v), _[i].v -= w;
  sort(_ + 1, _ + n + 1, cmp);
  for (long long i = 1; i <= n; i++) _[i].id = i, _[i].v += 2 * w;
  sort(_ + 1, _ + n + 1, cmp);
  for (long long i = 1; i <= n; i++)
    ans += i - 1 - sum(_[i].id), change(_[i].id);
  return printf("%I64d\n", ans), 0;
}
