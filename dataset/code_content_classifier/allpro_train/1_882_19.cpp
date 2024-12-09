#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  long long res = 1;
  a = a % 1000000007;
  while (b) {
    if (b & 1) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b /= 2;
  }
  return res;
}
long long invmod(long long a) { return power(a, 1000000007 - 2); }
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long total = a * (a + 1) / 2;
    long long zeros = a - b;
    long long group = zeros / (b + 1);
    long long ans = total - (b + 1) * group * (group + 1) / 2 -
                    zeros % (b + 1) * (group + 1);
    cout << ans << endl;
  }
  return 0;
}
