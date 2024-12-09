#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    cout << min(min(n, m), (n + m) / 3) << endl;
  }
  return 0;
}
