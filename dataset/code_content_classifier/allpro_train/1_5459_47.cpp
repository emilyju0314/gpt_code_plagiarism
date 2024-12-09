#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<char> v(n);
  for (int i = 0; i < n; i++) {
    v[i] = s[i];
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    cout << v[i];
  }
  cout << endl;
}
