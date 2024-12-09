#include <bits/stdc++.h>
using namespace std;
string s, s1[20], s2, s3;
int a, mx, pos;
bool e;
vector<pair<int, int> > v;
int main() {
  cin >> s >> a;
  for (int i = 1; i <= a; i++) cin >> s1[i];
  sort(s1 + 1, s1 + a + 1);
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= a; j++) {
      if (s1[i].size() <= s1[j].size() and i != j)
        for (int g = 0; g <= s1[j].size() - s1[i].size(); g++) {
          for (int h = 0; h < s1[i].size(); h++)
            if (s1[j][g + h] != s1[i][h]) {
              e = 1;
              break;
            }
          if (e == 0) {
            s1[j] = "#";
            break;
          }
          e = 0;
        }
    }
  }
  e = 0;
  for (int i = 1; i <= a; i++) {
    if (s.size() >= s1[i].size() and s1[i] != "#")
      for (int j = 0; j <= s.size() - s1[i].size(); j++) {
        for (int h = 0; h < s1[i].size(); h++)
          if (s[j + h] != s1[i][h]) {
            e = 1;
            break;
          }
        if (e == 0) v.push_back(make_pair(j, s1[i].size() + j - 1));
        e = 0;
      }
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  int x = 0;
  for (int i = 0; i < v.size(); i++)
    if (v[i].first != -1) {
      if (v[i].second - 1 - x + 1 > mx) {
        mx = v[i].second - 1 - x + 1;
        pos = x;
      }
      x = v[i].first + 1;
    }
  if (s.size() - 1 - x + 1 > mx) mx = s.size() - 1 - x + 1, pos = x;
  cout << mx << ' ' << pos << endl;
  return 0;
}
