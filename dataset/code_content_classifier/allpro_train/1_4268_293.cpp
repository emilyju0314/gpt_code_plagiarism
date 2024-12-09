#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int difference = 0;
  int count71 = 0, count72 = 0;
  int not_inplace = 0;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] != s2[i]) not_inplace++;
    if (s1[i] == '7') count71++;
    if (s2[i] == '7') count72++;
  }
  int ans = abs(count71 - count72);
  ans += ((not_inplace)-abs(count71 - count72)) / 2;
  cout << ans << endl;
  return 0;
}
