#include <bits/stdc++.h>
using namespace std;
const int inv = 2000000000;
const int minv = -inv;
int fgcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return fgcd(b % a, a);
}
int l[2], r[2], t[2];
int len[2];
int el[2];
int process(int d, bool type) {
  if (type)
    return max(d - (len[1] - len[0]), 0);
  else
    return d;
}
int main() {
  for (int i = 0; i < 2; ++i) {
    scanf("%d", &l[i]);
    scanf("%d", &r[i]);
    scanf("%d", &t[i]);
    len[i] = r[i] - l[i] + 1;
  }
  if (len[0] > len[1]) {
    swap(l[0], l[1]);
    swap(r[0], r[1]);
    swap(t[0], t[1]);
    swap(len[0], len[1]);
  }
  int g = fgcd(t[0], t[1]);
  for (int i = 0; i < 2; ++i) el[i] = (l[i] % g);
  int q = inv;
  if (el[0] == el[1])
    q = 0;
  else if (el[0] > el[1]) {
    q = min(q, process(el[0] - el[1], true));
    q = min(q, process(el[1] + g - el[0], false));
  } else {
    q = min(q, process(el[0] + g - el[1], true));
    q = min(q, process(el[1] - el[0], false));
  }
  printf("%d\n", max(len[0] - q, 0));
  return 0;
}
