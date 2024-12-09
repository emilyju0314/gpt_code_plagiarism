#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  string s;
  cin >> n >> k >> s;
  set<char> chars;
  char last = 'a', first = 'z';
  for (int i = 0; i < s.length(); i++) {
    chars.insert(s[i]);
    last = max(last, s[i]);
    first = min(first, s[i]);
  }
  string res = "";
  if (k > s.length()) {
    res = s;
    k -= s.length();
    while (k) {
      res += first;
      k--;
    }
  } else {
    for (int i = 0; i < k; i++) res += s[i];
    for (int j = res.length() - 1; j >= 0; j--) {
      if (res[j] == last) {
        res[j] = first;
      } else {
        res[j] = *chars.upper_bound(res[j]);
        break;
      }
    }
  }
  cout << res << endl;
  return 0;
}
