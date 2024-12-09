#include <bits/stdc++.h>
using namespace std;
int n;
string s;
bool sw, sw1;
vector<int> v;
int main() {
  sw = sw1 = false;
  getline(cin, s);
  s.push_back(' ');
  n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == '"') {
      v.push_back(i);
      sw = !sw;
    } else if (!sw && sw1 && s[i] == ' ') {
      sw1 = false;
      v.push_back(i);
    } else if (!sw && !sw1 && s[i] != ' ') {
      v.push_back(i);
      sw1 = true;
    }
  }
  for (int i = 0; i < v.size(); i += 2) {
    cout << "<";
    for (int j = v[i]; j < v[i + 1]; j++)
      if (s[j] != '"') cout << s[j];
    cout << ">" << endl;
  }
  return 0;
}
