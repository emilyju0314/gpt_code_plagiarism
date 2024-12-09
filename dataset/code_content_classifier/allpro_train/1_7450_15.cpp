#include <bits/stdc++.h>
using namespace std;
const int maxn = 1;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  long long n;
  cin >> n;
  long long o, d = sqrt(n) + 3;
  for (o = 2; o <= d; o++)
    if (o < n and n % o == 0) break;
  d = o;
  while (d < n) d *= o;
  if (d == o or n % o) return cout << "NO" << endl, 0;
  long long a = 1, b, nt = n;
  while (n % o == 0) {
    n /= o;
    a *= o;
  }
  b = n;
  n = nt;
  if (a > b) swap(a, b);
  for (long long i = 1; i * b < n; i++)
    if ((n - 1 - i * b) % a == 0) {
      cout << "YES" << endl << 2 << endl;
      cout << i << ' ' << a << endl;
      cout << (n - 1 - i * b) / a << ' ' << b << endl;
      return 0;
    }
  cout << "NO" << endl;
  return 0;
}
