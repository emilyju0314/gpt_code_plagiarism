#include <bits/stdc++.h>
using namespace std;
vector<string> m;
int main() {
  int n, k;
  cin >> n >> k;
  int e = 0;
  for (int i = 1; i < k; i++) {
    string t = "";
    t += char('A' + e / 26);
    t += char('a' + e % 26);
    e++;
    m.push_back(t);
  }
  for (int i = k; i <= n; i++) {
    string s;
    cin >> s;
    if (s == "YES") {
      string t = "";
      t += char('A' + e / 26);
      t += char('a' + e % 26);
      e++;
      m.push_back(t);
    } else {
      m.push_back(m[i - k]);
    }
  }
  for (string &s : m) std::cout << s << " ";
}
