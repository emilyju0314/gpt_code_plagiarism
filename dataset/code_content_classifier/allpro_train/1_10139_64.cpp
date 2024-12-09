#include <bits/stdc++.h>
using namespace std;
const int N = (int)3e5 + 7;
int n, k;
int x[N], y[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> y[i];
  }
  long long f, s;
  f = s = 0;
  for (int i = 1; i <= n; i++) {
    f = max(0LL, x[i] + f - y[i] * 1LL * k);
    s = max(0LL, y[i] + s - x[i] * 1LL * k);
    if (f > k || s > k) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
}
