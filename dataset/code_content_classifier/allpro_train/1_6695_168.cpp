#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t, n, s1, s2;
  bool flag = true;
  cin >> t >> n;
  set<int> st;
  set<int>::iterator itr;
  for (int i = 0; i < t; i++) {
    cin >> s1 >> s2;
    if (i == 0) {
      st.insert(s1);
      st.insert(s2);
      st.insert(7 - s1);
      st.insert(7 - s2);
    } else {
      if (st.find(s1) == st.end() || st.find(s2) == st.end()) {
        flag = false;
        break;
      }
    }
  }
  if (flag)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
