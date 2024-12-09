#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<int> v;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int f = s.substr(i).find(t[i]);
    if (f == string::npos) {
      cout << -1;
      return 0;
    } else {
      for (int j = i + f; j >= i + 1; j--) {
        s[j] = s[j - 1];
        v.push_back(j);
      }
      s[i] = t[i];
      ans += f;
    }
  }
  cout << ans << "\n";
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
}
