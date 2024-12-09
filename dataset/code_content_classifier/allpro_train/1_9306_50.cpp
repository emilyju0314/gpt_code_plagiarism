#include <bits/stdc++.h>
int trie[100005][27];
char ch[100005];
int dfs(int n) {
  if (n == -1) return 1;
  int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
  int sum = 0;
  for (int i = 1; i <= 26; i++) {
    if (trie[n][i] == -1) continue;
    sum++;
    int res = dfs(trie[n][i]);
    if (res == 1) {
      f1 = 1;
    } else if (res == 2)
      f2 = 1;
    else if (res == 3)
      f3 = 1;
    else if (res == 4)
      f4 = 1;
  }
  if (sum == 0) return 2;
  if (f4) return 3;
  if (f1) {
    if (f2)
      return 3;
    else
      return 2;
  } else if (f2)
    return 1;
  else
    return 4;
}
int main() {
  int n, k;
  while (scanf("%d %d", &n, &k) != EOF) {
    memset(trie, -1, sizeof(trie));
    int tot = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%s", ch + 1);
      int len = strlen(ch + 1);
      int tt = 0;
      for (int j = 1; j <= len; j++) {
        int k = ch[j] - 'a' + 1;
        if (trie[tt][k] == -1) {
          trie[tt][k] = ++tot;
          tt = tot;
        } else
          tt = trie[tt][k];
      }
    }
    int ans = dfs(0);
    if (ans == 1) {
      if (k & 1)
        printf("First\n");
      else
        printf("Second\n");
    } else if (ans == 2 || ans == 4)
      printf("Second\n");
    else if (ans == 3)
      printf("First\n");
  }
  return 0;
}
