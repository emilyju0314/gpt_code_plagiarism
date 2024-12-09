#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    string s;
    cin >> s;
    if (s[0] == '@' || s[(long long)s.size() - 1] == '@') {
      cout << "No solution";
      return 0;
    }
    vector<long long> pos;
    for (long long i = 0; i < (long long)s.size(); i++) {
      if (s[i] == '@') pos.push_back(i);
    }
    if ((long long)pos.size() == 0) {
      cout << "No solution";
      return 0;
    } else if ((long long)pos.size() == 1) {
      cout << s;
      return 0;
    }
    pos.push_back((long long)s.size() + 1);
    for (long long i = 0; i < (long long)pos.size() - 1; i++) {
      if (-pos[i] + pos[i + 1] > 2) {
        ;
      } else {
        cout << "No solution";
        return 0;
      }
    }
    long long count = 0;
    for (long long i = 0; i < (long long)s.size() - 2; i++) {
      if (i >= pos[(long long)pos.size() - 2] + count) break;
      if (s[i] == '@') {
        s.insert(s.begin() + i + 2, ',');
        count++;
      }
    }
    cout << s << '\n';
  }
  return 0;
}
