#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, b;
  cin >> s >> b;
  cout << s[0];
  for (int i = 1; i < s.size(); i++) {
    if (s[i] < b[0]) {
      cout << s[i];
    } else {
      cout << b[0];
      return 0;
    }
  }
  cout << b[0];
}
