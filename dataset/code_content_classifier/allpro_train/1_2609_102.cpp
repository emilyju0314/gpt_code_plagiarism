#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const long long key1 = MAXN + 2, key2 = MAXN + 4;
const long long mod1 = 1e9 + 7, mod2 = 1e9 + 9;
struct myHash {
  long long x, y;
  myHash() {
    this->x = 0;
    this->y = 0;
  }
  myHash(long long x, long long y) {
    this->x = x;
    this->y = y;
  }
  void append(long long c) {
    this->x = (this->x * key1 + c) % mod1;
    this->y = (this->y * key2 + c) % mod2;
  }
};
bool operator<(const myHash A, const myHash B) {
  if (A.x != B.x) return A.x < B.x;
  return A.y < B.y;
}
bool operator==(const myHash A, const myHash B) {
  if (A.x != B.x) return false;
  if (A.y != B.y) return false;
  return true;
}
bool operator!=(const myHash A, const myHash B) {
  if (A.x != B.x) return true;
  if (A.y != B.y) return true;
  return false;
}
int n;
vector<int> graph[MAXN];
myHash h[MAXN];
bool good[MAXN];
void DFSInit(int x, int par) {
  good[x] = true;
  myHash last = myHash(-1, -1);
  for (int i = 0; i < graph[x].size(); i++) {
    if (graph[x][i] == par) continue;
    DFSInit(graph[x][i], x);
    if (good[graph[x][i]] == false) good[x] = false;
    if (last == myHash(-1, -1)) {
      last = h[graph[x][i]];
      h[x] = last;
      h[x].append(graph[x].size());
    } else {
      if (h[graph[x][i]] != last) {
        good[x] = false;
      }
    }
  }
  if (last == myHash(-1, -1)) {
    h[x] = myHash(0, 0);
    h[x].append(graph[x].size());
  }
}
bool checkEqual(multiset<myHash> &s) {
  auto it = s.end();
  it--;
  if (*s.begin() == *it) return true;
  return false;
}
void DFS(int x, int last, myHash up) {
  int badCnt = 0;
  multiset<myHash> s;
  for (int i = 0; i < graph[x].size(); i++) {
    if (graph[x][i] == last) continue;
    s.insert(h[graph[x][i]]);
    badCnt += good[graph[x][i]] ^ true;
  }
  if (last != -1) {
    s.insert(up);
  }
  if (badCnt == 0) {
    auto it = s.end();
    it--;
    if (*s.begin() == *it) {
      cout << x << '\n';
      exit(0);
    }
  }
  if (badCnt > 1) return;
  for (int i = 0; i < graph[x].size(); i++) {
    if (graph[x][i] == last) continue;
    s.erase(s.find(h[graph[x][i]]));
    badCnt -= good[graph[x][i]] ^ true;
    if (badCnt == 0) {
      if (s.empty() == true || checkEqual(s) == true) {
        if (s.empty() == true)
          up = myHash(0, 0);
        else
          up = *s.begin();
        up.append(graph[x].size());
        DFS(graph[x][i], x, up);
      }
    }
    s.insert(h[graph[x][i]]);
    badCnt += good[graph[x][i]] ^ true;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  if (n == 1) {
    cout << "1" << '\n';
    return 0;
  }
  DFSInit(1, -1);
  DFS(1, -1, myHash(0, 0));
  cout << "-1" << '\n';
}
