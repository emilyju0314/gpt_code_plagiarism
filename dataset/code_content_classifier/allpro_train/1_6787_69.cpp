#include <bits/stdc++.h>
using namespace std;
const int MAXM = 100010;
int n, m;
pair<int, int> a[MAXM];
int xval[MAXM];
vector<pair<int, int> > ranges[MAXM];
int cmp(pair<int, int> x, pair<int, int> y) { return x.second < y.second; }
int makerange() {
  sort(a, a + m);
  int nlines = 0;
  xval[0] = a[0].first;
  ranges[0].push_back(make_pair(1, a[0].second - 1));
  for (int i = 0; i < m - 1; ++i) {
    if (a[i].first == a[i + 1].first) {
      if (a[i].first == 1) continue;
      if (a[i].second + 1 <= a[i + 1].second - 1) {
        ranges[nlines].push_back(
            make_pair(a[i].second + 1, a[i + 1].second - 1));
      }
    } else {
      if (a[i].first != 1) {
        if (a[i].second + 1 <= n) {
          ranges[nlines].push_back(make_pair(a[i].second + 1, n));
        }
      }
      ++nlines;
      if (1 <= a[i + 1].second - 1) {
        ranges[nlines].push_back(make_pair(1, a[i + 1].second - 1));
      }
      xval[nlines] = a[i + 1].first;
    }
  }
  if (a[m - 1].second + 1 <= n) {
    ranges[nlines].push_back(make_pair(a[m - 1].second + 1, n));
  }
  return ++nlines;
}
int find(int r, int y) {
  for (int i = 0; i < ranges[r].size(); ++i) {
    if (ranges[r][i].second < ranges[r][i].first) continue;
    if (ranges[r][i].second >= y) {
      return max(ranges[r][i].first, y);
    }
  }
  return n + 1;
}
int solve(int nlines) {
  for (int i = 1; i < nlines; ++i) {
    if (xval[i] - 1 > xval[i - 1]) {
      int idx = 0;
      for (int j = 0; j < ranges[i - 1].size(); ++j) {
        if (ranges[i - 1][j].second >= ranges[i - 1][j].first) {
          idx = j;
          break;
        }
      }
      if (ranges[i - 1].size() == 0) return false;
      int fr = ranges[i - 1][idx].first;
      for (int j = 0; j < ranges[i].size(); ++j) {
        if (ranges[i][j].first > ranges[i][j].second) continue;
        ranges[i][j].first = max(ranges[i][j].first, fr);
      }
    } else {
      for (int j = 0; j < ranges[i].size(); ++j) {
        if (ranges[i][j].first > ranges[i][j].second) continue;
        ranges[i][j].first = find(i - 1, ranges[i][j].first);
      }
    }
  }
  if (xval[nlines - 1] <= n - 1) {
    for (int i = 0; i < ranges[nlines - 1].size(); ++i) {
      if (ranges[nlines - 1][i].second >= ranges[nlines - 1][i].first) {
        return true;
      }
    }
  } else {
    for (int i = ranges[nlines - 1].size() - 1; i >= 0; --i) {
      if (ranges[nlines - 1][i].second >= ranges[nlines - 1][i].first) {
        if (ranges[nlines - 1][i].second == n) {
          return true;
        } else {
          return false;
        }
      }
    }
  }
  return false;
}
void debug(int nlines) {
  for (int i = 0; i < nlines; ++i) {
    for (int j = 0; j < ranges[i].size(); ++j) {
      cout << ranges[i][j].first << " " << ranges[i][j].second << " a ";
    }
    cout << xval[i] << endl;
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &a[i].first, &a[i].second);
  }
  int nlines = makerange();
  int reach = solve(nlines);
  if (reach)
    cout << 2 * (n - 1) << endl;
  else
    cout << -1 << endl;
  return 0;
}
