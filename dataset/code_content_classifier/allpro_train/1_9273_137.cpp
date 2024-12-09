#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, i, j, k, p, s = 10e6;
  cin >> x;
  char n[x + 1];
  cin >> n;
  char a[] = "RBG", b[] = "RGB", c[] = "BRG", d[] = "BGR", e[] = "GRB",
       f[] = "GBR";
  char ch[4] = {};
  p = 0;
  for (i = 0; i < x; i++) {
    if (n[i] != a[i % 3]) p++;
  }
  if (p < s) {
    s = p;
    strcpy(ch, a);
  }
  p = 0;
  for (i = 0; i < x; i++) {
    if (n[i] != b[i % 3]) p++;
  }
  if (p < s) {
    s = p;
    strcpy(ch, b);
  }
  p = 0;
  for (i = 0; i < x; i++) {
    if (n[i] != c[i % 3]) p++;
  }
  if (p < s) {
    s = p;
    strcpy(ch, c);
  }
  p = 0;
  for (i = 0; i < x; i++) {
    if (n[i] != d[i % 3]) p++;
  }
  if (p < s) {
    s = p;
    strcpy(ch, d);
  }
  p = 0;
  for (i = 0; i < x; i++) {
    if (n[i] != e[i % 3]) p++;
  }
  if (p < s) {
    s = p;
    strcpy(ch, e);
  }
  p = 0;
  for (i = 0; i < x; i++) {
    if (n[i] != f[i % 3]) p++;
  }
  if (p < s) {
    s = p;
    strcpy(ch, f);
  }
  for (i = 0; i < x; i++) {
    if (n[i] != ch[i % 3]) n[i] = ch[i % 3];
  }
  cout << s << endl;
  cout << n << endl;
}
