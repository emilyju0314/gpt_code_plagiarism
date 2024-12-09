#include <bits/stdc++.h>
using namespace std;
const long long N = 100000 + 5;
long long p[N], m[N], sum[N], rest[N], pc[N], e[N];
vector<long long> d[N];
long long n;
long long lb(long long k) { return k & -k; }
void add(long long k, long long v) {
  while (k <= n) {
    e[k] += v;
    k += lb(k);
  }
}
long long getsum(long long k) {
  long long res = 0;
  while (k >= 1) {
    res += e[k];
    k -= lb(k);
  }
  return res;
}
long long bs(long long pile) {
  long long beg = 1, en = n, mid;
  while (beg <= en) {
    mid = (beg + en) / 2;
    if (sum[mid] < pile)
      beg = mid + 1;
    else if (sum[mid] > pile)
      en = mid - 1;
    else
      return mid;
  }
  return beg;
}
int main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) scanf("%lld", &p[i]);
  sum[0] = 0;
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &m[i]);
    pc[i] = p[i] + sum[i - 1];
    sum[i] = sum[i - 1] + m[i];
  }
  for (long long i = 1; i <= n; i++) {
    add(i, 1);
  }
  for (long long i = 1; i <= n; i++) {
    long long pos = bs(pc[i]);
    rest[i] = pc[i] - sum[pos - 1];
    if (pos <= n) {
      d[pos].push_back(i);
      add(pos, -1);
    }
  }
  long long melt;
  for (long long i = 1; i <= n; i++) {
    melt = 0;
    long long siz = d[i].size();
    for (long long j = 0; j < siz; j++) {
      long long tmp = d[i][j];
      melt += rest[tmp];
    }
    melt += getsum(i) * m[i];
    printf("%lld", melt);
    if (i == n)
      printf("\n");
    else
      printf(" ");
  }
}
