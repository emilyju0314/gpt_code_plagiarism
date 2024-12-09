#include <bits/stdc++.h>
using namespace std;
int al[26][26], bl[26][26];
string a, b;
int get() {
  int ret = 0, i;
  for (i = 0; i < a.size(); ++i)
    if (a[i] != b[i]) ++ret;
  return ret;
}
int main() {
  int n, i, k, j;
  cin >> n >> a >> b;
  memset(al, -1, sizeof(al));
  for (i = 0; i < n; ++i)
    if (a[i] != b[i] && al[a[i] - 'a'][b[i] - 'a'] == -1) {
      al[a[i] - 'a'][b[i] - 'a'] = i;
    }
  int x = -1, y = -1;
  for (i = 0; i < 26; ++i)
    for (j = i + 1; j < 26; ++j)
      if (al[i][j] != -1 && al[j][i] != -1) {
        x = al[i][j], y = al[j][i];
        swap(a[x], a[y]);
        cout << get() << endl;
        cout << x + 1 << " " << y + 1 << endl;
        return 0;
      }
  for (i = 0; i < 26; ++i)
    for (j = 0; j < 26; ++j)
      for (k = 0; k < 26; ++k)
        if (al[i][j] != -1 && al[j][k] != -1) {
          x = al[i][j], y = al[j][k];
          swap(a[x], a[y]);
          cout << get() << endl;
          cout << x + 1 << " " << y + 1 << endl;
          return 0;
        }
  cout << get() << endl;
  cout << x << " " << y << endl;
}
