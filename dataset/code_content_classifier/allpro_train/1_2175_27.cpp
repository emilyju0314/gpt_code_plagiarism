#include <bits/stdc++.h>
using namespace std;
const int N = 30 + 5;
const int K = 100000 + 5;
map<int, int> cnt[N];
int n, k, a;
long long A, B;
int p[N];
long long solve(int l, int b) {
  if (cnt[l][b] == 0) {
    return A;
  }
  if (l == 0) {
    return B * cnt[l][b];
  }
  return min(B * cnt[l][b] * p[l],
             solve(l - 1, b * 2) + solve(l - 1, b * 2 + 1));
}
int main() {
  scanf("%d %d %lld %lld", &n, &k, &A, &B);
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] * 2;
  }
  for (int i = 1; i <= k; i++) {
    scanf("%d", &a);
    a--;
    for (int l = 0; l <= n; l++) {
      cnt[l][a]++;
      a >>= 1;
    }
  }
  printf("%lld\n", solve(n, 0));
  return 0;
}
