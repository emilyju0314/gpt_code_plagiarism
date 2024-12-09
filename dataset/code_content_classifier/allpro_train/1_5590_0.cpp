#include <bits/stdc++.h>
using namespace std;
int main() {
  int kitten, F, I, T;
  string tmp;
  cin >> F >> I >> T;
  vector<vector<int> > M(F, vector<int>(I));
  for (int f = 0; f < F; ++f) {
    cin >> tmp;
    for (int i = 0; i < I; ++i) {
      M[f][i] = (tmp[i] == 'Y');
    }
  }
  int ans = 0;
  for (int i = 0; i < I; ++i) {
    int S = 0;
    for (int f = 0; f < F; ++f) {
      S += M[f][i];
    }
    if (S >= T) {
      ++ans;
    }
  }
  cout << ans;
  return 0;
}
