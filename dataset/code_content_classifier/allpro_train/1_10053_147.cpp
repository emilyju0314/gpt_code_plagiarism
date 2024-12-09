#include <bits/stdc++.h>
using namespace std;
long long mod(long long a) {
  long long c = a % (long long)(1E9 + 7);
  if (c >= 0)
    return c;
  else
    return c + (long long)(1E9 + 7);
}
long long inf = (long long)1E12;
long long max(long long a, long long b) {
  if (a < b)
    return b;
  else
    return a;
}
long long min(long long a, long long b) {
  if (a > b)
    return b;
  else
    return a;
}
void Max(long long* pos, long long val) { *pos = max(*pos, val); }
void Min(long long* pos, long long val) { *pos = min(*pos, val); }
void Add(long long* pos, long long val) { *pos = mod(*pos + val); }
const long double EPS = 1E-8;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    cout << l << " " << 2 * l << endl;
  }
  return 0;
}
