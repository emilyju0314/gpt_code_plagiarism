#include <bits/stdc++.h>
using namespace std;
int a[200050];
int gcd(int a, int b) {
  if (a < b) {
    int t = a;
    a = b;
    b = t;
  }
  if (b == 0) return a;
  while (a % b != 0) {
    int t = a % b;
    a = b;
    b = t;
  }
  return b;
}
bool cmp(int a, int b) { return a > b; }
int main() {
  int n, ma = 0;
  cin >> n;
  int i, k;
  long long s = 0;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1, cmp);
  ma = a[1];
  if (n == 2)
    k = ma - a[2];
  else
    k = gcd(ma - a[3], ma - a[2]);
  for (i = 2; i <= n; i++) {
    s += ma - a[i];
    k = gcd(k, ma - a[i]);
  }
  cout << s / k << ' ' << k << endl;
}
