#include <bits/stdc++.h>
using namespace std;
int n;
double ans;
vector<int> vec[1001000];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vec[x].push_back(i);
  }
  for (int i = 1; i <= 1000000; i++) {
    double cnt = 0;
    for (int j = 0; j < vec[i].size(); j++) {
      double l = 0, r;
      if (j) l = vec[i][j - 1] + 1;
      r = vec[i][j] - 1;
      cnt += max(0.0, (r - l + 1) * (r - l + 1));
    }
    if (!vec[i].empty())
      cnt += max(0.0, (double)(n - vec[i][vec[i].size() - 1] - 1) *
                          (double)(n - vec[i][vec[i].size() - 1] - 1));
    ans += ((double)n * (double)n - cnt) * (!vec[i].empty());
  }
  cout << fixed << setprecision(9);
  cout << ans / n / n << endl;
}
