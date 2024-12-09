#include <bits/stdc++.h>
using namespace std;
string str[500005];
int lft[500005], rht[500005];
int cnt_lft[500005], cnt_rht[500005];
int main() {
  int i, j, k;
  int n;
  cin >> n;
  for (i = 0; i < n; ++i) {
    cin >> str[i];
  }
  int cnt;
  for (i = 0; i < n; ++i) {
    cnt = 0;
    k = str[i].length();
    for (j = 0; j < k; ++j) {
      if (str[i][j] == '(')
        cnt++;
      else {
        if (cnt == 0)
          lft[i]++;
        else
          cnt--;
      }
    }
    rht[i] = cnt;
  }
  int ans = 0, cnt_zero = 0;
  for (i = 0; i < n; ++i) {
    if (lft[i] != 0 && rht[i] != 0) continue;
    if (lft[i] != 0) {
      if (cnt_rht[lft[i]]) {
        cnt_rht[lft[i]]--;
        ans++;
      } else {
        cnt_lft[lft[i]]++;
      }
    } else if (rht[i] != 0) {
      if (cnt_lft[rht[i]]) {
        cnt_lft[rht[i]]--;
        ans++;
      } else {
        cnt_rht[rht[i]]++;
      }
    } else
      cnt_zero++;
  }
  ans += cnt_zero / 2;
  cout << ans << endl;
}
