#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 1000000000;
pair<int, int> A[20];
pair<int, int> B[2000];
int D[1000][1 << 7][1 << 7];
int n, m;
int CNT[1 << 7];
vector<int> BT[7][1000];
long long vdob(int x1, int y1, int x2, int y2, int x3, int y3) {
  long long X1 = x1 - x2;
  long long Y1 = y1 - y2;
  long long X2 = x3 - x2;
  long long Y2 = y3 - y2;
  return X1 * Y2 - X2 * Y1;
}
bool between(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
  long long d = vdob(A.first, A.second, B.first, B.second, C.first, C.second);
  if (d != 0) return false;
  int x1 = min(A.first, B.first);
  int x2 = max(A.first, B.first);
  int y1 = min(A.second, B.second);
  int y2 = max(A.second, B.second);
  if (x1 <= C.first && C.first <= x2 && y1 <= C.second && C.second <= y2)
    return true;
  return false;
}
vector<int> onWay(int x, int y) {
  vector<int> res;
  for (int i = (0); i < (m); ++i) {
    if (i == y) continue;
    if (between(A[x], B[y], B[i])) res.push_back(i);
  }
  return res;
}
bool can(set<int> s, int mask) {
  if (s.empty()) return true;
  if (n - CNT[mask] < (int)s.size()) return false;
  for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
    int x = *it;
    for (int j = (0); j < (n); ++j) {
      if (mask & (1 << j)) continue;
      if (BT[j][x].empty()) {
        set<int> ss = s;
        ss.erase(x);
        if (can(ss, mask ^ (1 << j))) return true;
        continue;
      }
      set<int> ss = s;
      ss.erase(x);
      for (int k = (0); k < ((int)BT[j][x].size()); ++k) {
        ss.insert(BT[j][x][k]);
      }
      if (can(ss, mask ^ (1 << j))) return true;
    }
  }
  return false;
}
int main() {
  for (int i = (1); i < (1 << 7); ++i) {
    CNT[i] = CNT[i >> 1] + (i & 1);
  }
  cin >> n >> m;
  for (int i = (0); i < (n); ++i) {
    cin >> A[i].first >> A[i].second;
  }
  for (int i = (0); i < (m); ++i) {
    cin >> B[i].first >> B[i].second;
  }
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (m); ++j) {
      BT[i][j] = onWay(i, j);
    }
  }
  int res = 0;
  for (int i = (0); i < (m); ++i) {
    set<int> s;
    s.insert(i);
    if (can(s, 0)) res++;
  }
  cout << res << endl;
  return 0;
}
