#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int maxn = 1e5 + 10, MOD = 1e9 + 7;
int N;
int A[maxn];
vector<int> D;
long long Pow(long long, int, int);
int work(int);
int main() {
  while (~scanf("%d", &N)) {
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    sort(A, A + N);
    int now, ans = 0;
    for (int tmax = A[N - 1]; tmax >= 1; tmax--) {
      now = work(tmax);
      ans = (ans + now) % MOD;
    }
    ans = (ans + MOD) % MOD;
    printf("%d\n", ans);
  }
  return 0;
}
int work(int tmax) {
  if (tmax == 1) return 1;
  D.clear();
  int lim = sqrt(tmax);
  for (int i = 1; i <= lim; i++)
    if (tmax % i == 0) {
      if (i * i == tmax)
        D.push_back(i);
      else
        D.push_back(i), D.push_back(tmax / i);
    }
  sort(D.begin(), D.end());
  int res = 1, now, tim, cnt = 0;
  for (int i = 2; i <= (int)D.size(); i++) {
    now = D[i - 1];
    tim = lower_bound(A, A + N, now) - A;
    res = (long long)res * Pow(i - 1, tim - cnt, MOD) % MOD;
    cnt = tim;
  }
  int left = N - cnt;
  res = (long long)res *
        (Pow(D.size(), left, MOD) - Pow(D.size() - 1, left, MOD)) % MOD;
  return res;
}
long long Pow(long long x, int n, int p) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}
