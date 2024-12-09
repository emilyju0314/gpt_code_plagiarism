#include <bits/stdc++.h>
using namespace std;
int d1[200100];
int d2[200100];
int pos[200100][26];
int main() {
  string s, t;
  getline(cin, s);
  getline(cin, t);
  for (int i = 0; i < int(26); i++) pos[0][i] = -1;
  pos[0][int(t[0]) - 'a'] = 0;
  for (int i = 1; i <= t.size(); i++) {
    for (int j = 0; j < int(26); j++) pos[i][j] = pos[i - 1][j];
    if (i < t.size()) pos[i][int(t[i]) - 'a'] = i;
  }
  int maxx = 0;
  for (int i = 0; i < int(s.size()); i++) {
    int k = pos[maxx][int(s[i]) - 'a'];
    d1[i] = k + 1;
    maxx = max(maxx, k + 1);
  }
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  for (int i = 0; i < int(26); i++) pos[0][i] = -1;
  pos[0][int(t[0]) - 'a'] = 0;
  for (int i = 1; i <= t.size(); i++) {
    for (int j = 0; j < int(26); j++) pos[i][j] = pos[i - 1][j];
    if (i < t.size()) pos[i][int(t[i]) - 'a'] = i;
  }
  maxx = 0;
  for (int i = 0; i < int(s.size()); i++) {
    int k = pos[maxx][int(s[i]) - 'a'];
    d2[i] = k + 1;
    maxx = max(maxx, k + 1);
  }
  bool q = true;
  for (int i = 0; i < int(s.size()); i++) {
    if ((d1[i] + d2[s.size() - i - 1]) <= t.size()) q = false;
  }
  if (q)
    cout << "Yes";
  else
    cout << "No" << endl;
  return 0;
}
