#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int i2 = 0;
  sort((s2).begin(), (s2).end());
  reverse((s2).begin(), (s2).end());
  for (int j = 0; j < s1.size() && i2 < s2.size(); j++) {
    if (s1[j] < s2[i2]) {
      s1[j] = s2[i2];
      i2++;
    }
  }
  cout << s1 << endl;
  return 0;
}
