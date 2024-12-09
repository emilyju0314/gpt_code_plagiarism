#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long n;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  long long c;
  vector<long long> t;
  for (long long i = 1; i <= n; i++) {
    cin >> c;
    t.push_back(c);
  }
  long long p1 = 0, a = 0, b = 0;
  long long p2 = n - 1;
  long long pre1 = t[0];
  long long pre2 = t[n - 1];
  while (p1 <= p2) {
    if (pre1 < pre2) {
      p1++;
      a++;
      pre1 += t[p1];
    } else if (pre1 > pre2) {
      p2--;
      b++;
      pre2 += t[p2];
    } else {
      if (p1 != p2) {
        a++;
        b++;
        p1++;
        p2--;
        pre1 += t[p1];
        pre2 += t[p2];
      } else {
        a++;
        p1++;
        p2--;
      }
    }
  }
  cout << a << " " << b;
  return 0;
}
