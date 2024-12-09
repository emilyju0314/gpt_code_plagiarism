#include <bits/stdc++.h>
using namespace std;
string s;
int T, n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    int cnt[2] = {0, 0}, tot[2] = {0, 0};
    for (int i = 0; i < n; i++) {
      cin >> s;
      tot[s.size() & 1]++;
      for (int j = 0; j < (int)s.size(); j++) cnt[s[j] - '0']++;
    }
    if (tot[1] >= (cnt[0] & 1) + (cnt[1] & 1))
      cout << n << endl;
    else
      cout << n - 1 << endl;
  }
  return 0;
}
