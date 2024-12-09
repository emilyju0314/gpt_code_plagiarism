#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[100010];
  string s;
  cin >> s;
  int m = 0;
  for (int i = 0; i < s.length(); i++) {
    if (m > 0 && s[i] == a[m - 1]) {
      m--;
    } else {
      a[m++] = s[i];
    }
  }
  if (m == 0)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
