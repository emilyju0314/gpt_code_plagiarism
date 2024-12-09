#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long temp = 0, flag = 0, diff = 0, sum = 0, result = 0, ct = 0,
              cnt = 0, found = 0;
    long long a = 0, b = 0, c = 0, n = 0, m = 0, k = 0, x = 0, y = 0;
    set<long long> s1;
    map<long long, long long> mapp;
    std::vector<long long> v, v1, v2;
    string s;
    long long x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;
    sum += 2 * min(z1, y2);
    z1 = z1 - min(z1, y2);
    y2 -= min(z1, y2);
    temp = min(z2, x1);
    z2 -= temp;
    x1 -= temp;
    temp = min(z2, z1);
    z2 -= temp;
    z1 -= temp;
    if (z2 > 0) {
      sum -= 2 * z2;
    }
    cout << sum;
    cout << '\n';
  }
  return 0;
}
