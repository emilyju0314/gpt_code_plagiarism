#include <bits/stdc++.h>
using namespace std;
int add(long long a, long long b) {
  return ((a % 1000000007) + (b % 1000000007)) % 1000000007;
}
int subtract(long long a, long long b) {
  return ((a % 1000000007) - (b % 1000000007)) % 1000000007;
}
int mult(long long a, long long b) {
  return ((a % 1000000007) * (b % 1000000007)) % 1000000007;
}
int add1(long long a, long long b) {
  return ((a % 998244353) + (b % 998244353)) % 998244353;
}
int subtract1(long long a, long long b) {
  return ((a % 998244353) - (b % 998244353)) % 998244353;
}
int mult1(long long a, long long b) {
  return ((a % 998244353) * (b % 998244353)) % 998244353;
}
long long int binmodwithMOD1(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = mult1(res, a) % 998244353;
    a = mult1(a, a) % 998244353;
    b >>= 1;
  }
  return res;
}
long long int binmodwithMOD(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = mult(res, a) % 1000000007;
    a = mult(a, a) % 1000000007;
    b >>= 1;
  }
  return res;
}
long long int binmodwithoutMOD1orMOD2(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int inverse(long long int n) {
  return binmodwithMOD(n, 1000000007 - 2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long int ele = a[0];
  bool ok = false;
  for (long long int i = 1; i < n; i++) {
    if (a[i] % ele != 0) ok = true;
  }
  if (ok)
    cout << -1 << "\n";
  else
    cout << ele << "\n";
  return 0;
}
