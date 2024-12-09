#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int, long long int>> a;
long long int recur(long long int a, long long int b);
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int x, y;
    cin >> x >> y;
    long long int a = min(x, y);
    long long int b = max(x, y);
    if ((a + b) % 3 == 0 && b <= a * 2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
