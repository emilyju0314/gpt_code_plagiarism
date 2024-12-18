#include <bits/stdc++.h>
using namespace std;
template <class T>
string toStr(const T &x) {
  stringstream s;
  s << x;
  return s.str();
}
template <class T>
int toInt(const T &x) {
  stringstream s;
  s << x;
  int r;
  s >> r;
  return r;
}
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int zeros;
void solve(vector<int> &v, vector<int> &vv, int a, int b) {
  vector<int> ans1[4], ans2[4];
  ans1[3].push_back(a);
  ans2[3].push_back(b);
  for (int i = 0; i < 10; ++i) {
    int res = 9 - i;
    while (v[i] && vv[res]) {
      ans1[2].push_back(i);
      ans2[2].push_back(res);
      v[i]--;
      vv[res]--;
    }
    while (vv[i] && v[res]) {
      ans1[2].push_back(res);
      ans2[2].push_back(i);
      vv[i]--;
      v[res]--;
    }
  }
  while (v[0] && vv[0]) {
    ans1[3].push_back(0);
    ans2[3].push_back(0);
    v[0]--;
    vv[0]--;
    zeros++;
  }
  for (int i = 0; i < 10; ++i) {
    while (v[i]-- > 0) ans1[0].push_back(i);
    while (vv[i]-- > 0) ans2[0].push_back(i);
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < ans1[i].size(); ++j) cout << ans1[i][j];
  }
  cout << '\n';
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < ans2[i].size(); ++j) cout << ans2[i][j];
  }
}
int howMany(vector<int> &v, vector<int> &vv) {
  int a = min(v[9], vv[0]) + min(vv[0], v[9]);
  int b = min(v[8], vv[1]) + min(vv[1], v[8]);
  int c = min(v[7], vv[2]) + min(vv[2], v[7]);
  int d = min(v[6], vv[3]) + min(vv[3], v[6]);
  int e = min(v[5], vv[4]) + min(vv[4], v[5]);
  return a + b + c + d + e;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  vector<int> v(10, 0), vv;
  for (int i = 0; i < s.size(); ++i) v[s[i] - '0']++;
  vv = v;
  int best = INT_MAX;
  pair<int, int> ten;
  ten.first = ten.second = 0;
  if (v[9] && vv[1]) {
    int t1 = howMany(v, vv);
    v[9]--;
    vv[1]--;
    int t2 = howMany(v, vv);
    int tmp = t1 - t2;
    if (tmp < best) {
      best = tmp;
      ten.first = 9;
      ten.second = 1;
    }
    v[9]++;
    vv[1]++;
  }
  if (v[8] && vv[2]) {
    int t1 = howMany(v, vv);
    v[8]--;
    vv[2]--;
    int t2 = howMany(v, vv);
    int tmp = t1 - t2;
    if (tmp < best) {
      best = tmp;
      ten.first = 8;
      ten.second = 2;
    }
    v[8]++;
    vv[2]++;
  }
  if (v[7] && vv[3]) {
    int t1 = howMany(v, vv);
    v[7]--;
    vv[3]--;
    int t2 = howMany(v, vv);
    int tmp = t1 - t2;
    if (tmp < best) {
      best = tmp;
      ten.first = 7;
      ten.second = 3;
    }
    v[7]++;
    vv[3]++;
  }
  if (v[6] && vv[4]) {
    int t1 = howMany(v, vv);
    v[6]--;
    vv[4]--;
    int t2 = howMany(v, vv);
    int tmp = t1 - t2;
    if (tmp < best) {
      best = tmp;
      ten.first = 6;
      ten.second = 4;
    }
    v[6]++;
    vv[4]++;
  }
  if (v[5] && vv[5]) {
    int t1 = howMany(v, vv);
    v[5]--;
    vv[5]--;
    int t2 = howMany(v, vv);
    int tmp = t1 - t2;
    if (tmp < best) {
      best = tmp;
      ten.first = 5;
      ten.second = 5;
    }
    v[5]++;
    vv[5]++;
  }
  if (!ten.first) {
    vector<int> ans1[4], ans2[4];
    while (v[0] && vv[0]) {
      ans1[3].push_back(0);
      ans2[3].push_back(0);
      v[0]--;
      vv[0]--;
    }
    for (int i = 0; i < 10; ++i) {
      while (v[i]-- > 0) ans1[0].push_back(i);
      while (vv[i]-- > 0) ans2[0].push_back(i);
    }
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < ans1[i].size(); ++j) cout << ans1[i][j];
    }
    cout << '\n';
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < ans2[i].size(); ++j) cout << ans2[i][j];
    }
  } else {
    v[ten.first]--;
    vv[ten.second]--;
    solve(v, vv, ten.first, ten.second);
  }
  return 0;
}
