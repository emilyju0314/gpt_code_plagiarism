#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
const int maxn = 105;
int n, T;
int s[maxn], t[maxn];
int main() {
  cin >> n >> T;
  int ans = 0x3f3f3f3f, idx = -1;
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> t[i];
    for (int j = s[i]; j <= 200000; j += t[i]) {
      if (j >= T) {
        if (ans > j - T) {
          ans = j - T;
          idx = i;
        }
        break;
      }
    }
  }
  cout << idx << endl;
  return 0;
}
