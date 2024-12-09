#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using ull = unsigned long long;
const long long INF = (1ll << 32);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n % 2) {
    cout << 7;
    n -= 3;
  }
  for (int i = 0; i < n / 2; i++) cout << 1;
  cout << endl;
  return 0;
}
