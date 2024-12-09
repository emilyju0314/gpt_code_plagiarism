#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<vector<int>> gd;
vector<vector<pair<int, int>>> gu;
int N, M;
vector<int> dr;
vector<pair<int, int>> ed;
void away(int n) {
  if (v[n]) return;
  v[n] = 1;
  for (int x = 0; x < gd[n].size(); x++) {
    away(gd[n][x]);
  }
  for (int x = 0; x < gu[n].size(); x++) {
    if (dr[gu[n][x].second] == 0) {
      if (ed[gu[n][x].second].first == n) {
        dr[gu[n][x].second] = 1;
      } else {
        dr[gu[n][x].second] = -1;
      }
      away(gu[n][x].first);
    }
  }
}
void towards(int n) {
  if (v[n]) return;
  v[n] = 1;
  for (int x = 0; x < gd[n].size(); x++) {
    towards(gd[n][x]);
  }
  for (int x = 0; x < gu[n].size(); x++) {
    if (dr[gu[n][x].second] == 0) {
      if (ed[gu[n][x].second].first == n) {
        dr[gu[n][x].second] = -1;
      } else {
        dr[gu[n][x].second] = 1;
      }
    }
  }
}
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  int s;
  cin >> N >> M >> s;
  int A, B, t;
  int tu = 0;
  gd.assign(N + 1, vector<int>());
  gu.assign(N + 1, vector<pair<int, int>>());
  for (int m = 0; m < M; m++) {
    cin >> t >> A >> B;
    if (t == 1) {
      gd[A].push_back(B);
    } else {
      gu[A].push_back({B, tu});
      gu[B].push_back({A, tu++});
      ed.push_back({A, B});
    }
  }
  dr.assign(tu + 1, 0);
  v.assign(N + 1, 0);
  away(s);
  int c = 0;
  for (int x = 1; x <= N; x++) {
    if (v[x]) c++;
  }
  cout << c << endl;
  for (int x = 0; x < tu; x++) {
    if (dr[x] == 1)
      cout << "+";
    else if (dr[x] == -1)
      cout << "-";
    else
      cout << "+";
  }
  cout << endl;
  v.clear();
  v.assign(N + 1, 0);
  dr.assign(tu + 1, 0);
  c = 0;
  towards(s);
  for (int x = 1; x <= N; x++) c += v[x];
  cout << c << endl;
  for (int x = 0; x < tu; x++) {
    if (dr[x] == 1)
      cout << "+";
    else if (dr[x] == -1)
      cout << "-";
    else
      cout << "+";
  }
  cout << endl;
  return 0;
}
