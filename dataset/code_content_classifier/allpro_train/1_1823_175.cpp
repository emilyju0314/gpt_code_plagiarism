#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e9;
int solve(int x) {
  int ans = 1;
  while (x > 0) {
    if (x % 2) ans *= 2;
    x /= 2;
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    printf("%d\n", solve(x));
  }
  return 0;
}
