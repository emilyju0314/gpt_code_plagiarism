#include <bits/stdc++.h>
using namespace std;
int h, m, n;
vector<int> tree;
int findFirstFree(int node, int nl, int nr, int L, int R) {
  if (nl > R || nr < L) return -1;
  if (tree[node] == nr - nl + 1) return -1;
  if (nl == nr) {
    tree[node]++;
    return nl;
  }
  int m = nl + (nr - nl) / 2;
  int res = findFirstFree(2 * node + 1, nl, m, L, R);
  if (res < 0) res = findFirstFree(2 * node + 2, m + 1, nr, L, R);
  if (res >= 0) tree[node]++;
  return res;
}
void remove(int node, int nl, int nr, int x) {
  if (nl > x || nr < x) return;
  tree[node]--;
  if (nl == nr) return;
  int m = nl + (nr - nl) / 2;
  remove(2 * node + 1, nl, m, x);
  remove(2 * node + 2, m + 1, nr, x);
}
int main() {
  cin >> h >> m >> n;
  tree.resize(h * 4, 0);
  vector<int> newHash(h, -1), start;
  newHash.resize(h, -1);
  for (int s = 0; s < h; ++s)
    if (newHash[s] < 0) {
      int curStart = start.size();
      newHash[s] = start.size();
      start.push_back(curStart);
      int t = (s + m) % h;
      while (t != s) {
        newHash[t] = start.size();
        start.push_back(curStart);
        t = (t + m) % h;
      }
    }
  start.push_back(h);
  vector<int> end(h);
  int i = 0;
  for (int j = 1; j <= h; ++j)
    if (start[j] != start[i]) {
      for (; i < j; ++i) end[i] = j - 1;
    }
  long long res = 0;
  map<int, int> where;
  while (n--) {
    char c;
    cin >> c;
    if (c == '+') {
      int id, hash;
      cin >> id >> hash;
      hash = newHash[hash];
      int L = start[hash], R = end[hash];
      int pos = findFirstFree(0, 0, h - 1, hash, R);
      if (pos < 0) {
        res += (R - hash + 1);
        pos = findFirstFree(0, 0, h - 1, L, hash - 1);
        res += (pos - L);
      } else
        res += (pos - hash);
      where[id] = pos;
    } else {
      int id;
      cin >> id;
      int pos = where[id];
      where.erase(id);
      remove(0, 0, h - 1, pos);
    }
  }
  cout << res << endl;
  return 0;
}
