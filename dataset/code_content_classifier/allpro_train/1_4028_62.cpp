#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, cf, cm, k, kj;
long long A, m, Max = -1;
long long a[maxn], sum[maxn];
struct node {
  long long x;
  int Loc;
  bool operator<(const node &a) const { return x < a.x; }
} b[maxn];
int main() {
  scanf("%d%lld%d%d%lld", &n, &A, &cf, &cm, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    b[i] = (node){A - a[i], i};
  }
  sort(b + 1, b + n + 1);
  for (int i = n - 1; i; --i)
    sum[i] = sum[i + 1] + (b[i + 1].x - b[i].x) * (n - i);
  sum[0] = sum[1] + b[1].x * n;
  int j = n;
  while (j && sum[j - 1] <= m) --j;
  long long t = 0;
  for (int i = 0; i <= n; ++i) {
    t += b[i].x;
    if (t > m) break;
    while (j <= n && m - t < sum[j]) ++j;
    j = max(j, i + 1);
    long long temp = i * cf;
    if (j <= n)
      temp += (A - b[j].x + min((m - t - sum[j]) / (n - j + 1), b[j].x)) * cm;
    else
      temp += A * cm;
    if (temp > Max) {
      Max = temp;
      k = i;
      kj = j;
    }
  }
  for (int i = 1; i <= k; ++i) {
    a[b[i].Loc] = A;
    m -= b[i].x;
  }
  for (int i = kj; i <= n; ++i) a[b[i].Loc] = A - b[kj].x;
  m -= sum[kj];
  if (kj <= n) {
    for (int i = kj; i <= n; ++i) a[b[i].Loc] += min(m / (n - kj + 1), b[kj].x);
  }
  printf("%lld\n", Max);
  for (int i = 1; i <= n; ++i) printf("%lld ", a[i]);
  return 0;
}
