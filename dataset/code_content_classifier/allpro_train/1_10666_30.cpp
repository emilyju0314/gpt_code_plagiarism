#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int test;
  cin >> test;
  while (test--) {
    long long int n, a, b;
    cin >> n >> a >> b;
    long long int diff = n - (2 * n - (a + b) - 1);
    cout << max((long long int)1, min(n, diff)) << " ";
    cout << min(a + b - 1, n) << "\n";
  }
  return 0;
}
