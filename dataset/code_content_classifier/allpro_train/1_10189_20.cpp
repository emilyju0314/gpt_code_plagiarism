#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  int c = 1;
  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i] == s[i + 1]) {
      c++;
    } else {
      if (c > k) {
        cout << "NO";
        return 0;
      }
      c = 1;
    }
  }
  if (c > k) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
  return 0;
}
