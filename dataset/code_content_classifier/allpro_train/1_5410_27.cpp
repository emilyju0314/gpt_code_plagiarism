#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100005];
int b[100005];
bool judge(long long M) {
  for (int i = 0; i < n; i++) b[i] = a[i];
  int p;
  for (p = n - 1; p >= 0; p--)
    if (b[p]) break;
  bool flag = true;
  int rest = m;
  long long cur = M;
  if (p >= 0 && M <= p + 1) return false;
  while (p >= 0) {
    while (cur && p >= 0) {
      if (cur == M) cur -= (p + 1);
      long long tmp = min((long long)b[p], cur);
      cur -= tmp;
      b[p] -= tmp;
      if (b[p] == 0)
        while (p >= 0 && b[p] == 0) p--;
    }
    rest--;
    cur = M;
    if (rest < 0) {
      flag = false;
      break;
    }
  }
  return flag;
}
int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    long long L = 0, R = 0;
    for (int i = 0; i < n; i++) R += a[i];
    R += n;
    while (L < R) {
      long long M = L + (R - L) / 2;
      if (judge(M))
        R = M;
      else
        L = M + 1;
    }
    cout << L << "\n";
  }
  return 0;
}
