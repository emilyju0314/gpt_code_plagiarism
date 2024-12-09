#include <bits/stdc++.h>
using namespace std;
vector<char> ans;
string s;
int two, one, zero;
int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '2') two++;
    if (s[i] == '1') one++;
    if (s[i] == '0') zero++;
  }
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '0' && two > 0) {
      zero--;
      ans.push_back('0');
      continue;
    }
    if (s[i] == '1') continue;
    if (s[i] == '2') {
      two--;
      ans.push_back('2');
    }
  }
  while (zero > 0) {
    cout << 0;
    zero--;
  }
  while (one > 0) {
    cout << 1;
    one--;
  }
  for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
  return 0;
}
