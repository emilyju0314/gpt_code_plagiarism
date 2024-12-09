#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    queue<char> ev;
    queue<char> odd;
    for (int i = 0; i < s.length(); i++) {
      if ((s[i] - '0') % 2 == 0) {
        ev.push(s[i]);
      } else {
        odd.push(s[i]);
      }
    }
    string ans = "";
    while (!ev.empty() && !odd.empty()) {
      if (ev.front() < odd.front()) {
        ans += ev.front();
        ev.pop();
      } else {
        ans += odd.front();
        odd.pop();
      }
    }
    while (!ev.empty()) {
      ans += ev.front();
      ev.pop();
    }
    while (!odd.empty()) {
      ans += odd.front();
      odd.pop();
    }
    cout << ans << endl;
  }
  return 0;
}
