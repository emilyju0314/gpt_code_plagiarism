#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int len = s.length();
  int SF = 0;
  for (int i = 1; i < len; i++)
    if (s[i] == 'S' && s[i - 1] == 'F')
      SF--;
    else if (s[i] == 'F' && s[i - 1] == 'S')
      SF++;
  cout << (SF > 0 ? "YES" : "NO");
  return 0;
}
