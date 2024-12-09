#include <bits/stdc++.h>
using namespace std;
const int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int n, a[15];
long long mini = 1e18, inf = 2e18;
void ck(int k) {
  reverse(a, a + k);
  long long sum = 1;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < a[i] - 1; j++) {
      if (inf / p[i] < sum) return;
      sum *= p[i];
    }
  }
  if (sum < mini) mini = sum;
}
void dfs(int d, int l, int k) {
  if (d == 1) {
    ck(k);
  }
  for (int i = l; i <= n; i++) {
    if (d % i == 0) {
      a[k] = i;
      dfs(d / i, i, k + 1);
    }
  }
}
int main() {
  cin >> n;
  dfs(n, 2, 0);
  cout << mini;
  return 0;
}
