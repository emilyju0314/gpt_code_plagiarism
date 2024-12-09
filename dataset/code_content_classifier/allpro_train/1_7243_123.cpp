#include <bits/stdc++.h>
using namespace std;
const int tinf = (int)1e9 + 7;
const long long inf = (long long)1e18 + 7;
const int N = 4e5 + 5;
int main() {
  {
    ios ::sync_with_stdio(false);
    cin.tie(0);
  }
  long long k1, k2, k3, d[10000] = {};
  cin >> k1 >> k2 >> k3;
  d[k1]++, d[k2]++, d[k3]++;
  if (d[1] || d[2] >= 2 || d[3] == 3 || (d[4] == 2 && d[2])) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
}
