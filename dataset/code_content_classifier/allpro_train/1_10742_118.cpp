#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  string s;
  while (t--) {
    cin >> s;
    int c[] = {0, 0, 0};
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] >= '0' && s[i] <= '9') c[0]++;
      if (s[i] >= 'a' && s[i] <= 'z') c[1]++;
      if (s[i] >= 'A' && s[i] <= 'Z') c[2]++;
    }
    if (!c[0] || !c[1] || !c[2])
      for (int i = 0; i < 3; ++i) {
        if (c[i]) continue;
        for (int j = 0; j < s.size(); ++j) {
          int p = 0;
          if (s[j] >= 'a' && s[j] <= 'z') p = 1;
          if (s[j] >= 'A' && s[j] <= 'Z') p = 2;
          if (c[p] < 2) continue;
          if (i == 0) s[j] = '0';
          if (i == 1) s[j] = 'a';
          if (i == 2) s[j] = 'A';
          c[p]--;
          c[i]++;
          break;
        }
      }
    cout << s << "\n";
  }
}
