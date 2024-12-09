#include <bits/stdc++.h>
using namespace std;
string st;
bool ispal(string st) {
  string st1 = st;
  reverse(st.begin(), st.end());
  return (st == st1);
}
string solve(string st) {
  for (int i = 0; i <= st.size(); i++)
    for (int ah = 'a'; ah <= 'z'; ah++) {
      string st1 = st;
      st1.insert(st1.begin() + i, ah);
      if (ispal(st1)) return st1;
    }
  return "NA";
}
int main() {
  string st;
  cin >> st;
  cout << solve(st) << endl;
}
