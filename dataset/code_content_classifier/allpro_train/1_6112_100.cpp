#include <bits/stdc++.h>
using namespace std;
struct line {
  int h, l, r, s;
  line(int h, int l, int r, int s) : h(h), l(l), r(r), s(s) {}
  bool operator<(const line& x) const { return h < x.h; }
};
int n, m, k;
int x[500], y[500];
vector<line> lines;
vector<int> vh;
int cnt[1005];
bool check(int t) {
  lines.clear();
  vh.clear();
  vh.push_back(1);
  vh.push_back(m + 1);
  lines.push_back(line(1, 1, 1, 1));
  lines.push_back(line(n + 1, 1, 1, 1));
  for (int i = 0; i < k; i++) {
    lines.push_back(line(((1) < (x[i] - t) ? x[i] - t : 1),
                         ((1) < (y[i] - t) ? y[i] - t : 1),
                         ((m) > (y[i] + t) ? y[i] + t : m) + 1, 1));
    lines.push_back(line(((n) > (x[i] + t) ? x[i] + t : n) + 1,
                         ((1) < (y[i] - t) ? y[i] - t : 1),
                         ((m) > (y[i] + t) ? y[i] + t : m) + 1, -1));
    vh.push_back(((1) < (y[i] - t) ? y[i] - t : 1));
    vh.push_back(((m) > (y[i] + t) ? y[i] + t : m) + 1);
  }
  sort(vh.begin(), vh.end());
  vh.erase(unique(vh.begin(), vh.end()), vh.end());
  sort(lines.begin(), lines.end());
  int U = n + 1, D = 1, L = m + 1, R = 1;
  for (int i = 0; i < 1005; i++) cnt[i] = 0;
  for (int i = 0, j = 0; i < lines.size(); i = j) {
    for (; j < lines.size() && lines[i].h == lines[j].h; j++) {
      int l = lower_bound(vh.begin(), vh.end(), lines[j].l) - vh.begin();
      int r = lower_bound(vh.begin(), vh.end(), lines[j].r) - vh.begin();
      for (int k = l; k < r; k++) cnt[k] += lines[j].s;
    }
    if (lines[i].h <= n) {
      for (int k = 0; k < vh.size() - 1; k++) {
        if (cnt[k] == 0) {
          U = ((U) > (lines[i].h) ? lines[i].h : U);
          D = ((D) < (lines[j].h - 1) ? lines[j].h - 1 : D);
          L = ((L) > (vh[k]) ? vh[k] : L);
          R = ((R) < (vh[k + 1] - 1) ? vh[k + 1] - 1 : R);
        }
      }
    }
  }
  return D - U <= 2 * t && R - L <= 2 * t;
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) cin >> x[i] >> y[i];
  int l = 0, r = ((n) < (m) ? m : n);
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << r << endl;
}
