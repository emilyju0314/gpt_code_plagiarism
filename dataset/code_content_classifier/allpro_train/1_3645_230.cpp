#include <bits/stdc++.h>
using namespace std;
long long arr[200010];
struct baba {
  long long shunji, shunou, niji, niou;
};
baba s[200010];
int main() {
  long long ans = 0;
  long long n;
  cin >> n;
  s[1].shunou = 0;
  s[n].niji = 0;
  s[n].niou = 0;
  long long sumji = 0, sumou = 0;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (i % 2 == 0)
      sumou += arr[i];
    else
      sumji += arr[i];
    s[i].shunji = sumji;
    s[i].shunou = sumou;
  }
  for (int i = n; i > 0; i--) {
    if (i % 2 == 0) {
      s[i].niou = sumou - s[i].shunou + arr[i];
      s[i].niji = sumji - s[i].shunji;
    } else {
      s[i].niou = sumou - s[i].shunou;
      s[i].niji = sumji - s[i].shunji + arr[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (s[i].shunji + s[i].niou == s[i].shunou + s[i].niji) ans++;
  }
  cout << ans;
  return 0;
}
