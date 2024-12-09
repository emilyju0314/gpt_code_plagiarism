#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  int cnt[26];
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < 26; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++) {
      string str;
      cin >> str;
      for (int j = 0; j < str.length(); j++) {
        cnt[str[j] - 'a']++;
      }
    }
    bool ok = true;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] % n != 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
