#include <bits/stdc++.h>
using namespace std;
inline int read() {
  static int r, sign;
  static char c;
  r = 0, c = getchar(), sign = 1;
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') sign = -1, c = getchar();
  while (c >= '0' && c <= '9') r = r * 10 + (c - '0'), c = getchar();
  return r * sign;
}
template <typename T>
inline void print(T* a, int n) {
  for (int i = 1; i < n; ++i) cout << a[i] << " ";
  cout << a[n] << endl;
}
int n, cnt = 0;
char s[250000 + 1], t[250000 + 1];
int main(int argc, char* argv[]) {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0, j; i < n; i = j) {
    for (j = i + 1; j < n && s[i] == s[j]; ++j)
      ;
    int len = j - i;
    if (len > 2) len = 2;
    if (cnt >= 2 && t[cnt - 1] == t[cnt - 2]) len = 1;
    while (len--) t[cnt++] = s[i];
  }
  printf("%s\n", t);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
