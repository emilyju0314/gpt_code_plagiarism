#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
const long long MOD = 1000000000 + 9;
int a[10];
int ans[maxn];
int po[10];
char str[maxn];
int cnt[30];
int main() {
  a[0] = 1869;
  a[1] = 6198;
  a[2] = 1896;
  a[3] = 1689;
  a[4] = 1986;
  a[5] = 1968;
  a[6] = 1698;
  po[0] = 1;
  po[1] = 10;
  po[2] = 100;
  po[3] = 1000;
  scanf("%s", str + 1);
  int len = strlen(str + 1);
  for (int i = 1; i <= len; i++) {
    cnt[str[i] - '0']++;
  }
  int tmp = 0;
  int cur = 1;
  cnt[1]--;
  cnt[6]--;
  cnt[8]--;
  cnt[9]--;
  int i;
  for (i = 1; i <= len; i++) {
    while (cnt[cur] == 0 && cur <= 9) cur++;
    if (cur == 10) break;
    cnt[cur]--;
    ans[i] = cur;
    tmp = (tmp * 10 + cur) % 7;
  }
  int j = 3;
  for (; i <= len; i++) {
    if (j == -1) break;
    ans[i] = a[tmp] / po[j];
    a[tmp] %= po[j];
    j--;
  }
  for (; i <= len; i++) {
    ans[i] = 0;
  }
  for (int i = 1; i <= len; i++) {
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
