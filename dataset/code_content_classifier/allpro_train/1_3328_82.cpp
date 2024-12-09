#include <bits/stdc++.h>
using namespace std;
vector<long long> G;
long long a, b, c;
long long ha(long long x) {
  long long sum = 1;
  for (long long i = 0; i < a; i++) sum *= x;
  return b * sum + c;
}
int main() {
  scanf("%I64d%I64d%I64d", &a, &b, &c);
  for (long long i = 1; i <= 81; i++) {
    long long p = ha(i);
    if (p >= 1000000000)
      continue;
    else if (p < 0)
      continue;
    long long k = p;
    long long sum = 0;
    while (k) {
      sum += (k % 10);
      k /= 10;
    }
    if (sum == i) G.push_back(p);
  }
  printf("%d\n", G.size());
  for (int i = 0; i < G.size(); i++) printf("%I64d ", G[i]);
}
