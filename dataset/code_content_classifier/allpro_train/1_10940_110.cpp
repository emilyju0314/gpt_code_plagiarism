#include <bits/stdc++.h>
using namespace std;
char c[100005];
int n, m;
int main() {
  int i, j, a;
  n = 0;
  m = 0;
  cin >> c;
  n = strlen(c);
  for (i = 0; i < n; i++) {
    a = 0;
    for (j = 0; j < i; j++) {
      if (c[i] == c[j]) {
        a = 1;
        break;
      }
    }
    if (a == 0) m++;
  }
  if (m % 2 == 0)
    cout << "CHAT WITH HER!";
  else
    cout << "IGNORE HIM!";
  return 0;
}
