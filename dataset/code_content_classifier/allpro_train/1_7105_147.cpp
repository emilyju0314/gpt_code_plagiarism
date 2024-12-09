#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
void solving() {
  string s;
  cin >> s;
  stack<char> st;
  long long int c = 0;
  for (long long int i = 0; i < (long long int)s.size(); i++) {
    if ((long long int)st.size() == 0)
      st.push(s[i]);
    else {
      if (st.top() == s[i])
        st.pop(), c++;
      else
        st.push(s[i]);
    }
  }
  if (c % 2 == 0)
    cout << "No"
         << "\n";
  else
    cout << "Yes"
         << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solving();
  return 0;
}
