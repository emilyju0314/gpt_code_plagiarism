#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long lcm(long long a, long long b) { return (a * (b / gcd(a, b))); }
int a[100010];
int main() {
  long long n, k, x = 1, t1, t2, tmp;
  cin >> n >> k;
  vector<long long> ans(n);
  t1 = 1;
  t2 = t1 + k;
  tmp = k;
  for (int i = 0; i < int(n); ++i) {
    if (i % 2 == 0) {
      a[t1] = 1;
      cout << t1++ << " ";
    } else {
      a[t2] = 1;
      cout << t2-- << " ";
    }
    if (tmp == 0) {
      for (int i = int(1); i < int(n + 1); ++i)
        if (!a[i]) cout << i << " ";
      break;
    } else
      tmp--;
  }
  return 0;
}
