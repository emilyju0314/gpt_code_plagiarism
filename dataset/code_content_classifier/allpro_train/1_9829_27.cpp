#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long S = 0;
  if (n > 2) {
    for (long long i = 0; i < n - 2; i++) {
      S += a[i] * (i + 2);
    }
    S += (a[n - 1] + a[n - 2]) * n;
  } else if (n == 2)
    S += 2 * (a[0] + a[1]);
  else
    S += a[0];
  cout << S;
}
