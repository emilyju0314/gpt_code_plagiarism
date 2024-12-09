#include <bits/stdc++.h>
using namespace std;
string a, b;
int c[26] = {0};
int main() {
  int i, j, y, n, m, k;
  cin >> a >> b;
  n = a.size();
  m = b.size();
  for (i = 0; i < n; i++) c[a[i] - 'a']++;
  k = m;
  for (i = 0; i < k && i < m; i++) {
    if (c[b[i] - 'a'] > 0)
      c[b[i] - 'a']--;
    else
      break;
  }
  if (i == k && n > k) {
    cout << b;
    for (j = 0; j < 26; j++)
      for (y = 0; y < c[j]; y++) printf("%c", j + 'a');
    cout << endl;
    return 0;
  }
  int q = 0;
  if (i == k) {
    i = k - 1;
    q = 1;
  }
  int I = i;
  for (; i >= 0; i--) {
    if (I != i || q) c[b[i] - 'a']++;
    for (y = b[i] + 1 - 'a'; y < 26; y++)
      if (c[y] > 0) break;
    if (y < 26) {
      for (j = 0; j < i; j++) cout << b[j];
      c[y]--;
      printf("%c", y + 'a');
      for (j = 0; j < 26; j++)
        for (y = 0; y < c[j]; y++) printf("%c", j + 'a');
      cout << endl;
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
