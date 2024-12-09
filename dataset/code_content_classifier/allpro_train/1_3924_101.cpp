#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 200, M = 1e7 + 200;
long long n, a, MN[M];
int32_t main() {
  scanf("%I64d %I64d", &a, &n);
  for (long long i = 1; i < N; i++)
    for (long long j = 1; i * i * j < M; j++) {
      if (!MN[i * i * j])
        MN[i * i * j] = j;
      else
        MN[i * i * j] = min(MN[i * i * j], j);
    }
  long long ans = 0;
  for (long long i = a; i < n + a; i++) ans += MN[i];
  printf("%I64d", ans);
}
