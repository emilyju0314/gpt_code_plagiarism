#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int h[2 * n], w[n];
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> h[i];
    h[n + i] = w[i];
  }
  int ans = 1000000001;
  for (int i = 0; i < 2 * n; ++i) {
    int H = h[i];
    int max = n / 2;
    bool good = true;
    int len = 0;
    vector<int> diff;
    for (int j = 0; j < n; ++j) {
      if (h[j] > H && w[j] > H)
        good = false;
      else if (h[j] > H) {
        --max;
        len += h[j];
      } else if (w[j] > H)
        len += w[j];
      else {
        len += w[j];
        if (h[j] < w[j]) diff.push_back(w[j] - h[j]);
      }
    }
    if (!good) continue;
    if (max < 0) continue;
    sort(diff.begin(), diff.end(), greater<int>());
    for (int j = 0; j < max && j < diff.size(); ++j) len -= diff[j];
    ans = min(ans, len * H);
  }
  cout << ans << endl;
  return 0;
}
