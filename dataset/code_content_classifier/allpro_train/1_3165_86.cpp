#include <bits/stdc++.h>
using namespace std;
bool is_prime(long long x) {
  if (x < 2) return false;
  for (int i = 2; i <= sqrt(x); i++)
    if (x % i == 0) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  if (n % 2 == 0) {
    if (n == 2)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  } else if (n % 2 == 1 && is_prime(n))
    cout << 1 << endl;
  else if (n % 2 == 1 && is_prime(n - 2))
    cout << 2 << endl;
  else
    cout << 3 << endl;
  return 0;
}
