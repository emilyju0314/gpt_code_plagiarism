#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
int main() {
  int n, g, i;
  cin >> n;
  vector<int> v(n);
  for (i = 0; i < n; i++) cin >> v[i];
  g = v[n - 1];
  for (i = 0; i < n - 1; i++) g = gcd(v[i], g);
  while (g % 2 == 0) g /= 2;
  while (g % 3 == 0) g /= 3;
  for (i = 0; i < n; i++) {
    v[i] /= g;
    while (v[i] % 2 == 0) v[i] /= 2;
    while (v[i] % 3 == 0) v[i] /= 3;
    if (v[i] != 1) break;
  }
  if (i == n)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
