#include <bits/stdc++.h>
using namespace std;
const long long int mod = 998244353;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int z, s0 = 0, s1 = 0;
    for (int i = 0; i < n; i++) {
      cin >> z;
      if (z)
        s1++;
      else
        s0++;
    }
    if (s0 >= n / 2) {
      cout << s0 << "\n";
      for (int i = 0; i < s0; i++) {
        cout << "0 ";
      }
      cout << "\n";
    } else {
      if (s1 % 2 != 0) s1--;
      cout << s1 << "\n";
      for (int i = 0; i < s1; i++) {
        cout << "1 ";
      }
      cout << "\n";
    }
  }
}
