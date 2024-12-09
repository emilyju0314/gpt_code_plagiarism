#include <bits/stdc++.h>
using namespace std;
int main() {
  long double a, b[1000], c = 0;
  cin >> a;
  for (int i = 0; i < a; i++) {
    cin >> b[i];
    c += b[i];
  }
  size_t save_prec = cout.precision();
  cout << setprecision(12) << fixed << c / a;
}
