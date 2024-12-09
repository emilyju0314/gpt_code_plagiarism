#include <bits/stdc++.h>
using namespace std;
int main() {
  for (int n; cin >> n;) {
    vector<int> r;
    int s = 0, negs = 0;
    for (int i = 0; i < n; i++) {
      int ai;
      cin >> ai;
      if (ai < 0 && ++negs >= 3) {
        r.push_back(s);
        s = 1;
        negs = 1;
      } else
        s++;
    }
    if (s > 0) r.push_back(s);
    cout << r.size() << endl;
    for (int i = 0; i < r.size(); i++)
      cout << r[i] << (i == r.size() - 1 ? "" : " ");
    cout << endl;
  }
}
