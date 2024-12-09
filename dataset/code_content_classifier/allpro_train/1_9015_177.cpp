#include <bits/stdc++.h>
using namespace std;
int zm1[30], zm2[30];
int main() {
  int n;
  cin >> n;
  while (n--) {
    string s, t;
    cin >> s >> t;
    int i = 0, j = 0;
    while (j < t.size()) {
      if (s[i] == t[j])
        i++;
      else if (j == 0)
        break;
      else if (t[j] != t[j - 1]) {
        break;
      }
      j++;
    }
    if (j != t.size() || i != s.size())
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
