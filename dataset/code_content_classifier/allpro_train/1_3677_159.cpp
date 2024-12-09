#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  string s;
  getline(cin, s);
  set<char> st;
  int n = s.size();
  for (int i = 1; i < n - 1; i += 3) st.insert(s[i]);
  cout << st.size();
  return 0;
}
