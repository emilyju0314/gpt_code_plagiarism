#include <bits/stdc++.h>
using namespace std;
unordered_map<char, int> p;
unordered_set<char> a;
int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++) {
    p[s[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    a.insert(s[i]);
    if (a.size() > k) {
      cout << "YES" << endl;
      return 0;
    }
    if (p[s[i]] == i) a.erase(s[i]);
  }
  cout << "NO" << endl;
  return 0;
}
