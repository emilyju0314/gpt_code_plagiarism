#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long a1, a2, k1, k2, n;
  cin >> a1 >> a2 >> k1 >> k2 >> n;
  long long n1, n2;
  n1 = n2 = n;
  long long mmin = 0, mmax = 0;
  if (k1 > k2) {
    swap(k1, k2);
    swap(a1, a2);
  }
  long long remt1 = min(n1 / k1, a1);
  n1 -= remt1 * k1;
  mmax = remt1;
  if (n1 > 0) {
    long long remt2 = min(n1 / k2, a2);
    mmax += remt2;
  }
  long long maxwithnoloss = min(a1 * (k1 - 1) + a2 * (k2 - 1), n);
  n2 -= maxwithnoloss;
  mmin = min(n2, a1 + a2);
  cout << mmin << " " << mmax << endl;
}
