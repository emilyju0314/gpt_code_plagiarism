#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long int poww(long long int b, long long int e) {
  if (e == 0)
    return 1;
  else if (e % 2 == 0) {
    long long int a = pow(b, e / 2);
    return a * a;
  } else {
    long long int a = pow(b, e / 2);
    return b * a * a;
  }
}
long long int powm(long long int x, long long int y,
                   long long int m = 1000000007) {
  x = x % m;
  long long int res = 1;
  while (y) {
    if (y & 1) res = res * x;
    res %= m;
    y = y >> 1;
    x = x * x;
    x %= m;
  }
  return res;
}
long long int modInverse(long long int a, long long int m = 1000000007) {
  return powm(a, m - 2, m);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int Testcases;
  cin >> Testcases;
  while (Testcases--) {
    long long int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    long long int diff = b - a;
    diff *= 2;
    long long int n, val;
    for (long long int i = (0); i <= (b); i += (1)) {
      long long int val = (a + (i * (i + 1)) / 2);
      if (val >= b) {
        if ((val - b) % 2 == 0) {
          cout << i << "\n";
          break;
        }
      }
    }
  }
  return 0;
}
