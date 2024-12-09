#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[2 * n];
    for (int i = 0; i < 2 * n; i++) {
      cin >> arr[i];
    }
    vector<long int> o;
    vector<long int> e;
    for (int i = 0; i < 2 * n; i++) {
      if (arr[i] % 2 == 0) {
        e.push_back(i + 1);
      } else {
        o.push_back(i + 1);
      }
    }
    if (e.size() % 2 == 1) {
      e.pop_back();
      o.pop_back();
    } else {
      if (e.size() != 0) {
        e.pop_back();
        e.pop_back();
      } else {
        o.pop_back();
        o.pop_back();
      }
    }
    for (int i = 0; i < e.size(); i += 2) {
      cout << e[i] << " " << e[i + 1] << endl;
    }
    for (int i = 0; i < o.size(); i += 2) {
      cout << o[i] << " " << o[i + 1] << endl;
    }
  }
}
