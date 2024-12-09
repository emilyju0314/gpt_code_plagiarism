#include <bits/stdc++.h>
using namespace std;
int n, m, vert = -1, hor = -1, cy = 1, cx = 1, nx, ny;
char t[107][107];
bitset<107> vis[107];
void check() {
  if (t[cy][cx] == 'F') {
    cerr << "OK";
    exit(0);
  }
}
void q(char c) {
  cout << c << '\n';
  fflush(stdout);
  cin >> nx >> ny;
  swap(nx, ny);
}
bool ins(int y, int x) { return 1 <= y && y <= n && 1 <= x && x <= m; }
void ruch() {
  cy = ny;
  cx = nx;
}
void dfs() {
  check();
  vis[cy][cx] = 1;
  if (vert == -1 && !ins(cy - 1, cx) && ins(cy + 1, cx) &&
      t[cy + 1][cx] != '*') {
    q('D');
    if (ny == cy && nx == cx)
      vert = 1;
    else {
      vert = 0;
      check();
      q('U');
    }
  }
  if (vert == -1 && !ins(cy + 1, cx) && ins(cy - 1, cx) &&
      t[cy - 1][cx] != '*') {
    q('U');
    if (ny == cy && nx == cx)
      vert = 1;
    else {
      vert = 0;
      check();
      q('D');
    }
  }
  if (hor == -1 && !ins(cy, cx - 1) && ins(cy, cx + 1) &&
      t[cy][cx + 1] != '*') {
    q('R');
    if (ny == cy && nx == cx)
      hor = 1;
    else {
      hor = 0;
      check();
      q('L');
    }
  }
  if (hor == -1 && !ins(cy, cx + 1) && ins(cy, cx - 1) &&
      t[cy][cx - 1] != '*') {
    q('L');
    if (ny == cy && nx == cx)
      hor = 1;
    else {
      hor = 0;
      check();
      q('R');
    }
  }
  if (vert == 0) {
    if (ins(cy + 1, cx) && !vis[cy + 1][cx] && t[cy + 1][cx] != '*') {
      q('D');
      ruch();
      dfs();
      q('U');
      ruch();
    }
    if (ins(cy - 1, cx) && !vis[cy - 1][cx] && t[cy - 1][cx] != '*') {
      q('U');
      ruch();
      dfs();
      q('D');
      ruch();
    }
  } else if (vert == 1) {
    if (ins(cy + 1, cx) && !vis[cy + 1][cx] && t[cy + 1][cx] != '*') {
      q('U');
      ruch();
      dfs();
      q('D');
      ruch();
    }
    if (ins(cy - 1, cx) && !vis[cy - 1][cx] && t[cy - 1][cx] != '*') {
      q('D');
      ruch();
      dfs();
      q('U');
      ruch();
    }
  }
  if (hor == 0) {
    if (ins(cy, cx + 1) && !vis[cy][cx + 1] && t[cy][cx + 1] != '*') {
      q('R');
      ruch();
      dfs();
      q('L');
      ruch();
    }
    if (ins(cy, cx - 1) && !vis[cy][cx - 1] && t[cy][cx - 1] != '*') {
      q('L');
      ruch();
      dfs();
      q('R');
      ruch();
    }
  } else if (hor == 1) {
    if (ins(cy, cx + 1) && !vis[cy][cx + 1] && t[cy][cx + 1] != '*') {
      q('L');
      ruch();
      dfs();
      q('R');
      ruch();
    }
    if (ins(cy, cx - 1) && !vis[cy][cx - 1] && t[cy][cx - 1] != '*') {
      q('R');
      ruch();
      dfs();
      q('L');
      ruch();
    }
  }
}
int32_t main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> t[i][j];
    }
  }
  dfs();
}
