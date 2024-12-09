#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long i, j, k, n, r, a[10], t;
  cin >> t;
  while (t--) {
    string str = "";
    cin >> n;
    for (i = 0; i < n / 2; i++) str += "1";
    if (n % 2 == 1) str[0] = '7';
    cout << str << "\n";
  }
  return 0;
}
