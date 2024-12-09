#include <bits/stdc++.h>
using namespace std;
long long int powr(int s, int p) {
  if (p == 0) return 1;
  if (p % 2 == 1) {
    long long int q = powr(s, p / 2);
    long long int a = q;
    q = (a * a);
    q = (q * s);
    return (q);
  } else {
    long long int q = powr(s, p / 2);
    long long int a = q;
    q = (a * a);
    return (q);
  }
}
int gcd(int p, int q) {
  if (q == 0)
    return p;
  else
    return (gcd(q, p % q));
}
int main() {
  int n, m;
  int a, b;
  int tempa, tempb;
  cin >> n >> m;
  cin >> a;
  for (int i = 0; i < n; i++) cin >> tempa;
  cin >> b;
  for (int i = 0; i < m; i++) cin >> tempb;
  if (n > m) {
    if (a * b > 0)
      cout << "Infinity" << endl;
    else
      cout << "-Infinity\n";
  } else if (m > n) {
    printf("0/1\n");
  } else {
    int x = abs(a);
    int y = abs(b);
    int g = gcd(x, y);
    a /= g;
    b /= g;
    x = abs(a);
    y = abs(b);
    if (a * b > 0)
      cout << x << '/' << y << endl;
    else
      cout << '-' << x << '/' << y << endl;
  }
  return 0;
}
