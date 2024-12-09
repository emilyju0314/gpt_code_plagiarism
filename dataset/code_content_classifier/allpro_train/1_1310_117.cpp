#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 1;
const int INF_INT = 1e9 + 100;
const long long POLTOS = 50;
const long long SOTKA = 100;
const long long P = 1e9 + 7;
const long double eps = 1e-9;
const int base = 257;
const long long M = 500;
const long long MAXN = 1e6 + 1;
const long long MAXN1 = 2 * 1e2;
const long long N = 20;
const long double pi = acos(-1);
const long long mod = 1e9 + 7;
const int S_M = 20;
const long long LEN = 96;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long ans = 0;
  long long first = 1;
  while (n > 0) {
    ans++;
    n -= first;
    first <<= 1;
  }
  cout << ans << endl;
  return 0;
}
