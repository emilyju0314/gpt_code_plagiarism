#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 + 10;
long long f[maxn] = {0, 1, 2};
void Output(long long n, long long m, long long t) {
  if (n == 1)
    cout << 1 + t << endl;
  else if (n == 2) {
    if (m == 1)
      cout << 1 + t << ' ' << 2 + t << endl;
    else
      cout << 2 + t << ' ' << 1 + t << endl;
  } else {
    if (m <= f[n - 1]) {
      cout << 1 + t << ' ';
      Output(n - 1, m, t + 1);
    } else {
      cout << 2 + t << ' ' << 1 + t << ' ';
      Output(n - 2, m - f[n - 1], t + 2);
    }
  }
  return;
}
int main() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 3; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
  Output(n, m, 0);
  return 0;
}
