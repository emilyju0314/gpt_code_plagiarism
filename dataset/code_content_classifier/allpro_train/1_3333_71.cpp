#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
const int INF = 1000000007;
int a[] = {0, 1, 0, 1, 2};
int b[] = {0, 1, 2};
int n, k, g[N], ans = 0;
int grundy(int n) {
  if (k & 1) {
    if (n < 5) return a[n];
    if (n & 1) return 0;
    return (grundy(n / 2) == 1 ? 2 : 1);
  } else {
    if (n < 3) return b[n];
    return !(n % 2);
  }
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    ans ^= grundy(x);
  }
  cout << (ans ? "Kevin" : "Nicky") << endl;
}
