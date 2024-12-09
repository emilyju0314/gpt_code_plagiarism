#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int n, res = 0;
  ;
  bool l, r, u, d;
  cin >> n;
  vector<pair<int, int> > vec;
  vec.resize(n);
  for (int i = 0; i < n; i++) cin >> vec[i].first >> vec[i].second;
  for (int i = 0; i < n; i++) {
    l = r = u = d = 0;
    for (int j = 0; j < n; j++) {
      if (vec[j].first < vec[i].first && vec[j].second == vec[i].second)
        l = 1;
      else if (vec[j].first > vec[i].first && vec[j].second == vec[i].second)
        r = 1;
      else if (vec[j].first == vec[i].first && vec[j].second < vec[i].second)
        d = 1;
      else if (vec[j].first == vec[i].first && vec[j].second > vec[i].second)
        u = 1;
      if (l == 1 && u == 1 && d == 1 && r == 1) {
        res++;
        break;
      }
    }
  }
  cout << res;
  return 0;
}
