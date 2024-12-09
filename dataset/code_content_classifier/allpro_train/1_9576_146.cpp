#include <bits/stdc++.h>
using namespace std;
long long int binomialCoeff(long long int n, long long int k) {
  long long int res = 1;
  if (k > n - k) k = n - k;
  for (int i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  long long int p =
      binomialCoeff(n, 7) + binomialCoeff(n, 6) + binomialCoeff(n, 5);
  cout << p;
  return 0;
}
