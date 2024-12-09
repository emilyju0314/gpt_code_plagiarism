#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    if (n == 1 or m == 1 or (n == 2 and m == 2))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
