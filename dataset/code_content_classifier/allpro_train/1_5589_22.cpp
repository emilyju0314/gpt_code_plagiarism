#include <bits/stdc++.h>
using namespace std;
long long int pow(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 0) {
    long long int c = pow(2, b / 2);
    return c * c;
  } else {
    long long int c = pow(2, (b - 1) / 2);
    return 2 * c * c;
  }
}
int main() {
  int n{0};
  cin >> n;
  long long int ans = 0;
  for (long long int i = 1; i <= n; i++) {
    ans += pow(2, i);
  }
  cout << ans << endl;
  return 0;
}
