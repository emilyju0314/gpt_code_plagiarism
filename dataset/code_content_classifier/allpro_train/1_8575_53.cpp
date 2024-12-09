#include <bits/stdc++.h>
using namespace std;
string s;
vector<pair<int, char> > v(27);
int n, z;
int main() {
  cin >> s >> n;
  for (int i = 0; i < s.size(); i++) {
    v[s[i] - 'a'].first++, v[s[i] - 'a'].second = s[i];
    if (v[s[i] - 'a'].first == 1) z++;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++)
    if (v[i].first != 0 and v[i].first <= n) {
      n -= v[i].first, v[i].first = 0, z--;
      for (int j = 0; j < s.size(); j++)
        if (s[j] == v[i].second) s[j] = '*';
    }
  cout << z << endl;
  for (int i = 0; i < s.size(); i++)
    if (s[i] != '*') cout << s[i];
  return 0;
}
