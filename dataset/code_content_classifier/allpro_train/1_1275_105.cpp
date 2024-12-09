#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64377216")
using namespace std;
vector<char> isPrime;
vector<int> primes;
void genPrimes(int n) {
  isPrime.assign(n, true);
  for (int i = 2; i < n; ++i) {
    if (!isPrime[i]) continue;
    primes.push_back(i);
    for (int j = i + i; j < n; j += i) isPrime[j] = false;
  }
}
bool testPrime(int a) {
  for (int i = 0; primes[i] * primes[i] <= a; ++i) {
    if (a % primes[i] == 0) return false;
  }
  return true;
}
int getCount(int n, int p, long long cur, int sign) {
  if (cur > n) return 0;
  if (p < 0) return sign * (n / cur);
  int res = 0;
  res += getCount(n, p - 1, cur, sign);
  res += getCount(n, p - 1, cur * primes[p], -sign);
  return res;
}
int getAnswer(int b, int k) {
  if (!testPrime(k)) return 0;
  if (k > b / k)
    return k <= b ? 1 : 0;
  else {
    int index = find(primes.begin(), primes.end(), k) - primes.begin();
    return getCount(b / k, index - 1, 1, 1);
  }
}
int main() {
  genPrimes(100000);
  int a, b, k;
  cin >> a >> b >> k;
  int x = getAnswer(b, k);
  int y = getAnswer(a - 1, k);
  cout << x - y;
  return 0;
}
