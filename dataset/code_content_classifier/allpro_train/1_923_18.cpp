#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int inf = 50000000;
const int maxn = 100010;
const int maxk = 350;
int grundy[maxn], cut[maxn], prefxor[maxn];
int possible(int n, int k) {
  int temp = 2 * n;
  if (temp % k) return 0;
  temp /= k;
  temp = temp - 1 + k;
  if (temp <= 0 || temp & 1)
    return 0;
  else {
    int lst = (temp / 2) - (k - 1);
    if (lst <= 0) return 0;
    return temp / 2;
  }
}
void precompute() {
  int i, j, second;
  for (i = 1; i < maxn; i++) {
    set<int> mset;
    cut[i] = inf;
    for (j = 2; j <= min(maxk, i); j++) {
      second = possible(i, j);
      if (second) {
        int x = prefxor[second] ^ prefxor[second - j];
        mset.insert(x);
        if (!x) cut[i] = min(cut[i], j);
      }
    }
    int ret = 0;
    while (mset.find(ret) != mset.end()) ret++;
    grundy[i] = ret;
    prefxor[i] = prefxor[i - 1] ^ ret;
  }
}
int main() {
  precompute();
  int n;
  scanf("%d", &n);
  if (grundy[n]) {
    printf("%d\n", cut[n]);
  } else {
    printf("-1\n");
  }
  return 0;
}
