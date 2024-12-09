#include <bits/stdc++.h>
using namespace std;
bool comp(string s1, string s2) {
  if (s1.length() != s2.length())
    return s1.length() > s2.length();
  else
    return s1[0] > s2[0];
}
int main() {
  string s;
  cin >> s;
  int result = 0, j;
  for (int i = 0; i < s.length(); i = j) {
    for (j = i + 1; j < s.length(); j++)
      if (s[j] != '0') break;
    if (j - i > i || (j - i == i && s[i] > s[0])) result = 0;
    result++;
  }
  cout << result << endl;
  return 0;
}
