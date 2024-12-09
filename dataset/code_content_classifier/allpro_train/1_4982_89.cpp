#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (a && b) a > b ? a %= b : b %= a;
  return a + b;
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
int main() {
  int n;
  cin >> n;
  int i, j, sum = 0, in;
  int a[n];
  for (i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  int x = n / 2;
  int avg = sum / x;
  for (i = 0; i < n; i++) {
    if (a[i] == 0) continue;
    cout << i + 1 << " ";
    for (j = i + 1; j < n; j++) {
      if (a[j] == 0) continue;
      if ((a[j] + a[i]) == avg) {
        cout << j + 1 << " ";
        a[j] = 0;
        a[i] = 0;
        break;
      }
    }
    cout << endl;
  }
  return 0;
}
