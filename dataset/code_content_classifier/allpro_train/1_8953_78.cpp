#include <bits/stdc++.h>
using namespace std;
const long double EPS = 0.00001;
const long double PI = 3.14159265358979323846;
inline void file_io(string in_file, string out_file, bool mark) {
  if (!mark) return;
  freopen(in_file.c_str(), "r", stdin);
}
struct tr {
  tr() {}
  tr(int a, int b, int c) : a(a), b(b), c(c) {}
  bool operator!=(const tr& other) {
    return a != other.a || b != other.b || c != other.c;
  }
  int a, b, c;
};
const int ml = 71;
const int inf = 1e9;
queue<tr> q;
char g[ml][ml];
int d[ml][ml][ml];
tr p[ml][ml][ml];
bool used[ml][ml][ml], mark[ml][ml][ml];
int main() {
  file_io("input.in", "distance.out", 0);
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int a, b, c, n;
  cin >> n >> a >> b >> c;
  for (int i = 1; i <= n; ++i) {
    string tmp;
    cin >> tmp;
    for (int j = 1; j <= n; ++j) g[i][j] = tmp[j - 1];
  }
  for (int i = 0; i < ml; ++i)
    for (int j = 0; j < ml; ++j)
      for (int k = 0; k < ml; ++k) d[i][j][k] = inf;
  for (int i = 1; i <= 3; ++i)
    for (int j = 1; j <= 3; ++j)
      for (int k = 1; k <= 3; ++k)
        if (i != j && i != k && j != k) mark[i][j][k] = 1;
  d[a][b][c] = 0;
  used[a][b][c] = 1;
  q.push(tr(a, b, c));
  while (!q.empty()) {
    tr cur = q.front();
    q.pop();
    int v = cur.a;
    char col = g[cur.b][cur.c];
    for (int i = 1; i <= n; ++i) {
      if (i != cur.b && i != cur.c && g[v][i] != '*' && g[v][i] == col &&
          !used[i][cur.b][cur.c]) {
        q.push(tr(i, cur.b, cur.c));
        d[i][cur.b][cur.c] = d[cur.a][cur.b][cur.c] + 1;
        p[i][cur.b][cur.c] = cur;
        used[i][cur.b][cur.c] = 1;
        if (mark[i][cur.b][cur.c]) goto finish;
      }
    }
    v = cur.b;
    col = g[cur.a][cur.c];
    for (int i = 1; i <= n; ++i) {
      if (i != cur.a && i != cur.c && g[v][i] != '*' && g[v][i] == col &&
          !used[cur.a][i][cur.c]) {
        q.push(tr(cur.a, i, cur.c));
        d[cur.a][i][cur.c] = d[cur.a][cur.b][cur.c] + 1;
        p[cur.a][i][cur.c] = cur;
        used[cur.a][i][cur.c] = 1;
        if (mark[cur.a][i][cur.c]) goto finish;
      }
    }
    v = cur.c;
    col = g[cur.a][cur.b];
    for (int i = 1; i <= n; ++i) {
      if (i != cur.a && i != cur.b && g[v][i] != '*' && g[v][i] == col &&
          !used[cur.a][cur.b][i]) {
        q.push(tr(cur.a, cur.b, i));
        d[cur.a][cur.b][i] = d[cur.a][cur.b][cur.c] + 1;
        p[cur.a][cur.b][i] = cur;
        used[cur.a][cur.b][i] = 1;
        if (mark[cur.a][cur.b][i]) goto finish;
      }
    }
  }
finish:
  tr end(-1, -1, -1);
  for (int i = 1; i <= 3; ++i)
    for (int j = 1; j <= 3; ++j)
      for (int k = 1; k <= 3; ++k)
        if (i != j && i != k && j != k && d[i][j][k] != inf)
          if ((end.a == -1 && end.b == -1 && end.c == -1) ||
              d[i][j][k] < d[end.a][end.b][end.c])
            end = tr(i, j, k);
  if (end.a == -1 && end.b == -1 && end.c == -1)
    cout << -1 << endl;
  else {
    tr start = tr(a, b, c);
    vector<tr> ans;
    while (end != start) {
      ans.push_back((end));
      end = p[end.a][end.b][end.c];
    }
    ans.push_back((start));
    cout << ans.size() - 1 << endl;
    reverse((ans).begin(), (ans).end());
    for (int i = 1; i < ans.size(); ++i) {
      if (ans[i].a != ans[i - 1].a)
        cout << ans[i - 1].a << " " << ans[i].a << endl;
      if (ans[i].b != ans[i - 1].b)
        cout << ans[i - 1].b << " " << ans[i].b << endl;
      if (ans[i].c != ans[i - 1].c)
        cout << ans[i - 1].c << " " << ans[i].c << endl;
    }
  }
  return 0;
}
