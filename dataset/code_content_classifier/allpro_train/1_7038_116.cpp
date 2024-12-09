#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1e-11;
signed long long n, c;
signed long long a[101], b[101];
int main() {
  cin >> n >> c;
  for (int i = 0; i < (n); i++) {
    cin >> a[i] >> b[i];
  }
  signed long long ans = 0;
  signed long long l = 0;
  signed long long first = 0;
  while (1) {
    first++;
    l = 0;
    for (int i = 0; i < (n); i++) l += 1 + ((first * a[i]) / b[i]);
    if (l == c) ans++;
    if (l > c) break;
  }
  cout << ans;
  return 0;
}
