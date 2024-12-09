#include <bits/stdc++.h>
using namespace std;
char s1[5005], s2[5005];
vector<int> cnt[2][2];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s1 + 1);
  scanf("%s", s2 + 1);
  for (int i = 1; i <= n; i++) {
    if (s1[i] == '0' && s2[i] == '0') cnt[0][0].push_back(i);
    if (s1[i] == '0' && s2[i] == '1') cnt[0][1].push_back(i);
    if (s1[i] == '1' && s2[i] == '0') cnt[1][0].push_back(i);
    if (s1[i] == '1' && s2[i] == '1') cnt[1][1].push_back(i);
  }
  int a = cnt[0][0].size(), b = cnt[0][1].size(), c = cnt[1][0].size(),
      d = cnt[1][1].size();
  int i, j;
  bool flag = 0;
  for (i = 0; i <= n / 2 && 2 * i <= b + c + d; i++) {
    for (j = max(0, i - d); j <= i && j <= c; j++) {
      int temp = (d - (i - j));
      if (temp <= i && b >= i - temp && b <= i + n / 2 - temp - i &&
          max(0, n / 2 - j - (i - j) - (b - i + temp)) <= a &&
          c - (i - temp) <= c && i - j <= d) {
        flag = true;
        break;
      }
    }
    if (flag) break;
  }
  if (!flag) {
    cout << -1 << endl;
    return 0;
  }
  if (cnt[1][0].size())
    for (int x = 0; x < j; x++) cout << cnt[1][0][x] << ' ';
  if (cnt[1][1].size())
    for (int x = 0; x < i - j; x++) cout << cnt[1][1][x] << ' ';
  if (cnt[0][1].size())
    for (int x = 0; x < b - (i - (d - (i - j))); x++)
      cout << cnt[0][1][x] << ' ';
  if (cnt[0][0].size())
    for (int x = 0; x < n / 2 - b - d + i - j; x++) cout << cnt[0][0][x] << ' ';
}
