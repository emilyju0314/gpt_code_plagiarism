#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d = 0;
  char s[105];
  cin >> s;
  a = strlen(s);
  for (b = 1; b < a; b++) {
    if (s[b] >= 65 && s[b] <= 90) {
      d++;
    }
  }
  if (d == a - 1) {
    for (b = 0; b < a; b++) {
      if (s[b] >= 65 && s[b] <= 90) {
        s[b] += (97 - 65);
      } else
        s[b] -= (97 - 65);
    }
    cout << s << endl;
  } else
    cout << s << endl;
  return 0;
}
