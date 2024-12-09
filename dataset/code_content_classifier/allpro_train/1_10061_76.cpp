#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v;
    int i = 1;
    while (n / i) {
      int tmp = n / i;
      v.push_back(tmp);
      i = n / tmp + 1;
    }
    v.push_back(0);
    cout << v.size() << endl;
    for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
    cout << endl;
  }
  return 0;
}
