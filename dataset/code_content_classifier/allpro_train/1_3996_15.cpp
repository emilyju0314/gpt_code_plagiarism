#include <bits/stdc++.h>
using namespace std;
void ti() {}
void print(vector<int> m) {
  vector<int>::iterator i = m.begin();
  while (i != m.end()) {
    cout << *i << " ";
    i++;
  }
  cout << endl;
}
int main() {
  ti();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    set<int> sl;
    for (int i = 1; i <= n; i++) {
      sl.insert(i);
    }
    vector<int> v;
    while (n--) {
      int a;
      cin >> a;
      v.push_back(a);
    }
    vector<int> vq = {v[0]};
    sl.erase(v[0]);
    bool t2 = true;
    for (int i = 1; i < v.size(); i++) {
      if (v[i] > v[i - 1]) {
        vq.push_back(v[i]);
        sl.erase(v[i]);
      } else if (v[i] == v[i - 1]) {
        bool t1 = true;
        auto s1 = sl.begin();
        while (s1 != sl.end()) {
          if (*s1 < v[i]) {
            vq.push_back(*s1);
            sl.erase(*s1);
            t1 = false;
            break;
          }
          s1++;
        }
        if (t1) {
          t2 = false;
          break;
        }
      }
    }
    if (t2) {
      print(vq);
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
