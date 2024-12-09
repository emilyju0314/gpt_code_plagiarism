#include <bits/stdc++.h>
using namespace std;
char s1[6], s2[6], ch;
int cnt = 0, ans, ok1, ok2;
bool func1(int sumA, int sumB, char s[]) {
  int dif = sumB - sumA;
  for (int i = 0; i < 3; i++) {
    bool fl = 0;
    ch = s[i];
    while (ch < '9' && dif > 0) ch++, dif--, fl = 1;
    if (fl) cnt++;
  }
  return dif == 0;
}
bool func2(int sumA, int sumB, char s[]) {
  int dif = sumB - sumA;
  for (int i = 2; i >= 0; i--) {
    bool fl = 0;
    ch = s[i];
    while (ch > '0' && dif > 0) ch--, dif--, fl = 1;
    if (fl) cnt++;
  }
  return dif == 0;
}
int main() {
  while (scanf("%3s%3s", s1, s2) == 2) {
    cerr << s1 << " " << s2 << '\n';
    int sum = 0, sum1 = 0, sum2 = 0, ans = 9;
    for (int i = 0; i < 3; i++) sum1 += s1[i] - '0';
    for (int i = 0; i < 3; i++) sum2 += s2[i] - '0';
    sort(s1, s1 + 3), sort(s2, s2 + 3);
    sum = max(sum1, sum2);
    while (sum) {
      cnt = ok1 = ok2 = 0;
      if (sum1 <= sum)
        ok1 = func1(sum1, sum, s1);
      else
        ok1 = func2(sum, sum1, s1);
      if (sum2 <= sum)
        ok2 = func1(sum2, sum, s2);
      else
        ok2 = func2(sum, sum2, s2);
      if (ok1 && ok2) {
        cerr << "cnt= " << cnt << " " << sum << '\n';
        ans = min(ans, cnt);
      }
      sum--;
    }
    if (ans == 9) ans = 0;
    cout << ans << '\n';
  }
  return 0;
}
