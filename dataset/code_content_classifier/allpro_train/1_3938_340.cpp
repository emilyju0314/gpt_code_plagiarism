#include <bits/stdc++.h>
using namespace std;
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  };
  string s;
  getline(cin, s);
  int n = s.length() - 2;
  while (s[n] == ' ') {
    n--;
  }
  if (s[n] == 'a' || s[n] == 'e' || s[n] == 'i' || s[n] == 'o' || s[n] == 'u' ||
      s[n] == 'y' || s[n] == 'A' || s[n] == 'E' || s[n] == 'I' || s[n] == 'O' ||
      s[n] == 'U' || s[n] == 'Y') {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
