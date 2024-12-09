#include <bits/stdc++.h>
using namespace std;
set<int> st;
int main() {
  int button, bulb, x;
  cin >> button >> bulb;
  for (int i = 0; i < button; i++) {
    int b;
    cin >> b;
    for (int j = 0; j < b; j++) {
      cin >> x;
      st.insert(x);
    }
  }
  if (st.size() != bulb)
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}
