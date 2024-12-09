#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[105][105];
  int T, a[105];
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    scanf("%d", a + i);
  }
  getchar();
  for (int i = 0; i < T; i++) {
    gets(s[i]);
  }
  int zz = 0, cc = 0;
  for (int i = 0; i < T; i++) {
    zz = 0;
    int t = strlen(s[i]);
    for (int j = 0; j < t; j++) {
      if (s[i][j] == 'a' || s[i][j] == 'e' || s[i][j] == 'i' ||
          s[i][j] == 'o' || s[i][j] == 'u' || s[i][j] == 'y')
        zz++;
    }
    if (zz == a[i]) cc++;
  }
  if (cc == T)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
