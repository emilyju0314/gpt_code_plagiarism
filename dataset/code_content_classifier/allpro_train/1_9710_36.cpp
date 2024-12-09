#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &x) {
  x = 0;
  int f = 0;
  char c = getchar();
  while (c < '0' && '9' < c) {
    f |= (f == '-');
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  x = f ? -x : x;
  return;
}
int bel[15];
char s[15];
void query(int m) {
  printf("next");
  for (int i = 0; i < m; i++) printf(" %d", i);
  puts("");
  fflush(stdout);
  int k;
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    scanf("%s", s + 1);
    for (int j = strlen(s + 1); j; j--) bel[s[j] - '0'] = i;
  }
}
int main() {
  while (1) {
    query(2);
    query(1);
    if (bel[0] == bel[1]) break;
  }
  while (1) {
    query(10);
    if (bel[0] == bel[2]) break;
  }
  printf("done");
  return 0;
}
