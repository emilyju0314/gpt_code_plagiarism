#include <bits/stdc++.h>
char S[100005];
int n;
int num[1000];
int main() {
  scanf("%d", &n);
  scanf("%s", S + 1);
  for (register int i = 1; i <= n; i++) num[S[i]]++;
  for (register char i = 'a'; i <= 'z'; i++)
    for (register int j = 1; j <= num[i]; j++) putchar(i);
  puts("");
  return 0;
}
