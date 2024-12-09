#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  string x, y;
  cin >> x >> y;
  long long p1 = x[1] - '0', p2 = y[1] - '0';
  char s1, s2, ii = x[0], jj = y[0];
  if (p2 > p1) {
    s2 = 'U';
  } else {
    s2 = 'D';
  }
  if (jj > ii) {
    s1 = 'R';
  } else {
    s1 = 'L';
  }
  long long difs = abs(jj - ii), difp = abs(p2 - p1);
  cout << max(difs, difp) << '\n';
  for (long long i = 1; i <= min(difs, difp); i++) {
    cout << s1 << s2 << '\n';
  }
  for (long long j = 1; j <= max(difs, difp) - min(difs, difp); j++) {
    (max(difs, difp) == difp ? cout << s2 << '\n' : cout << s1 << '\n');
  }
  return 0;
}
