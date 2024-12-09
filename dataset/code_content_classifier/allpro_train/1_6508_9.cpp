#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n = 0, i = 0, co = 0, cc = 0, ans = 0;
  cin >> n;
  string s;
  cin >> s;
  for (i = 0; i < s.length(); i++) {
    if (s[i] == '(')
      co++;
    else
      cc++;
  }
  if (co != cc) {
    cout << "-1\n";
  } else {
    ans = 0;
    stack<char> st;
    for (i = 0; i < n; i++) {
      if (st.empty()) {
        st.push(s[i]);
      } else if (st.top() == '(') {
        if (s[i] == ')')
          st.pop();
        else
          st.push(s[i]);
      } else {
        if (s[i] == ')')
          st.push(s[i]);
        else {
          st.pop();
          ans += 2;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
