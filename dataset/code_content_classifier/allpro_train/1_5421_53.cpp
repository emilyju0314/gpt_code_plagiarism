#include <bits/stdc++.h>
using namespace std;
int t, n, m, tmp, cnt, b, a, x, y;
string s[101], tt;
char ltr[5] = "abba";
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    printf("%c", ltr[i % 4]);
  }
  return 0;
}
