#include <bits/stdc++.h>
using namespace std;
typedef unsigned int UI;
typedef long int LI;
typedef unsigned long int ULI;
typedef long long int LL;
typedef unsigned long long int ULL;
LL mod = 1e9 + 7;
inline int scanInt() {
  int n = 0;
  char ch = getchar();
  int sign = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    n = (n << 1) + (n << 3) + (int)(ch - '0');
    ch = getchar();
  }
  return n * sign;
}
inline LL scanLong() {
  LL n = 0;
  char ch = getchar();
  LL sign = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    n = (n << 1) + (n << 3) + (LL)(ch - '0');
    ch = getchar();
  }
  return n * sign;
}
int main() {
  LL n = scanLong();
  ;
  string s;
  cin >> s;
  string ans = "No";
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    if ((s[i] == '?' && i > 0 && i + 1 < n) &&
        (s[i - 1] != '?' && s[i + 1] != '?' && s[i - 1] != s[i + 1]))
      ;
    else if (s[i] == '?')
      ans = "Yes";
    else if ((i > 0 && s[i] == s[i - 1]) || (i + 1 < n && s[i] == s[i + 1])) {
      ans = "No";
      break;
    }
  }
  cout << ans << endl;
}
