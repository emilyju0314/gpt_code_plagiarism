#include <bits/stdc++.h>
using namespace std;
int n;
char s[1001], tmp[1001];
int a[1001], len, aans[1001];
int ans[1001], alen, last, flag;
int Ans[100001][11], Len[100001];
int main() {
  scanf("%d", &n);
  alen = 1;
  ans[1] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%s", tmp + 1);
    len = strlen(tmp + 1);
    for (int j = 1; j <= len; j++) s[len - j + 1] = tmp[j];
    ans[1]++;
    for (int j = 1; ans[j] >= 10; j++) {
      ans[j] -= 10;
      ans[j + 1]++;
      if (j + 1 > alen) alen = j + 1;
    }
    if (len < alen) {
      puts("NO");
      return 0;
    }
    if (len > alen) {
      alen = len;
      if (s[len] == '?')
        ans[len] = 1;
      else
        ans[len] = s[len] - '0';
      for (int j = 1; j < len; j++)
        if (s[j] == '?')
          ans[j] = 0;
        else
          ans[j] = s[j] - '0';
    } else {
      last = len + 1;
      for (int j = len; j; j--) {
        if (s[j] == '?') {
          if (ans[j] != 9) last = j;
        } else {
          if (s[j] - '0' > ans[j]) {
            ans[j] = s[j] - '0';
            for (int k = j - 1; k > 0; k--)
              if (s[k] == '?')
                ans[k] = 0;
              else
                ans[k] = s[k] - '0';
            break;
          } else if (s[j] - '0' != ans[j]) {
            if (last == len + 1) {
              puts("NO");
              return 0;
            }
            ans[last]++;
            for (int j = last - 1; j > 0; j--)
              if (s[j] == '?')
                ans[j] = 0;
              else
                ans[j] = s[j] - '0';
            break;
          }
        }
      }
    }
    for (int j = 1; j <= alen; j++) Ans[i][j] = ans[j];
    Len[i] = alen;
  }
  puts("YES");
  for (int i = 1; i <= n; i++) {
    for (int k = Len[i]; k; k--) printf("%d", Ans[i][k]);
    printf("\n");
  }
}
