#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int one = 0, two = 0, zero = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '0') zero++;
    if (s[i] == '2') two++;
    if (s[i] == '1') one++;
  }
  int a = n / 3;
  int x = zero - a, y = one - a, z = two - a, ans = 0;
  ans += abs(x) + abs(y) + abs(z);
  if (x < 0 && z > 0) {
    for (int i = 0; i < s.length(); i++) {
      if (z == 0 || x == 0) break;
      if (s[i] == '2') {
        s[i] = '0';
        z--;
        x++;
      }
    }
  }
  if (x < 0 && y > 0) {
    for (int i = 0; i < s.length(); i++) {
      if (x == 0 || y == 0) break;
      if (s[i] == '1') {
        s[i] = '0';
        y--;
        x++;
      }
    }
  }
  if (y < 0 && z > 0) {
    for (int i = 0; i < s.length(); i++) {
      if (z == 0 || y == 0) break;
      if (s[i] == '2') {
        s[i] = '1';
        z--;
        y++;
      }
    }
  }
  if (z < 0 && x > 0) {
    for (int i = s.length(); i >= 0; i--) {
      if (z == 0 || x == 0) break;
      if (s[i] == '0') {
        s[i] = '2';
        z++;
        x--;
      }
    }
  }
  if (z < 0 && y > 0) {
    for (int i = s.length(); i >= 0; i--) {
      if (z == 0 || y == 0) break;
      if (s[i] == '1') {
        s[i] = '2';
        y--;
        z++;
      }
    }
  }
  if (x > 0 && y < 0) {
    for (int i = s.length(); i >= 0; i--) {
      if (x == 0 || y == 0) break;
      if (s[i] == '0') {
        s[i] = '1';
        x--;
        y++;
      }
    }
  }
  cout << s << '\n';
}
