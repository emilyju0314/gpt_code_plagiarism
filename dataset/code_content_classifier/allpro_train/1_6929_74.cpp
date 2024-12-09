#include <bits/stdc++.h>
using namespace std;
long long int sq(long long int x) { return 1LL * x * x; }
long long int ans = 2e18;
void solve(vector<long long int> x, vector<long long int> y,
           vector<long long int> z) {
  for (auto i : y) {
    auto r = lower_bound(z.begin(), z.end(), i);
    auto l = upper_bound(x.begin(), x.end(), i);
    if (r == z.end() || l == x.begin()) continue;
    l--;
    ans = min(ans, sq(*l - i) + sq(*r - i) + sq(*l - *r));
  }
}
signed main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    vector<long long int> l(0), r(0);
    long long int n = (long long int)(sqrt(2 * (a + b)));
    if (n * (n + 1) <= 2 * (a + b)) n++;
    long long int x = max(a, b);
    long long int y = min(a, b);
    long long int k = (long long int)(sqrt(2 * (x)));
    if (k * (k + 1) < 2 * (x)) k++;
    long long int temp = ((k + 1) * k) / 2 - x;
    if (temp > 0 && y >= temp) r.push_back(temp);
    for (long long int i = 1; i <= k; i++)
      if (i != temp) l.push_back(i);
    k++;
    y = y - temp;
    while (y >= k) {
      r.push_back(k);
      y -= k;
      k++;
    }
    if (x == a) {
      cout << l.size() << endl;
      for (auto i : l) cout << i << " ";
      cout << endl;
      cout << r.size() << endl;
      for (auto i : r) cout << i << " ";
      cout << endl;
    } else {
      cout << r.size() << endl;
      for (auto i : r) cout << i << " ";
      cout << endl;
      cout << l.size() << endl;
      for (auto i : l) cout << i << " ";
      cout << endl;
    }
  }
}
