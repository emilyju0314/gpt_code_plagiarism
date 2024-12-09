#include <bits/stdc++.h>
using namespace std;
const int maxn = 5010;
const int maxm = 1000010;
int A[maxn], f[maxm], n, m, k, kk, vis[maxm], vnt;
bool Check(int x) {
  vnt++;
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (vis[A[i] % x] == vnt) {
      res++;
      if (res > k) return 0;
    }
    vis[A[i] % x] = vnt;
  }
  return 1;
}
int main() {
  scanf("%d%d", &n, &k);
  kk = k * (k + 1) / 2;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
    m = max(m, A[i]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      f[abs(A[i] - A[j])]++;
    }
  }
  for (int i = n - k;; ++i) {
    for (int j = i * 2; j < m; j += i) {
      f[i] += f[j];
    }
    if (f[i] > kk) continue;
    if (Check(i)) {
      printf("%d", i);
      break;
    }
  }
  return 0;
}
