#include <bits/stdc++.h>
const long long INF = 2009000999;
const float cp = 2 * acos(0.0);
const float eps = 1e-18;
using namespace std;
int main() {
  long long n, p[1010000];
  cin >> n;
  if (n % 4 == 2 || n % 4 == 3) {
    puts("-1");
    return 0;
  }
  if (n % 4 == 0) {
    for (int i = 1; i <= n / 2; i++) {
      if (i % 2 == 1)
        p[i] = i + 1, p[n + 1 - i] = n - i;
      else
        p[i] = n + 2 - i, p[n + 1 - i] = i - 1;
    }
    for (int(i) = (1); (i) <= (n); i++) cout << p[i] << ' ';
  } else {
    for (int(i) = (1); (i) <= (n / 2); i++) {
      if (i % 2 == 1)
        p[i] = i + 1, p[n + 1 - i] = n - i;
      else
        p[i] = n + 2 - i, p[n + 1 - i] = i - 1;
    }
    p[n / 2 + 1] = n / 2 + 1;
    for (int(i) = (1); (i) <= (n); i++) cout << p[i] << ' ';
  }
}
