#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, deque<int> > m;
  int k;
  string s, t;
  cin >> k >> s;
  for (int i = 0; i < k; i++) t += s;
  for (int i = 0; i < t.size(); i++) m[t[i]].push_back(i);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int p;
    char c;
    cin >> p >> c;
    int index = m[c][p - 1];
    t[index] = '1';
    m[c].erase(m[c].begin() + (p - 1));
  }
  t.erase(remove(t.begin(), t.end(), '1'), t.end());
  cout << t << endl;
  return 0;
}
