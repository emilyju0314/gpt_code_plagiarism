#include <bits/stdc++.h>
using namespace std;
int n, m, cnt[30][2];
char a[1005], b[1005];
int main() {
  scanf("%s", a);
  n = strlen(a);
  scanf("%s", b);
  m = strlen(b);
  for (int i = 0; i < n; i++) cnt[a[i] - 'a'][0]++;
  for (int i = 0; i < m; i++) cnt[b[i] - 'a'][1]++;
  int ans = 0;
  for (int i = 0; i < 26; i++)
    if (cnt[i][1] && cnt[i][0] == 0) {
      printf("-1\n");
      return 0;
    }
  for (int i = 0; i < 26; i++) {
    if (cnt[i][0] >= cnt[i][1])
      ans += cnt[i][1];
    else
      ans += cnt[i][0];
  }
  printf("%d\n", ans);
  return 0;
}
