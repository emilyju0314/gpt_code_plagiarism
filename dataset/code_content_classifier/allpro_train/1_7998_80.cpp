#include <bits/stdc++.h>
using namespace std;
char s[5555];
int sg[5555];
bool v[5555];
int main() {
  gets(s);
  int len = strlen(s);
  if (len == 1 || len == 2) {
    puts("Second");
    return 0;
  }
  memset(sg, 0, sizeof(sg));
  sg[1] = 1;
  for (int i = 2; i <= len; i++) {
    memset(v, 0, sizeof(v));
    for (int j = 1; j <= i; j++)
      v[sg[max(j - 2, 0)] ^ sg[max(0, i - j - 1)]] = 1;
    for (int j = 0; j <= len; j++)
      if (!v[j]) {
        sg[i] = j;
        break;
      }
  }
  int ans = 0, sum = 0, cost = 0;
  for (int i = 1; i <= len - 2; i++) {
    if (s[i - 1] == s[i + 1])
      sum++;
    else {
      ans ^= sg[sum];
      sum = 0;
    }
  }
  ans ^= sg[sum];
  if (ans == 0)
    puts("Second");
  else {
    puts("First");
    for (int i = 1; i <= len - 2; i++)
      if (s[i - 1] == s[i + 1]) {
        sum = 1;
        int j = i;
        while (s[j] == s[j + 2] && j + 2 < len) j++;
        int tmp = sg[j - i + 1] ^ ans;
        for (int k = 1; k <= j - i + 1; k++) {
          int tt = tmp ^ sg[max(0, k - 2)] ^ sg[max(j - i - k, 0)];
          if (tt == 0) {
            printf("%d\n", i + k);
            return 0;
          }
        }
        i = j;
      }
  }
  return 0;
}
