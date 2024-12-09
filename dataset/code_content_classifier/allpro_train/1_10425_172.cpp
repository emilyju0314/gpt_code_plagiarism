#include <bits/stdc++.h>
using namespace std;
char str[100010];
map<char, int> mp;
int main() {
  while (scanf("%s", &str) == 1) {
    int n = strlen(str);
    mp.clear();
    long long ans = 1;
    int num = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (str[i] >= '0' && str[i] <= '9') continue;
      if (str[i] == '?') {
        if (i == 0)
          ans = ans * 9;
        else
          num++;
      } else {
        if (mp[str[i]]) continue;
        if (i == 0)
          ans = ans * 9;
        else
          ans = ans * (10 - cnt);
        mp[str[i]] = 1;
        cnt++;
      }
    }
    cout << ans;
    for (int i = 0; i < num; i++) printf("0");
    cout << endl;
  }
  return 0;
}
