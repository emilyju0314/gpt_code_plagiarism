#include <bits/stdc++.h>
using namespace std;
bool flag;
int a, n, i, j, k, x, o, ans;
int w[10011], tot;
char s[100011];
int main() {
  scanf("%d\n%s", &a, s + 1);
  n = strlen(s + 1);
  if (s[1] != '-') {
    for (i = n + 1; i > 1; i--) s[i] = s[i - 1];
    s[1] = '+', n++;
  }
  for (i = 1; i <= n; i += 3) {
    if (s[i++] == '+')
      k = 1;
    else
      k = -1;
    j = 0;
    while (i <= n && '0' <= s[i] && s[i] <= '9') (j *= 10) += s[i++] - 48;
    if (s[i] == '*')
      i++;
    else
      j = 1;
    w[++tot] = (k *= j);
    ans += (a - (s[i] == 'a')) * k;
  }
  sort(w + 1, w + tot + 1);
  for (i = 1; i <= tot; i++) ans += i * w[i];
  cout << ans;
  return 0;
}