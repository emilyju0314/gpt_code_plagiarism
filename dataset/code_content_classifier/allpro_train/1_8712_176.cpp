#include <bits/stdc++.h>
using namespace std;
int n;
int a[212345];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<vector<int> > data;
  data.push_back({a[0]});
  for (int i = 1; i < n; i++) {
    int sz = data.size();
    int val = a[i];
    if (val > data[0].back())
      data[0].push_back(val);
    else if (val < data[sz - 1].back())
      data.push_back({val});
    else {
      int l = 0;
      int r = sz - 1;
      while (l < r) {
        int mid = (l + r) / 2;
        if (data[mid].back() < val)
          r = mid;
        else
          l = mid + 1;
      }
      data[l].push_back(val);
    }
  }
  for (vector<int> d : data) {
    for (int v : d) cout << v << " ";
    cout << "\n";
  }
}
