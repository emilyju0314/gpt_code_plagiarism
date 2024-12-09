#include <bits/stdc++.h>
using namespace std;
long long inf = 1000 * 1000 * 1000 + 7;
long long inf64 = inf * inf;
long long mod = 228228227;
long long math_mod = 998244353;
const int maxn = 50005;
float START_TIME;
mt19937 gen(time(0));
int n, m, k;
vector<vector<vector<int>>> f;
vector<vector<tuple<int, int, int>>> LEFT;
vector<vector<tuple<int, int, int>>> RIGHT;
vector<vector<tuple<int, int, int>>> TOP;
vector<vector<tuple<int, int, int>>> BOTTOM;
vector<vector<tuple<int, int, int>>> FRONT;
vector<vector<tuple<int, int, int>>> BACK;
vector<vector<int>> LEFT_BLOCK;
vector<vector<int>> RIGHT_BLOCK;
vector<vector<int>> TOP_BLOCK;
vector<vector<int>> BOTTOM_BLOCK;
vector<vector<int>> FRONT_BLOCK;
vector<vector<int>> BACK_BLOCK;
bool is_in_borders(int x, int y, int z) {
  return (x > 0 && y > 0 && z > 0 && x <= n && y <= m && z <= k);
}
bool check(int x, int y, int z) {
  tuple<int, int, int> tup = make_tuple(x, y, z);
  unordered_set<int> u;
  if (LEFT[y][z] == tup) u.insert(LEFT_BLOCK[y][z]);
  if (RIGHT[y][z] == tup) u.insert(RIGHT_BLOCK[y][z]);
  if (TOP[x][z] == tup) u.insert(TOP_BLOCK[x][z]);
  if (BOTTOM[x][z] == tup) u.insert(BOTTOM_BLOCK[x][z]);
  if (FRONT[x][y] == tup) u.insert(FRONT_BLOCK[x][y]);
  if (BACK[x][y] == tup) u.insert(BACK_BLOCK[x][y]);
  if ((u.find(0) != u.end()) || (u.size() > 1)) {
    return false;
  }
  return true;
}
void NO() {
  cout << -1;
  exit(0);
}
void rec(int x, int y, int z) {
  if ((f[x][y][z] != -1) || (check(x, y, z))) return;
  f[x][y][z] = 1;
  while (true) {
    int X, Y, Z;
    tie(X, Y, Z) = LEFT[y][z];
    if (f[X][Y][Z] == -1) break;
    LEFT[y][z] = make_tuple(X + 1, Y, Z);
    if (!is_in_borders(X + 1, Y, Z)) {
      if (LEFT_BLOCK[Y][Z] != 0)
        NO();
      else
        break;
    }
    if (f[X + 1][Y][Z] == -1) {
      rec(X + 1, Y, Z);
      break;
    }
  }
  while (true) {
    int X, Y, Z;
    tie(X, Y, Z) = RIGHT[y][z];
    if (f[X][Y][Z] == -1) break;
    RIGHT[y][z] = make_tuple(X - 1, Y, Z);
    if (!is_in_borders(X - 1, Y, Z)) {
      if (RIGHT_BLOCK[Y][Z] != 0)
        NO();
      else
        break;
    }
    if (f[X - 1][Y][Z] == -1) {
      rec(X - 1, Y, Z);
      break;
    }
  }
  while (true) {
    int X, Y, Z;
    tie(X, Y, Z) = BOTTOM[x][z];
    if (f[X][Y][Z] == -1) break;
    BOTTOM[x][z] = make_tuple(X, Y + 1, Z);
    if (!is_in_borders(X, Y + 1, Z)) {
      if (BOTTOM_BLOCK[X][Z] != 0)
        NO();
      else
        break;
    }
    if (f[X][Y + 1][Z] == -1) {
      rec(X, Y + 1, Z);
      break;
    }
  }
  while (true) {
    int X, Y, Z;
    tie(X, Y, Z) = TOP[x][z];
    if (f[X][Y][Z] == -1) break;
    TOP[x][z] = make_tuple(X, Y - 1, Z);
    if (!is_in_borders(X, Y - 1, Z)) {
      if (TOP_BLOCK[X][Z] != 0)
        NO();
      else
        break;
    }
    if (f[X][Y - 1][Z] == -1) {
      rec(X, Y - 1, Z);
      break;
    }
  }
  while (true) {
    int X, Y, Z;
    tie(X, Y, Z) = FRONT[x][y];
    if (f[X][Y][Z] == -1) break;
    FRONT[x][y] = make_tuple(X, Y, Z + 1);
    if (!is_in_borders(X, Y, Z + 1)) {
      if (FRONT_BLOCK[X][Y] != 0)
        NO();
      else
        break;
    }
    if (f[X][Y][Z + 1] == -1) {
      rec(X, Y, Z + 1);
      break;
    }
  }
  while (true) {
    int X, Y, Z;
    tie(X, Y, Z) = BACK[x][y];
    if (f[X][Y][Z] == -1) break;
    BACK[x][y] = make_tuple(X, Y, Z - 1);
    if (!is_in_borders(X, Y, Z - 1)) {
      if (BACK_BLOCK[X][Y] != 0)
        NO();
      else
        break;
    }
    if (f[X][Y][Z - 1] == -1) {
      rec(X, Y, Z - 1);
      break;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  f.resize(n + 2, vector<vector<int>>(m + 2, vector<int>(k + 2, -1)));
  LEFT.resize(m + 1, vector<tuple<int, int, int>>(k + 1));
  RIGHT.resize(m + 1, vector<tuple<int, int, int>>(k + 1));
  TOP.resize(n + 1, vector<tuple<int, int, int>>(k + 1));
  BOTTOM.resize(n + 1, vector<tuple<int, int, int>>(k + 1));
  FRONT.resize(n + 1, vector<tuple<int, int, int>>(m + 1));
  BACK.resize(n + 1, vector<tuple<int, int, int>>(m + 1));
  LEFT_BLOCK.resize(m + 1, vector<int>(k + 1, 0));
  RIGHT_BLOCK.resize(m + 1, vector<int>(k + 1, 0));
  TOP_BLOCK.resize(n + 1, vector<int>(k + 1, 0));
  BOTTOM_BLOCK.resize(n + 1, vector<int>(k + 1, 0));
  FRONT_BLOCK.resize(n + 1, vector<int>(m + 1, 0));
  BACK_BLOCK.resize(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= k; ++j) {
      LEFT[i][j] = make_tuple(1, i, j);
      RIGHT[i][j] = make_tuple(n, i, j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      BOTTOM[i][j] = make_tuple(i, 1, j);
      TOP[i][j] = make_tuple(i, m, j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      FRONT[i][j] = make_tuple(i, j, 1);
      BACK[i][j] = make_tuple(i, j, k);
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= k; ++j) {
      cin >> LEFT_BLOCK[i][j];
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= k; ++j) {
      cin >> RIGHT_BLOCK[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      cin >> BOTTOM_BLOCK[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      cin >> TOP_BLOCK[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> FRONT_BLOCK[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> BACK_BLOCK[i][j];
    }
  }
  bool ff = false;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int z = 1; z <= k; ++z) {
        if ((f[i][j][z] != -1) || ff) continue;
        rec(i, j, z);
      }
    }
  }
  cout << endl;
  for (int x = 1; x <= n; ++x) {
    for (int y = 1; y <= m; ++y) {
      for (int z = 1; z <= k; ++z) {
        if (f[x][y][z] != -1)
          f[x][y][z] = 0;
        else {
          f[x][y][z] = 0;
          tuple<int, int, int> tup = make_tuple(x, y, z);
          if (LEFT[y][z] == tup) f[x][y][z] = LEFT_BLOCK[y][z];
          if (RIGHT[y][z] == tup) f[x][y][z] = RIGHT_BLOCK[y][z];
          if (TOP[x][z] == tup) f[x][y][z] = TOP_BLOCK[x][z];
          if (BOTTOM[x][z] == tup) f[x][y][z] = BOTTOM_BLOCK[x][z];
          if (FRONT[x][y] == tup) f[x][y][z] = FRONT_BLOCK[x][y];
          if (BACK[x][y] == tup) f[x][y][z] = BACK_BLOCK[x][y];
        }
        cout << f[x][y][z] << " ";
      }
    }
  }
  cerr << endl << (clock() - START_TIME) / CLOCKS_PER_SEC << " sec." << endl;
}
