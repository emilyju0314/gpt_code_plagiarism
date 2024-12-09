#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15000001;
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n, x, y;
  cin >> n >> x >> y;
  long long w = x - 1 + y - 1, b = n - x + n - y;
  if (w <= b) {
    cout << "White" << '\n';
  } else
    cout << "Black" << '\n';
}
