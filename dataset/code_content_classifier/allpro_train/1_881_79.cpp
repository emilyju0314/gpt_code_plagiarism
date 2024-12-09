#include <bits/stdc++.h>
using namespace std;
const int MAX = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int x;
    string s;
    cin >> x >> s;
    int currLen = (int)s.size();
    for (int i = 0; i < x; i++) {
      int curr = s[i] - '0';
      if (currLen < x) {
        for (int j = 1; j < curr; j++)
          if ((int)s.size() < x) {
            for (int l = i + 1; l < currLen; l++)
              if ((int)s.size() < x) s += s[l];
          }
      }
      int d = (currLen - i - 1 + mod) % mod;
      currLen = ((i + 1) + (long long)d * curr) % mod;
    }
    cout << currLen << '\n';
  }
  return 0;
}
