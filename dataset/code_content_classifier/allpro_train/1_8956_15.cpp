#include <bits/stdc++.h>
using namespace std;
string x;
char s[100000];
int i, n, m;
int main() {
  cin >> x;
  n = x.size();
  for (i = 0; i < n; i++)
    if (x[i] == '1') s[n - i - 1]++;
  cin >> x;
  m = x.size();
  for (i = 0; i < m; i++)
    if (x[i] == '1') s[m - i - 1]--;
  for (i = max(n, m) - 1; i > 1; i--) {
    if (s[i] > 1) {
      cout << ">" << endl;
      return 0;
    } else if (s[i] < -1) {
      cout << "<" << endl;
      return 0;
    } else if (s[i] == 1) {
      s[i] = 0;
      s[i - 1]++;
      s[i - 2]++;
    } else if (s[i] == -1) {
      s[i] = 0;
      s[i - 1]--;
      s[i - 2]--;
    }
  }
  if (s[1] == 0 && s[0] == 0)
    cout << "=" << endl;
  else if (s[1] * 8 + s[0] * 5 > 0)
    cout << ">" << endl;
  else
    cout << "<" << endl;
  return 0;
}
