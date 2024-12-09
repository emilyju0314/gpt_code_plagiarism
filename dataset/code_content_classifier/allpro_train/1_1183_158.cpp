#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 10;
int n, t, k, m;
int a[MAXN];
string s;
const int MOD = 1e9 + 7;
int main() {
  cin >> k >> n >> m;
  if ((n % k == 0 && n != 0) || (m % k == 0 && m != 0) || (n >= k && m >= k))
    return cout << n / k + m / k, 0;
  cout << -1;
}
