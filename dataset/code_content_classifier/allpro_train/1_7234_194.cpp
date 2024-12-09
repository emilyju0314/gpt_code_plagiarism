#include <bits/stdc++.h>
using namespace std;
inline long long int max(long long int a, long long int b) {
  return (a > b ? a : b);
}
inline long long int min(long long int a, long long int b) {
  return (a < b ? a : b);
}
bool isPrime[100000 + 5];
void sieveOfEratosthenes(long long int n) {
  memset(isPrime, 1, sizeof(isPrime));
  for (long long int i = 2; i * i <= n; ++i) {
    if (isPrime[i]) {
      for (long long int j = i * i; j <= n; j += i) isPrime[j] = 0;
    }
  }
  return;
}
int main() {
  long long int t;
  cin >> t;
  long long int a[t];
  for (long long int i = 0; i < t; i++) cin >> a[i];
  long long int sum = 0;
  for (long long int i = 0; i < t; i++) {
    sum += a[i] - 1;
    if (sum % 2)
      cout << 1 << "\n";
    else
      cout << 2 << "\n";
  }
}
