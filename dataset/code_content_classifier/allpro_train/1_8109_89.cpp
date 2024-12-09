#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > con[3];
vector<pair<long long, long long> > sum;
int main() {
  for (long long i = 0; i < ((long long)3); i++) {
    long long n;
    cin >> n;
    for (long long j = 0; j < ((long long)n); j++) {
      long long x, y;
      cin >> x >> y;
      con[i].push_back(make_pair(x, y));
    }
  }
  long long pos[3] = {1, 1, 1};
  long long start[3] = {1, 1, 1};
  for (long long i = 0; i < ((long long)3); i++)
    for (long long j = 0; j < ((long long)((long long)con[i].size())); j++)
      if (con[i][start[i]] < con[i][j]) pos[i] = start[i] = j;
  long long sum_x = 0;
  long long sum_y = 0;
  bool f[3] = {true, true, true};
  while (pos[0] != start[0] || pos[1] != start[1] || pos[2] != start[2] ||
         f[0] || f[1] || f[2]) {
    double ang[3] = {0, 0, 0};
    long long next[3] = {(pos[0] + 1) % ((long long)con[0].size()),
                         (pos[1] + 1) % ((long long)con[1].size()),
                         (pos[2] + 1) % ((long long)con[2].size())};
    for (long long i = 0; i < ((long long)3); i++) {
      double xx = (con[i][next[i]].first) - (con[i][pos[i]].first);
      double yy = (con[i][next[i]].second) - (con[i][pos[i]].second);
      ang[i] = (yy == 0) ? (acos(-1) / 2.0) : acos(yy / hypot(xx, yy));
      if (0 < xx) ang[i] = acos(-1) * 2.0 - ang[i];
      if (ang[i] == 0) ang[i] = acos(-1) * 2.0;
      if (pos[i] == start[i] && !f[i]) ang[i] = 365;
    }
    long long mini = 0;
    for (long long i = 0; i < ((long long)3); i++)
      if (ang[i] < ang[mini]) mini = i;
    pos[mini] = next[mini];
    f[mini] = false;
    sum_x = sum_y = 0;
    for (long long i = 0; i < ((long long)3); i++)
      sum_x += (con[i][pos[i]].first);
    for (long long i = 0; i < ((long long)3); i++)
      sum_y += (con[i][pos[i]].second);
    sum.push_back(make_pair(sum_x, sum_y));
  }
  vector<pair<long long, long long> > low, high;
  long long mini = 0, maxi = 0;
  long long mini_y[2], maxi_y[2];
  for (long long i = 0; i < ((long long)((long long)sum.size())); i++)
    if (sum[i] < sum[mini]) mini = i;
  for (long long i = 0; i < ((long long)((long long)sum.size())); i++)
    if (sum[maxi] < sum[i]) maxi = i;
  for (int i = mini; i != maxi; i = (i + 1) % ((long long)sum.size()))
    low.push_back(sum[i]);
  for (int i = mini; i != maxi;
       i = (i + ((long long)sum.size()) - 1) % ((long long)sum.size()))
    high.push_back(sum[i]);
  low.push_back(sum[maxi]);
  high.push_back(sum[maxi]);
  for (long long i = 0; i < ((long long)2); i++) mini_y[i] = sum[mini].second;
  for (long long i = 0; i < ((long long)2); i++) maxi_y[i] = sum[maxi].second;
  for (long long i = 0; i < ((long long)((long long)sum.size())); i++)
    if (sum[i].first == sum[mini].first) {
      mini_y[0] = min(mini_y[0], sum[i].second);
      mini_y[1] = max(mini_y[1], sum[i].second);
    }
  for (long long i = 0; i < ((long long)((long long)sum.size())); i++)
    if (sum[i].first == sum[maxi].first) {
      maxi_y[0] = min(maxi_y[0], sum[i].second);
      maxi_y[1] = max(maxi_y[1], sum[i].second);
    }
  sort(low.begin(), low.end());
  sort(high.begin(), high.end());
  long long n;
  cin >> n;
  for (long long i = 0; i < ((long long)n); i++) {
    long long xx, yy;
    cin >> xx >> yy;
    xx *= 3;
    yy *= 3;
    if (xx == sum[maxi].first) {
      if (maxi_y[0] <= yy && yy <= maxi_y[1])
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else if (xx == sum[mini].first) {
      if (mini_y[0] <= yy && yy <= mini_y[1])
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else if (sum[mini].first < xx && xx < sum[maxi].first) {
      vector<pair<long long, long long> >::iterator lp0 =
          upper_bound(low.begin(), low.end(), make_pair(xx, yy));
      vector<pair<long long, long long> >::iterator hp0 =
          upper_bound(high.begin(), high.end(), make_pair(xx, yy));
      vector<pair<long long, long long> >::iterator lp1 = lp0--;
      vector<pair<long long, long long> >::iterator hp1 = hp0--;
      long long ldx = lp1->first - lp0->first;
      long long ldy = lp1->second - lp0->second;
      long long hdx = hp1->first - hp0->first;
      long long hdy = hp1->second - hp0->second;
      if (ldx * lp0->second - ldy * lp0->first + ldy * xx <= ldx * yy &&
          hdx * yy <= hdx * hp0->second - hdy * hp0->first + hdy * xx) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
}
