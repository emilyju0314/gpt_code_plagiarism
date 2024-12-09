#include <bits/stdc++.h>
using namespace std;
const int geta = 100000;
int p[100010], x[100010], y[100010];
vector<int> hoge[2][200010];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, w, h;
  cin >> n >> w >> h;
  for (int i = 0; i < n; i++) {
    int g, t;
    cin >> g >> p[i] >> t;
    g--;
    hoge[g][geta + p[i] - t].push_back(i);
  }
  for (int i = 0; i <= 200000; i++) {
    sort(hoge[0][i].begin(), hoge[0][i].end(),
         [&](const int& i1, const int& i2) { return p[i1] < p[i2]; });
    sort(hoge[1][i].begin(), hoge[1][i].end(),
         [&](const int& i1, const int& i2) { return p[i1] < p[i2]; });
  }
  for (int i = 0; i <= 200000; i++) {
    deque<int> dq;
    for (int idx : hoge[1][i]) dq.push_back(idx);
    for (int idx : hoge[0][i]) {
      dq.push_front(idx);
      x[dq.back()] = p[idx];
      y[dq.back()] = h;
      dq.pop_back();
    }
    for (int j = 0; j < dq.size(); j++) {
      x[dq[j]] = w;
      y[dq[j]] = p[hoge[1][i][j]];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << x[i] << " " << y[i] << endl;
  }
  return 0;
}
