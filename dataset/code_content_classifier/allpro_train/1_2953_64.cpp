#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, p;
  cin >> n >> p;
  for (long long i = 1; i < 31; ++i) {
    if (n - i * p > 0 && n - i * p >= i && __builtin_popcount(n - i * p) <= i) {
      cout << i << "\n";
      return 0;
    }
  }
  cout << "-1\n";
  return 0;
}
