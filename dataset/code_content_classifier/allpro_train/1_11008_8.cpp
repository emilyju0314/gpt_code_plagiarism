#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long int flag = 0;
  long long int msb = s.length();
  long long int ans;
  for (long long int i = 1; i < msb; i++) {
    if (s[i] == '1') {
      flag = 1;
      break;
    }
  }
  if (msb % 2 != 0) {
    if (flag)
      ans = (msb + 1) / 2;
    else
      ans = (msb - 1) / 2;
  } else
    ans = msb / 2;
  cout << ans;
}
