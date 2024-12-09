#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n;
char s[N], s1[N];
int len, len1, ans, flag[40], flag1;
int male, female, cnt;
int a[N], an, ok, num;
int cnt1[3];
int main() {
  int i, j, k;
  char str[6][10] = {"lios", "liala", "etr", "etra", "initis", "inites"};
  an = 0;
  male = female = 0;
  cnt = 0;
  ok = 1;
  num = 0;
  while (scanf("%s", s) != EOF) {
    num++;
    len = strlen(s);
    for (i = 0; i < 6; i++) {
      len1 = strlen(str[i]);
      if (len >= len1) {
        for (j = len - 1, k = len1 - 1; k >= 0; k--, j--)
          if (s[j] != str[i][k]) break;
        if (k == -1) {
          if (i % 2 == 0)
            male = 1;
          else
            female = 1;
          a[an++] = i / 2;
          if (i / 2 == 1) cnt++;
          break;
        }
      }
    }
    if (i == 6) ok = 0;
  }
  if (ok == 1 && num == 1)
    printf("YES\n");
  else if (ok == 0 || (male && female) || cnt != 1)
    printf("NO\n");
  else {
    memset(cnt1, 0, sizeof(cnt1));
    for (i = 0; i < an; i++) {
      if (a[i] == 0) {
        if (cnt1[1] > 0 || cnt1[2] > 0) break;
      } else if (a[i] == 1) {
        if (cnt1[2] > 0) break;
      }
      cnt1[a[i]]++;
    }
    if (i == an)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
