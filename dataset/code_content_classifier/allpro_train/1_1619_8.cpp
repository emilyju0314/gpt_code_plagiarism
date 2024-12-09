#include <bits/stdc++.h>
const int MAXN = 1000000 + 10;
long long P, K;
long long S[MAXN];
long long ans;
int main() {
  register int i;
  scanf("%I64d%I64d", &P, &K);
  while (P) P -= S[++ans] = (P % K + K) % K, P /= -K;
  printf("%I64d\n", ans);
  for (i = 1; i <= ans; ++i) printf("%I64d ", S[i]);
  return 0;
}
