#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1000001;
long long n, l[MAXN], r[MAXN], id[MAXN], K;
bool cmp(long long i, long long j) {
  return (l[i] / K == l[j] / K)
             ? ((l[i] / K & 1) ? (r[i] < r[j]) : (r[i] > r[j]))
             : (l[i] < l[j]);
}
int main() {
  scanf("%lld", &n);
  K = 1000;
  for (long long i = 1; i <= n; i++) scanf("%lld%lld", &l[i], &r[i]), id[i] = i;
  sort(id + 1, id + 1 + n, cmp);
  for (int i = 1; i <= n; i++) printf("%lld ", id[i]);
}
