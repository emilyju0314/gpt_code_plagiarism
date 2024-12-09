#include <bits/stdc++.h>
using namespace std;
const long long mx = 1000050;
int main() {
  string week = "-baabcacbaabcac", r_week = "-cacbaabcacbaab";
  long long a, b, c;
  cin >> a >> b >> c;
  long long min_w = min(a / 3, b / 2);
  min_w = min(min_w, c / 2);
  a -= min_w * 3;
  b -= min_w * 2;
  c -= min_w * 2;
  long long cnt = 0;
  for (int i = 14; i >= 7; --i) {
    long long A = a, B = b, C = c, t = 0;
    for (long long j = i; j >= i - 7; --j) {
      if (week[j] == 'a') {
        if (A <= 0)
          break;
        else
          A--;
      }
      if (week[j] == 'b') {
        if (B <= 0)
          break;
        else
          B--;
      }
      if (week[j] == 'c') {
        if (C <= 0)
          break;
        else
          C--;
      }
      t++;
    }
    cnt = max(t, cnt);
  }
  cout << min_w * 7 + cnt;
}
