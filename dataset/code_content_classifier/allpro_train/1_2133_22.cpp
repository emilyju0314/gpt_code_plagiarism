#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, w, sum = 0;
  cin >> n >> w;
  vector<pair<int, int> > v;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    int tut = ceil((double)a / 2.0);
    v.push_back(make_pair(a, tut));
    ans.push_back(a);
    sum += tut;
  }
  if (sum > w) {
    cout << "-1" << endl;
    return 0;
  }
  sort(v.rbegin(), v.rend());
  w -= sum;
  for (int i = 0; i < n; i++) {
    int tut = min(v[i].first - v[i].second, w);
    v[i].second += tut;
    w -= tut;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (ans[i] == v[j].first && v[j].second != -1) {
        cout << v[j].second << " ";
        v[j].second = -1;
        break;
      }
    }
  }
  cout << endl;
  return 0;
}
