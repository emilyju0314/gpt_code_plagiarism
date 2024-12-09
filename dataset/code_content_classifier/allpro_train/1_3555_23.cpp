#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, s, i, an = 0, x;
  cin >> n >> s;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (i = 1; i < n; i++) an += (a[i] - a[0]);
  if (an >= s)
    cout << a[0];
  else {
    s -= an;
    x = a[0];
    if (s > n * x)
      cout << "-1";
    else {
      if (s % n == 0) {
        s /= n;
        cout << x - s;
      } else {
        s /= n;
        cout << x - s - 1;
      }
    }
  }
}
