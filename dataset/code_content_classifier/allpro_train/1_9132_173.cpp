#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  unordered_map<char, int> uKey;
  int ans(0);
  for (int i = 0; i < 2 * n - 2; i++) {
    if (i % 2 == 0)
      uKey[s[i]]++;
    else if (uKey[tolower(s[i])] > 0)
      uKey[tolower(s[i])]--;
    else
      ans++;
  }
  cout << ans;
  return 0;
}
