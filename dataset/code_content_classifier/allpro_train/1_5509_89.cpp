#include <bits/stdc++.h>
using namespace std;
string t[100005];
int n, m;
int num[1000005];
pair<int, int> p[2 * 1000005];
char s[2 * 1000005];
int main() {
  scanf("%d", &n);
  int maxlen = 0;
  memset(s, 0, sizeof(s));
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    scanf("%d", &m);
    for (int j = 0; j < m; j++) scanf("%d", &num[j]);
    for (int j = 0; j < m; j++) {
      maxlen = max(maxlen, num[j] + (int)t[i].length() - 1);
      if (p[num[j]].second == 0)
        p[num[j]] = make_pair(i, t[i].length());
      else if (p[num[j]].second < (int)t[i].length())
        p[num[j]] = make_pair(i, t[i].length());
    }
  }
  int mark = 1;
  for (int i = 1; i <= maxlen; i++) {
    if (s[i] == 0) mark = i;
    if (p[i].second > 0) {
      for (int j = mark; j <= i + p[i].second - 1; j++)
        s[j] = t[p[i].first][j - i];
      mark = max(mark, p[i].second + i - 1);
    } else if (s[i] == 0)
      s[i] = 'a';
  }
  for (int i = 1; i <= maxlen; i++) printf("%c", s[i]);
  cout << endl;
}
