#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int main() {
  int t;
  cin >> t;
  mp.clear();
  while (t--) {
    char c;
    string s;
    cin >> c;
    if (c == '+') {
      string bin;
      cin >> s;
      reverse(s.begin(), s.end());
      while (s.size() <= 20) {
        s += '0';
      }
      for (int i = 0; i < s.size(); i++) {
        if ((s[i] - '0') % 2 == 0) {
          bin += '0';
        } else {
          bin += '1';
        }
      }
      mp[bin]++;
    }
    if (c == '-') {
      string bin;
      cin >> s;
      reverse(s.begin(), s.end());
      while (s.size() <= 20) {
        s += '0';
      }
      for (int i = 0; i < s.size(); i++) {
        if ((s[i] - '0') % 2 == 0) {
          bin += '0';
        } else {
          bin += '1';
        }
      }
      mp[bin]--;
    }
    if (c == '?') {
      cin >> s;
      reverse(s.begin(), s.end());
      while (s.size() <= 20) {
        s += '0';
      }
      cout << mp[s] << endl;
    }
  }
  return 0;
}
