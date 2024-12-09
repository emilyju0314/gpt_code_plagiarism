#include <bits/stdc++.h>
using namespace std;
long long a[101];
int main() {
  long long n, x, y, sum = 0, sum2 = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  cin >> x >> y;
  for (int i = min((x - 1), (y - 1)); i <= max((x - 1), (y - 1)) - 1; i++)
    sum2 += a[i];
  cout << min(abs(sum - sum2), sum2) << endl;
  return 0;
}
