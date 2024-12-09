#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, i, j, k;
  cin >> n >> m;
  vector<string> name(n), store;
  for (i = 0; i < n; i++) {
    cin >> name[i];
  }
  map<string, map<string, bool>> M;
  for (i = 0; i < m; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    M[s1][s2] = true;
    M[s2][s1] = true;
  }
  for (i = 0; i < (1 << n); i++) {
    vector<string> check;
    for (j = 0; j < n; j++) {
      if (i & (1 << j)) {
        check.push_back(name[j]);
      }
    }
    bool f = true;
    for (k = 0; k < check.size(); k++) {
      for (j = k + 1; j < check.size(); j++) {
        if (M[check[k]][check[j]]) {
          f = false;
        }
      }
    }
    if (f && check.size() > store.size()) store = check;
  }
  sort(store.begin(), store.end());
  cout << store.size() << endl;
  for (i = 0; i < store.size(); i++) {
    cout << store[i] << endl;
  }
}
