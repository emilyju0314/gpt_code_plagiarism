#include <bits/stdc++.h>
using namespace std;
int get(int l, int r, string &s) {
  int ans = 0;
  int pow = 1;
  for (int i = r; i >= l; i--) {
    if (s[i] == '1') {
      ans += pow;
    }
    pow <<= 1;
  }
  return ans;
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<int> a;
    int last = -1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') last = i;
      a.push_back(last);
    }
    long long ans = 0;
    for (int l = 1; l <= 18; l++) {
      for (int i = 0; i + l - 1 < s.size(); i++) {
        if (s[i] == '0') continue;
        int n = get(i, i + l - 1, s);
        int r = i > 0 ? a[i - 1] + 1 : i;
        if (n <= i + l - r) ans++;
      }
    }
    cout << ans << endl;
  }
}
int main() {
  solve();
  getchar();
  getchar();
}
