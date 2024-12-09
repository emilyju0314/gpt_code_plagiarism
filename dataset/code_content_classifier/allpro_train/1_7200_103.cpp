#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    int i;
    int sum = 0;
    int e = 0;
    int z = 0;
    cin >> s;
    for (i = 0; i < s.length(); i++) {
      if ((s[i] - '0') % 2 == 0) e++;
      if ((s[i] - '0') == 0) z++;
      sum = sum + (s[i] - '0');
    }
    if (sum % 3 == 0 && z > 0 && e >= 2)
      cout << "red";
    else
      cout << "cyan";
    cout << endl;
  }
}
