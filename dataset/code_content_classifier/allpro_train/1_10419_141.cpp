#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long int n = s.length();
  vector<string> v;
  string t = "";
  for (long long int i = 0; i < n; i++) {
    if (s[i] != '.') {
      t += s[i];
    } else {
      v.push_back(t);
      t = "";
    }
  }
  v.push_back(t);
  if (v.size() == 1) {
    cout << "NO" << endl;
  } else if (s[0] != '.' && v[0].length() < 9) {
    for (int i = 1; i < v.size() - 1; i++) {
      if (v[i].length() < 2 || v[i].length() > 11) {
        cout << "NO" << endl;
        return 0;
      }
    }
    if (v[v.size() - 1].length() == 0 || v[v.size() - 1].length() > 3) {
      cout << "NO" << endl;
      return 0;
    }
    cout << "YES" << endl;
    cout << v[0] << ".";
    for (int i = 1; i < v.size() - 1; i++) {
      if (v[i].length() > 8) {
        cout << v[i].substr(0, 3) << endl;
        cout << v[i].substr(3, v[i].length()) << ".";
      } else {
        cout << v[i][0] << endl;
        cout << v[i].substr(1, v[i].length()) << ".";
      }
    }
    cout << v[v.size() - 1];
  } else {
    cout << "NO" << endl;
  }
}
