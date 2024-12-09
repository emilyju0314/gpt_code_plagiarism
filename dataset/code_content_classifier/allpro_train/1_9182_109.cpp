#include <bits/stdc++.h>
using namespace std;
map<int, long long> mp;
const int maxn = 1e6 + 10;
char str[maxn];
int num[30];
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    scanf("%s", str);
    memset(num, 0, sizeof num);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
      num[str[i] - 'a']++;
    }
    int state = 0;
    for (int i = 0; i < 26; i++) {
      if (num[i] & 1) {
        state |= (1 << i);
      }
    }
    mp[state]++;
  }
  long long ans = 0;
  for (map<int, long long>::iterator it = mp.begin(); it != mp.end(); it++) {
    ans += (it->second) * ((it->second) - 1) / 2;
    int state = it->first;
    for (int i = 0; i < 26; i++) {
      if ((state >> i) & 1) {
        int tmp = (1 << i) ^ (state);
        ans += mp[tmp] * mp[state];
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
