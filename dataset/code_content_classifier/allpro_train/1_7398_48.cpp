#include <bits/stdc++.h>
using namespace std;
long long power(long long b, long long p) {
  if (p == 0)
    return 1;
  else
    return b * power(b, p - 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, sum, cnt(0);
  string s;
  cin >> n >> s;
  for (int i = 0; i < s.size(); i++) {
    if (((i + 1) % 2 == 1 && s[i] == '1') || ((i + 1) % 2 == 0 && s[i] == '0'))
      cnt++;
  }
  sum = n - cnt;
  cout << min(sum, cnt) << endl;
  return 0;
}
