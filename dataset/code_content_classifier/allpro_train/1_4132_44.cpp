#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int D;
  cin >> D;

  vector<int> C(26);
  rep(i, 26) {
    cin >> C.at(i);
  }

  vector<int> T(D);
  rep(i, D) {
    int max = 0;
    rep(j, 26) {
      int s;
      cin >> s;
      if (max <= s) {
        max = s;
        T.at(i) = j + 1;
      }
    }
  }

  rep(i, D) {
    cout << T.at(i) << endl;
  }
}
