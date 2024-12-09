#include <bits/stdc++.h>
char a[112345];
char b[112], c[112];
int base[112];
int temp[112345];
void reverse(char *a) {
  int i, o, p, j, k;
  k = strlen(a);
  for (i = 0, o = k - 1; i <= o; ++i) {
    p = a[i];
    a[i] = a[o];
    a[o] = p;
    --o;
  }
}
int find(char *s, char *t, int flag) {
  int i, o, p, j, k, l, n, m;
  int st, add, back, tt, l_s = strlen(s), l_t = strlen(t);
  if (flag == 1) {
    st = 0;
    add = 1;
  } else {
    st = strlen(s) - strlen(t);
    add = -1;
  }
  back = strlen(s) - strlen(t);
  if (back < 0) return -1;
  l = strlen(t);
  temp[back] = 0;
  for (i = back, j = 0; i < l_s; ++i, ++j) temp[back] += s[i] * base[j];
  for (i = back - 1; i >= 0; --i) {
    p = temp[i + 1] - s[i + l] * base[l - 1];
    p = p * 7;
    temp[i] = p + s[i];
  }
  tt = 0;
  for (i = 0; i < l; ++i) tt += t[i] * base[i];
  while ((st >= 0) && (st < l_s) && (st + l_t <= l_s)) {
    {
      p = s[st + l];
      s[st + l] = 0;
      if (strcmp(s + st, t) == 0) {
        s[st + l] = p;
        return (st);
      }
      s[st + l] = p;
    }
    st += add;
  }
  return -1;
}
int main() {
  int i;
  base[0] = 1;
  for (i = 1; i < 112; ++i) base[i] = base[i - 1] * 7;
  scanf("%s", a);
  scanf("%s", b);
  scanf("%s", c);
  int flag_f = 0, flag_b = 0;
  int t_b, t_c;
  t_b = find(a, b, 1);
  t_c = find(a, c, -1);
  if ((t_b >= 0) && (t_c >= 0) && (t_b + strlen(b) - 1 < t_c)) flag_f = 1;
  reverse(a);
  t_b = find(a, b, 1);
  t_c = find(a, c, -1);
  if ((t_b >= 0) && (t_c >= 0) && (t_b + strlen(b) - 1 < t_c)) flag_b = 1;
  if (flag_f == 1 && flag_b == 1)
    printf("both\n");
  else if (flag_f == 1)
    printf("forward\n");
  else if (flag_b == 1)
    printf("backward\n");
  else
    printf("fantasy\n");
  return 0;
}
