#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, s, k;
  cin >> a >> b >> s;
  if (a < 0) a *= -1;
  if (b < 0) b *= -1;
  if (s < 0) s *= -1;
  k = a + b;
  if (k > s) {
    cout << "No";
    return 0;
  }
  if (k == s)
    cout << "Yes";
  else if ((s - k) % 2 == 0)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
