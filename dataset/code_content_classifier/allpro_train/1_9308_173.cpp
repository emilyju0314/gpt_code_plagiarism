#include <bits/stdc++.h>
using namespace std;
inline void pisz(int n) { printf("%d\n", n); }
template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  for (int(i) = 0; (i) < (((int)((t).size()))); ++(i)) s << t[i] << " ";
  return s;
}
int main() {
  int(n);
  cin >> (n);
  ;
  set<string> st;
  unordered_map<string, string> m;
  vector<string> ans;
  for (int(i) = 0; (i) < (n); ++(i)) {
    string s1, s2;
    cin >> s1 >> s2;
    if (st.find(s1) == st.end()) {
      ans.push_back(s1);
    }
    st.insert(s2);
    m[s1] = s2;
  }
  cout << ans.size() << endl;
  for (auto s : ans) {
    cout << s << " ";
    string str = s;
    auto it = m.find(str);
    while (it != m.end()) {
      str = it->second;
      it = m.find(str);
    }
    cout << str << endl;
  }
  return 0;
}
