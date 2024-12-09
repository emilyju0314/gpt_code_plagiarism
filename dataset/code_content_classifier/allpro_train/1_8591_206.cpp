#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s, temp;
  vector<string> vec(4 * n + 1);
  for (int j = 0; j < 4 * n; j++) {
    cin >> s;
    int cnt = 0;
    for (int i = s.length(); i >= 0; i--) {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
          s[i] == 'u') {
        ++cnt;
        if (cnt == k) {
          vec[j] = s.substr(i, s.length() - i);
          break;
        }
      }
    }
    if (cnt < k) {
      cout << "NO" << endl;
      return 0;
    }
  }
  set<string> st;
  for (int i = 0; i < 4 * n; i += 4) {
    if (vec[i] == vec[i + 1] && vec[i + 1] == vec[i + 2] &&
        vec[i + 2] == vec[i + 3]) {
      st.insert("aaaa");
      continue;
    }
    if (vec[i] == vec[i + 1] && vec[i + 2] == vec[i + 3]) {
      st.insert("aabb");
      continue;
    }
    if (vec[i] == vec[i + 2] && vec[i + 1] == vec[i + 3]) {
      st.insert("abab");
      continue;
    }
    if (vec[i] == vec[i + 3] && vec[i + 1] == vec[i + 2]) {
      st.insert("abba");
      continue;
    }
    cout << "NO" << endl;
    return 0;
  }
  if (st.size() > 2) {
    cout << "NO" << endl;
    return 0;
  }
  if (st.size() == 2) {
    auto it = st.begin();
    if (*it == "aaaa") {
      advance(it, 1);
      cout << *it << endl;
      return 0;
    }
    advance(it, 1);
    if (*it == "aaaa") {
      cout << *st.begin() << endl;
      return 0;
    }
    cout << "NO" << endl;
    return 0;
  }
  if (st.size() == 1) {
    cout << *st.begin() << endl;
  }
}
