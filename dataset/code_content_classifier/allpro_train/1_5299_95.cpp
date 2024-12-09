#include <bits/stdc++.h>
using namespace std;
template <typename Type>
class hset {
 private:
  static const int H = 1000003;
  static const int SIZE = 2000000;
  Type node[SIZE];
  int head[H], next[SIZE];
  int node_cnt, erase_cnt;

 public:
  typedef Type* iterator;
  hset() {
    memset(head, -1, sizeof(head));
    node_cnt = erase_cnt = 0;
  }
  iterator begin() { return node; }
  iterator end() { return node + node_cnt; }
  int size() const { return node_cnt - erase_cnt; }
  void clear() {
    for (int i = 0; i < node_cnt; i++) head[getHash(node[i])] = -1;
    node_cnt = erase_cnt = 0;
  }
  iterator find(const Type& key) {
    int h = getHash(key);
    for (int i = head[h]; i != -1; i = next[i])
      if (node[i] == key) return node + i;
    return end();
  }
  int count(const Type& key) { return find(key) != end(); }
  void insert(const Type& key) {
    int h = getHash(key);
    for (int i = head[h]; i != -1; i = next[i])
      if (node[i] == key) return;
    node[node_cnt] = key;
    next[node_cnt] = head[h];
    head[h] = node_cnt++;
  }
  void erase(const Type& key) {
    int h = getHash(key);
    if (node[head[h]] == key) {
      head[h] = next[head[h]];
      erase_cnt++;
      return;
    }
    int pre = head[h], cur = next[pre];
    while (cur != -1) {
      if (node[cur] == key) {
        next[pre] = next[cur];
        erase_cnt++;
        return;
      }
      pre = cur;
      cur = next[cur];
    }
  }
  int getHash(const Type& key) const;
};
template <typename Type>
int hset<Type>::getHash(const Type& key) const {
  return key.getHash(H);
}
const int N = 1100;
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
struct Point {
  int x, y;
  Point() {}
  Point(int x, int y) : x(x), y(y) {}
  bool operator==(const Point& a) const { return x == a.x && y == a.y; }
  bool operator<(const Point& a) const {
    return x < a.x || (x == a.x && y < a.y);
  }
  int getHash(int H) const { return (x * 1010 + y) % H; }
};
hset<Point> st;
char mz[N][N];
bool vis[N][N];
int n, m;
bool out;
bool check4() {
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < m - 1; j++)
      if (mz[i][j] == '1' && mz[i + 1][j] == '1' && mz[i][j + 1] == '1' &&
          mz[i + 1][j + 1] == '1')
        return true;
  return false;
}
void fill(int x, int y) {
  vis[x][y] = true;
  for (int d = 0; d < 8; d++) {
    int nx = x + dx[d], ny = y + dy[d];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
      if (mz[nx][ny] == '1')
        st.insert(Point(nx, ny));
      else if (!vis[nx][ny] && mz[nx][ny] == '0')
        fill(nx, ny);
    } else
      out = true;
  }
}
void go(int x, int y) {
  st.erase(Point(x, y));
  for (int d = 0; d < 4; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (st.count(Point(nx, ny))) go(nx, ny);
  }
}
int ok() {
  int tmp = st.size();
  if (tmp <= 4) return 0;
  for (__typeof((st).begin()) it = (st).begin(); it != (st).end(); it++)
    if (st.count(*it)) {
      int cnt = 0;
      for (int d = 0; d < 4; d++) {
        int nx = it->x + dx[d];
        int ny = it->y + dy[d];
        if (st.count(Point(nx, ny))) cnt++;
      }
      if (cnt != 2) return 0;
    }
  go(st.begin()->x, st.begin()->y);
  return st.size() ? 0 : tmp;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", mz[i]);
  memset(vis, 0, sizeof(vis));
  int ans = 0;
  if (check4()) ans = 4;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (mz[i][j] == '0' && !vis[i][j]) {
        out = false;
        st.clear();
        fill(i, j);
        if (out) st.clear();
        ans = max(ans, ok());
      }
  cout << ans << endl;
  return 0;
}
