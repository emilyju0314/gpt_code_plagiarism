#include <bits/stdc++.h>
using namespace std;
int n, v[15];
vector<pair<int, int> > erased;
vector<pair<int, int> > curv;
vector<int> needAcum;
map<int, int> assignedTo;
set<int> dp[15][1 << 15];
bool assign(int pos, int bm, int prev, int acumLeft, int usedHere, int aux2) {
  if (pos == curv.size()) return true;
  if (needAcum[pos] - usedHere > acumLeft) return false;
  if (dp[pos][bm].upper_bound(prev) != dp[pos][bm].begin()) return false;
  if (curv[pos].first > prev) {
    dp[pos][bm].insert(prev);
    return assign(pos + 1, bm, curv[pos].first, acumLeft, 0, 0);
  }
  for (int i = (aux2); i < (erased.size()); i++)
    if ((bm & (1 << i)) == 0) {
      if (curv[pos].first + erased[i].first > prev) {
        if (assign(pos + 1, bm | (1 << i),
                   curv[pos].first + erased[i].first + usedHere,
                   acumLeft - erased[i].first, 0, 0)) {
          assignedTo[erased[i].second] = curv[pos].second;
          return true;
        }
      } else if (assign(pos, bm | (1 << i), prev - erased[i].first,
                        acumLeft - erased[i].first, usedHere + erased[i].first,
                        i + 1)) {
        assignedTo[erased[i].second] = curv[pos].second;
        return true;
      }
    }
  dp[pos][bm].insert(prev);
  return false;
}
bool can(int pos, int toErase) {
  if (toErase < 0 || n - pos < toErase) return false;
  if (pos == n) {
    if (toErase != 0) return false;
    assignedTo.clear();
    bool ok = true;
    for (int i = (1); i < (curv.size()); i++)
      if (curv[i].first <= curv[i - 1].first) ok = false;
    if (ok) return true;
    assert(erased.size() + curv.size() == n);
    int acum = 0;
    for (auto it = erased.begin(); it != erased.end(); it++) acum += it->first;
    needAcum.clear();
    needAcum.push_back(0);
    for (int i = (1); i < (curv.size()); i++)
      needAcum.push_back(max(0, curv[i - 1].first + 1 - curv[i].first));
    for (int i = needAcum.size() - 1 - 1; i >= 0; i--)
      needAcum[i] += needAcum[i + 1];
    if (needAcum[0] > acum) return false;
    vector<pair<int, int> > origErased = erased;
    for (int i = (0); i < (curv.size()); i++)
      for (int j = (0); j < (1 << erased.size()); j++) dp[i][j].clear();
    bool ret = assign(0, 0, 0, acum, 0, 0);
    erased = origErased;
    return ret;
  }
  if (1) {
    curv.push_back(make_pair(v[pos], pos));
    if (can(pos + 1, toErase)) return true;
    curv.pop_back();
    erased.push_back(make_pair(v[pos], pos));
    if (can(pos + 1, toErase - 1)) return true;
    erased.pop_back();
  } else {
    erased.push_back(make_pair(v[pos], pos));
    if (can(pos + 1, toErase - 1)) return true;
    erased.pop_back();
    curv.push_back(make_pair(v[pos], pos));
    if (can(pos + 1, toErase)) return true;
    curv.pop_back();
  }
  return false;
}
bool can(int cant) {
  erased.clear();
  curv.clear();
  if (can(0, cant)) return true;
  return false;
}
void ans(int cant) {
  assert(can(cant));
  vector<int> alreadyErased;
  cout << cant << '\n';
  assert(erased.size() == cant);
  for (auto it = erased.begin(); it != erased.end(); it++) {
    int first = it->second, second = curv.back().second;
    if (assignedTo.count(it->second)) second = assignedTo[it->second];
    int initialsnd = second;
    for (int i = (0); i < (alreadyErased.size()); i++) {
      assert(alreadyErased[i] != it->second);
      assert(alreadyErased[i] != initialsnd);
      if (alreadyErased[i] < it->second) first--;
      if (alreadyErased[i] < initialsnd) second--;
    }
    assert(first != second);
    cout << first + 1 << ' ' << second + 1 << '\n';
    alreadyErased.push_back(it->second);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int T = (0); T < (t); T++) {
    cin >> n;
    for (int i = (0); i < (n); i++) cin >> v[i];
    int l = 0, r = n - 1, m;
    while (l < r) {
      m = (l + r) / 2;
      if (can(m))
        r = m;
      else
        l = m + 1;
    }
    ans(l);
  }
  return 0;
}
