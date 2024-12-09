#include <bits/stdc++.h>
using namespace std;
struct H {
  long long a, b;
  H() {}
  H(long long a, long long b) : a(a), b(b) {}
  H operator*(long long x) { return H(a * x, b * x % 1000000007); }
  H operator*(H h) { return H(a * h.a, b * h.b % 1000000007); }
  H operator+(long long x) { return H(a + x, b + x % 1000000007); }
  H operator-(H h) { return H(a - h.a, (b - h.b + 1000000007) % 1000000007); }
  bool operator==(H h) { return a == h.a && b == h.b; }
};
int n;
char a[1000010], b[1000010];
H x[1000010], y[1000010], p[1000010];
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> a + 1 >> b + 1;
  reverse(b + 1, b + n);
  for (int i = 1; i < n; i++) {
    if (b[i] == 'N')
      b[i] = 'S';
    else if (b[i] == 'S')
      b[i] = 'N';
    else if (b[i] == 'W')
      b[i] = 'E';
    else if (b[i] == 'E')
      b[i] = 'W';
  }
  p[0] = H(1, 1);
  for (int i = 1; i < n; i++) {
    x[i] = x[i - 1] * 37 + (a[i] - 'A');
    y[i] = y[i - 1] * 37 + (b[i] - 'A');
    p[i] = p[i - 1] * 37;
  }
  for (int i = 1; i < n; i++) {
    if (y[i] == x[n - 1] - x[n - 1 - i] * p[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}
