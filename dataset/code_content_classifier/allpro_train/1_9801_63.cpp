#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, temp, q, a, b, c, k, count, sum;
  vector<long long int> v;
  cin >> q;
  while (q--) {
    cin >> k >> n >> a >> b;
    double ans = k - b * n;
    ans /= (a - b);
    if (ans == floor(ans)) ans -= 1;
    ans = floor(ans);
    if (ans >= 0)
      cout << min(n, (long long int)ans) << endl;
    else
      cout << -1 << endl;
  }
}
