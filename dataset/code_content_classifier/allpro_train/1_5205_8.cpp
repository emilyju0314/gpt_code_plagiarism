#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  stack<char> st;
  string s;
  int n, cnt = 0;
  cin >> n >> s;
  for (int i = 0; i < s.size(); i++) {
    if (!st.empty() && s[i] == ')')
      st.pop();
    else if (s[i] == '(')
      st.push('(');
    else if (st.empty() && s[i] == ')')
      cnt++;
  }
  if ((st.empty() && !cnt) || (st.size() == 1 && cnt == 1))
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
