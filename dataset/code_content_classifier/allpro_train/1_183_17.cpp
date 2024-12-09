#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long mxi = 100005;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long t1 = -1, t2 = -1;
    long long fl = 0;
    int cur1, cur2;
    for (int i = 0; i < n; i++) {
      long long x, y;
      cin >> x >> y;
      if (!i) {
        t1 = max(t1, x);
        t2 = max(t2, y);
        cur1 = x;
        cur2 = y;
      }
      if (x < t1 || x < y || y < t2 || (x - cur1) < (y - cur2)) {
        fl = 1;
      }
      cur1 = x;
      cur2 = y;
      t1 = max(t1, x);
      t2 = max(t2, y);
    }
    if (fl) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
