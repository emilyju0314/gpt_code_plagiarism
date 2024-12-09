#include <bits/stdc++.h>
using namespace std;
const long long oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  vector<long long> a(n + 1);
  for (long long i = (0); i < (n); i++) cin >> a[i];
  a[n] = a[0];
  vector<pair<long long, long long> > c(n);
  for (long long i = (0); i < (n); i++) c[i] = {n - a[i] - a[i + 1], i};
  sort(begin(c), end(c));
  vector<long long> b(n);
  for (long long i = (0); i < (n); i++) b[c[i].second] = n - 1 - i;
  for (long long i = (0); i < (n); i++) cout << b[i] << " \n"[i + 1 == n];
}
