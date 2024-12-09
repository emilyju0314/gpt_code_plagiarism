#include <bits/stdc++.h>
using namespace std;
const int inf = 1999999999;
const double pi = acos(-1.0);
const double eps = 1e-10;
char gc() {
  char c;
  while (isspace(c = getchar()))
    ;
  return c;
}
int gs(char* s) {
  gets(s);
  int l = strlen(s);
  while (l && isspace(s[l - 1])) s[--l] = 0;
  return l;
}
bool nok[110];
int main() {
  ios::sync_with_stdio(false);
  string s, ls;
  vector<string> vs;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string t;
    cin >> t;
    vs.push_back(t);
  }
  cin >> s;
  string t;
  cin >> t;
  for (int i = 0; i < ((int)(vs).size()); i++)
    for (int j = 0; j < ((int)(vs[i]).size()); j++)
      vs[i][j] = tolower(vs[i][j]);
  ls = s;
  for (int i = 0; i < ((int)(ls).size()); i++) ls[i] = tolower(ls[i]);
  for (int i = 0; i < ((int)(vs).size()); i++) {
    int p = 0;
    while (true) {
      p = ls.find(vs[i], p);
      if (p == -1) break;
      for (int j = 0; j < ((int)(vs[i]).size()); j++) nok[j + p] = true;
      p++;
    }
  }
  for (int i = 0; i < ((int)(s).size()); i++) {
    if (nok[i]) {
      if (ls[i] == t[0]) {
        if (t[0] != 'a') {
          if (s[i] >= 'a' && s[i] <= 'z')
            putchar('a');
          else
            putchar('A');
        } else {
          if (s[i] >= 'a' && s[i] <= 'z')
            putchar('b');
          else
            putchar('B');
        }
      } else {
        if (s[i] >= 'a' && s[i] <= 'z')
          putchar(t[0]);
        else
          putchar(t[0] - 'a' + 'A');
      }
    } else
      putchar(s[i]);
  }
  putchar('\n');
  return 0;
}
