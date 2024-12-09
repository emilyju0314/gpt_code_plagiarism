#include <bits/stdc++.h>
using namespace std;
int l1, l2, src[200100], tar[200100], nxt[200100], ans;
void sread() {
  scanf("%d%d", &l2, &l1);
  for (int i = 0; i < (l2); ++i) scanf("%d", tar + i);
  for (int i = 0; i < (l1); ++i) scanf("%d", src + i);
  --l1, --l2;
  if (!l1) return;
  for (int i = 0; i < (l1); ++i) src[i] = src[i] - src[i + 1];
  for (int i = 0; i < (l2); ++i) tar[i] = tar[i] - tar[i + 1];
  src[l1 + 1] = 0x1f1f1f1f;
}
void getnxt() {
  nxt[1] = 0;
  int t = 0, i = 1;
  while (i <= l1) {
    while (t && src[i - 1] != src[t - 1]) t = nxt[t];
    ++i, ++t;
    nxt[i] = src[i - 1] == src[t - 1] ? nxt[t] : t;
  }
  while (t && src[i - 1] != src[t - 1]) t = nxt[t];
  ++i, ++t;
  nxt[i] = t;
}
void match() {
  for (int i = 1, j = 0; l1 + 1 - i <= l2 - j;) {
    if (src[i - 1] == tar[j]) {
      ++i, ++j;
      if (i > l1) {
        ++ans;
        i = nxt[i];
        if (!i) ++i, ++j;
      }
    } else {
      i = nxt[i];
      if (!i) ++i, ++j;
    }
  }
}
int main(int argc, char **argv) {
  sread();
  if (!l1) {
    printf("%d\n", l2 + 1);
    return 0;
  }
  getnxt();
  match();
  printf("%d\n", ans);
  return 0;
}
