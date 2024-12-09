#include <bits/stdc++.h>
using namespace std;
int isPalindrom(string s) {
  for (int i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[s.size() - 1 - i]) {
      return 0;
    }
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string a;
  cin >> a;
  if (isPalindrom(a)) {
    cout << "yes";
    return 0;
  }
  for (int i = 0; i < 15; i++) {
    a = "0" + a;
    if (isPalindrom(a)) {
      cout << "yes";
      return 0;
    }
  }
  cout << "no";
  return 0;
}
