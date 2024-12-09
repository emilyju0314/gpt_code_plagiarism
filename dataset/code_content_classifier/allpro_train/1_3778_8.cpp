#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[200];
  int a[200];
  while (~scanf("%s", s)) {
    memset(a, 0, sizeof(a));
    int len = strlen(s);
    int num = 0;
    for (int i = 0; i < len - 1; i++) {
      if (s[i] == 'V' && s[i + 1] == 'K') {
        a[i] = a[i + 1] = 1;
        num++;
        i++;
      }
    }
    for (int i = 0; i < len - 1; i++) {
      if ((s[i] == 'V' || s[i + 1] == 'K') && a[i] == 0 && a[i + 1] == 0) {
        num++;
        break;
      }
    }
    cout << num << endl;
  }
  return 0;
}
