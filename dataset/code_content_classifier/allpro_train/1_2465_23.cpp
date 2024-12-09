#include <bits/stdc++.h>
#pragma comment(linker, "STACK:1048576000")
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  long long ans = 1;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] - '0' + s[i - 1] - '0' != 9) continue;
    int j = i;
    while (j < s.size() && (s[j] - '0' + s[j - 1] - '0' == 9)) j++;
    j--;
    if ((j - i) % 2) ans *= (j - i + 3) / 2;
    i = j;
  }
  cout << ans << endl;
  return 0;
}
