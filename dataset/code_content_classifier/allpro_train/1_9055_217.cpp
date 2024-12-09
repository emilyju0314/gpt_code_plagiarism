#include <bits/stdc++.h>
using namespace std;
int main() {
  char c[1005];
  scanf("%s", c);
  long long ans = 0;
  int sum = 0;
  int cnt = 0;
  int dot = 0;
  for (int i = 0; c[i] != 0; i++) {
    if (c[i] <= '9' && c[i] >= '0') {
      sum = sum * 10 + c[i] - '0';
      if (dot) cnt++;
    } else if (c[i] == '.') {
      dot = 1;
      cnt = 0;
    } else {
      if (!dot || cnt != 2) {
        sum *= 100;
      }
      ans += sum;
      sum = 0;
      dot = 0;
      cnt = 0;
    }
  }
  if (!dot || cnt != 2) {
    sum *= 100;
  }
  ans += sum;
  long long tmp = ans;
  vector<char> res;
  int tot = 0;
  while (ans) {
    tot++;
    res.push_back(ans % 10 + '0');
    if (tot % 3 == 2) res.push_back('.');
    ans /= 10;
  }
  while (tot < 3) {
    res.push_back('0');
    tot++;
    if (tot % 3 == 2) res.push_back('.');
  }
  if (res.back() == '.') res.pop_back();
  reverse(res.begin(), res.end());
  if (tmp % 100 == 0)
    for (int t = 0; t < 3; t++) res.pop_back();
  for (auto it : res) printf("%c", it);
  printf("\n");
}
