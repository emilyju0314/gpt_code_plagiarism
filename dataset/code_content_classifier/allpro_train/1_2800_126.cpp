#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long n, long long INF) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * a) % INF;
    a = (a * a) % INF;
    n >>= 1;
  }
  return res;
}
bool checkCyclic(int base, int prime) {
  for (int i = 2; i * i < prime; ++i) {
    if ((prime - 1) % i == 0 && (binpow(base, (prime - 1) / i, prime) == 1 ||
                                 binpow(base, i, prime) == 1))
      return false;
  }
  return true;
}
bool isPrime(int X) {
  int i;
  for (i = 2; i * i <= X; ++i)
    if (X % i == 0) break;
  return (i * i > X);
}
int main(int argc, char** argv) {
  int n, x;
  cin >> n >> x;
  if (!(isPrime(n + 1)))
    cout << "-1" << endl;
  else {
    for (--x; x > 1; --x)
      if (checkCyclic(x, n + 1)) break;
    if (x > 1)
      cout << x << endl;
    else
      cout << "-1" << endl;
  }
  return 0;
}
