#include <bits/stdc++.h>
using namespace std;
int k;
char str[1005];
int ct[30];
char a[1005];
int main() {
  while (~scanf("%d", &k)) {
    scanf("%s", str);
    int len = strlen(str);
    memset(ct, 0, sizeof(ct));
    for (int i = 0; i < len; i++) {
      ct[str[i] - 'a']++;
    }
    int flag = 0;
    for (int i = 0; i < 26; i++)
      if (ct[i] % k != 0) flag = 1;
    if (flag) {
      puts("-1");
      continue;
    }
    int now = 0;
    for (int i = 0; i < 26; i++) {
      int kk = ct[i] / k;
      for (int j = 0; j < kk; j++) a[now++] = i + 'a';
    }
    a[now] = '\0';
    for (int i = 0; i < k; i++) printf("%s", a);
    puts("");
  }
  return 0;
}
