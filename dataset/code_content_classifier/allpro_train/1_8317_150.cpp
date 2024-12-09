#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 9;
int n, k, num, l, r, cnt;
char s[maxn];
int a[maxn];
int main() {
  scanf("%d %d", &n, &k);
  scanf("%s", s);
  num = (n - k) / 2;
  l = 0;
  for (int i = 0; i < n && num; i++) {
    if (s[i] == '(') {
      l++;
      a[l] = i;
    } else {
      s[a[l]] = 's';
      s[i] = 's';
      l--;
      num--;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] != 's') printf("%c", s[i]);
  }
  printf("\n");
  return 0;
}
