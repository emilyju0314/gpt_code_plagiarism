#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n;
  string q, s;
  set<string> st;
  cin >> n;
  while (n--) {
    cin >> q >> s;
    if (q[0] == 'i') st.insert(s);
    else if (st.count(s)) cout << "yes\n";
    else cout << "no\n";
  }
}
