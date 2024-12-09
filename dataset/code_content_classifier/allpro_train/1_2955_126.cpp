#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000 + 10, mod = 1000 * 1000 * 1000 + 7;
long long int n, a[MAXN];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int w = 0, b = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i % 2)
      b += a[i] / 2, w += (a[i] + 1) / 2;
    else
      b += (a[i] + 1) / 2, w += a[i] / 2;
  }
  cout << min(w, b);
  return 0;
}
