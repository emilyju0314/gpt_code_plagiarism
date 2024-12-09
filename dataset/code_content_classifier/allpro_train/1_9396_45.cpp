#include <bits/stdc++.h>
using namespace std;
char s[200][200];
int main() {
  int n, m;
  cin >> m >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < 2 * m; ++i) {
    for (int j = 0; j < 2 * n; ++j) {
      printf("%c", s[j >> 1][i >> 1]);
    }
    puts("");
  }
  return 0;
}
