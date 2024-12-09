#include <bits/stdc++.h>
using namespace std;
int szx = 0;
long long x_1[1000000];
long long y_1[1000000];
int szy = 0;
int main() {
  long long a, b;
  cin >> a >> b;
  long long c = a + b;
  int ans;
  for (long long i = 0; i < 1e6; i++) {
    if (c >= i * (i + 1) / 2 && c < (i + 2) * (i + 1) / 2) ans = i;
  }
  if (a <= b) {
    for (long long i = ans; i > 0; i--) {
      if (a >= i) {
        a -= i;
        x_1[szx] = i;
        szx++;
      } else {
        b -= i;
        y_1[szy] = i;
        szy++;
      }
    }
  } else {
    for (int i = ans; i > 0; i--) {
      if (b >= i) {
        b -= i;
        y_1[szy] = i;
        szy++;
      } else {
        a -= i;
        x_1[szx] = i;
        szx++;
      }
    }
  }
  cout << szx << '\n';
  for (int i = 0; i < szx; i++) {
    cout << x_1[i] << " ";
  }
  cout << '\n' << szy << '\n';
  for (int i = 0; i < szy; i++) {
    cout << y_1[i] << " ";
  }
  return 0;
}
