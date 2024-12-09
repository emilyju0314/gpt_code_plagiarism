#include <bits/stdc++.h>
using namespace std;
long long a[100002];
int n = 0;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main(int argc, const char* argv[]) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0) a[i] = -a[i];
  }
  int cnt = 0;
  long long g = gcd(a[0], a[1]);
  if (n > 2) {
    for (int k = 2; k < n; k++) {
      g = gcd(g, a[k]);
    }
  }
  if (g > 1) {
    cout << "YES\n0\n";
    return 0;
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] % 2 != 0 && a[i + 1] % 2 != 0) {
      long long diff = a[i] - a[i + 1];
      a[i + 1] = a[i] + a[i + 1];
      a[i] = diff;
      cnt++;
      continue;
    }
    if (a[i] % 2 != 0 && a[i + 1] % 2 == 0) {
      long long diff = a[i] - a[i + 1];
      a[i + 1] = a[i] + a[i + 1];
      a[i] = diff;
      cnt++;
      diff = a[i] - a[i + 1];
      a[i + 1] = a[i] + a[i + 1];
      a[i] = diff;
      cnt++;
      continue;
    }
  }
  if (a[n - 1] % 2 != 0) cnt += 2;
  cout << "YES\n" << cnt << endl;
  return 0;
}
