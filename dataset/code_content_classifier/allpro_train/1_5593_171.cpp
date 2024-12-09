#include <bits/stdc++.h>
using namespace std;
char str[200005];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", str);
  int s = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '<') s++;
    if (str[i] == '>') break;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (str[i] == '>')
      s++;
    else
      break;
  }
  printf("%d\n", s);
  return 0;
}
