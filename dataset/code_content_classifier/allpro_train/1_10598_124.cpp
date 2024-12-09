#include <bits/stdc++.h>
using namespace std;
long long n, m, x, y, a, b;
int main() {
  cin >> n >> m >> x >> y >> a >> b;
  long long W = min(n, (m * a) / b);
  long long divA = a, divB = b;
  for (long long i = 2; i * i <= divB; i++) {
    while (divB % i == 0) {
      if (divA % i == 0) {
        divA /= i;
      }
      divB /= i;
    }
  }
  if (divA % divB == 0) divA /= divB;
  W -= (W % divA);
  long long H = (W * b) / a;
  long long x1 = x - ((W + 1) / 2);
  long long y1 = y - ((H + 1) / 2);
  long long x2 = x1 + W;
  long long y2 = y1 + H;
  if (x2 > n) {
    x2 = n;
    x1 = x2 - W;
  }
  if (x1 < 0) {
    x1 = 0;
    x2 = W;
  }
  if (y2 > m) {
    y2 = m;
    y1 = y2 - H;
  }
  if (y1 < 0) {
    y1 = 0;
    y2 = H;
  }
  W = x2 - x1;
  H = y2 - y1;
  cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}
