#include <bits/stdc++.h>
using namespace std;
long long INF = 1e9 + 7;
long long MOD = 998244353;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, k, s;
    cin >> s >> n >> k;
    if (s == k) {
      cout << "YES\n";
    } else if (k > s) {
      cout << "NO\n";
    } else {
      long long posa = s + k;
      long long l = s - k + 1, r = s;
      long long siz = r - l + 1;
      long long a = 0, b = 0;
      long long num = (s / k) * k;
      b = r - num + 1;
      a = siz - b;
      if ((s / k) % 2 == 1) {
        posa -= b;
      } else {
        posa -= a;
      }
      if ((2 * n + 1) > posa) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}
