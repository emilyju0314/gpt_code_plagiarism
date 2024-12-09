#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string input;
  cin >> n;
  map<string, int> M;
  int k = 1;
  for (int i = 0; i < n; i++, k++) {
    cin >> input;
    M[input] = k;
  }
  set<pair<int, string> > S;
  for (map<string, int>::iterator it = M.begin(); it != M.end(); it++) {
    S.insert(make_pair(it->second, it->first));
  }
  set<pair<int, string> >::iterator temp = S.end();
  temp--;
  for (set<pair<int, string> >::iterator it = temp;; it--) {
    cout << it->second << endl;
    if (it == S.begin()) break;
  }
  return 0;
}
