#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s1;
    string s2;
    cin >> s1 >> s2;
    int p = 0, q = 0;
    for (int i = s2.size() - 1; i >= 0; i--, q++) {
      if (s2[i] == '1') break;
    }
    for (int i = s1.size() - 1; i >= 0; i--, p++) {
      if (s1[i] == '1' && p >= q) break;
    }
    cout << p - q << endl;
  }
  return 0;
}
