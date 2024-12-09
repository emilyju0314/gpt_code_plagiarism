#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  for (int case_no = 1; case_no <= tc; case_no++) {
    string s;
    cin >> s;
    vector<int> indices;
    for (int i = 0; i + 2 < s.size(); i++) {
      if (i + 4 < s.size()) {
        if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' &&
            s[i + 3] == 'n' && s[i + 4] == 'e') {
          s[i + 2] = 'x';
          indices.push_back(i + 2);
        }
      }
      if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') {
        s[i + 1] = 'x';
        indices.push_back(i + 1);
      }
      if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o') {
        s[i + 1] = 'x';
        indices.push_back(i + 1);
      }
    }
    cout << indices.size() << endl;
    for (int i = 0; i < indices.size(); i++) {
      if (i != 0) cout << " ";
      cout << 1 + indices[i];
    }
    cout << endl;
  }
  return 0;
}
