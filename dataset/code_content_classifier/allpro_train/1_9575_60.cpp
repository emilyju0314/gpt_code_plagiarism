#include <bits/stdc++.h>
using namespace std;
int n, seq[1000001], m;
set<int> r;
string s;
int main() {
  cin >> n >> m;
  cin.get();
  for (int i = 1; i < n + 1; i++) r.insert(i);
  set<int>::iterator it;
  while (m--) {
    getline(cin, s);
    if (s[7] == 'r') {
      int t = 0;
      for (int j = 16; j < s.size(); j++) t *= 10, t += (s[j] - 48);
      it = r.end();
      it--;
      if (t >= *it) {
        cout << -1 << endl;
        return 0;
      }
      for (int i = 1; i < t + 1; i++) r.erase(i);
    }
    if (s[7] == 'l') {
      int t = 0;
      for (int j = 15; j < s.size(); j++) t *= 10, t += (s[j] - 48);
      if (t <= *r.begin()) {
        cout << -1 << endl;
        return 0;
      }
      for (int i = t; i < n + 1; i++) r.erase(i);
    }
  }
  cout << r.size() << endl;
  return 0;
}
