#include <bits/stdc++.h>
using namespace std;
int n;
char s[1000001];
short a[(1 << 26)];
int m;
int c[10001], b[10001];
char t[100001];
int main() {
  scanf("%s", s);
  n = strlen(s);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%s", t);
    int l = strlen(t);
    int k = 0;
    for (int j = 0; j < l; j++) k |= 1 << (t[j] - 'a');
    b[i] = k;
    a[k] = i;
  }
  for (int i = 0; i < n; i++) {
    int k = 0;
    for (int j = i; j < n; j++) {
      if (s[i - 1] == s[j]) break;
      k |= 1 << (s[j] - 'a');
      if (!(k & (1 << (s[j + 1] - 'a')))) c[a[k]]++;
    }
  }
  for (int i = 1; i <= m; i++) printf("%d\n", c[a[b[i]]]);
  return 0;
}
