#include <bits/stdc++.h>
using namespace std;
long long w[3000002], n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long x = 0, y; x < n; x++) {
    cin >> y;
    w[y]++;
  }
  for (long long x = 0; x <= 3000000; x++) {
    w[x + 1] += w[x] / 2;
    w[x] %= 2;
  }
  long long out = 0;
  for (long long x = 0; x <= 3000001; x++) {
    out += w[x];
  }
  cout << out << endl;
  return 0;
}
