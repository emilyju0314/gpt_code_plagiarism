#include <bits/stdc++.h>
using namespace std;
const int module = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> p4(n, 1);
  for (int i = 1; i < n; ++i) p4[i] = p4[i - 1] * 4;
  cout << 4 * 2 * 3 * p4[n - 3] + 4 * (n - 3) * 3 * 3 * (n >= 4 ? p4[n - 4] : 0)
       << "\n";
  return 0;
}
