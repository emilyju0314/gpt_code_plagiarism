#include <bits/stdc++.h>
using namespace std;
const long long int maxn = 1000000000;
const long long int mod = 1e9 + 7;
int main() {
  long long int n, m;
  scanf("%lld", &n), scanf("%lld", &m);
  map<string, long long int> make_pair;
  string s;
  for (long long int i = 0; i < n; i++) {
    cin >> s;
    make_pair[s]++;
  }
  set<long long int> col;
  for (map<string, long long int>::iterator it = make_pair.begin();
       it != make_pair.end(); ++it) {
    s = it->first;
    for (long long int i = 0; i < m; i++) {
      if (s[i] == '#') {
        if (col.find(i) != col.end()) {
          cout << "No" << endl;
          return 0;
        } else {
          col.insert(i);
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
