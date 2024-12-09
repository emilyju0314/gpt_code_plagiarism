#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;
constexpr int INF = INT32_MAX;
constexpr int MAXN = 1e3 + 10;
constexpr double eps = 1e-8;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
using Vec = vector<int>;
template <class T>
void Min(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
void Max(T &a, T b) {
  if (b > a) a = b;
}
ll N, M, K, T;
Vec A;
vector<Pii> dirs = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
vector<Pii> moves_from[MAXN][MAXN];
vector<Pii> pos;
bool vis_white[MAXN][MAXN];
bool vis_black[MAXN][MAXN];
int dist_white_goal[MAXN][MAXN];
int dist_black_goal[MAXN][MAXN];
int act;
int white_x, white_y, black_x, black_y;
void LegalMoves(int x, int y) {
  for (auto d : dirs) {
    int nx = x + d.first, ny = y + d.second;
    if (1 <= nx && nx <= N && 1 <= ny && ny <= M)
      moves_from[x][y].emplace_back(nx, ny);
  }
}
void BfsWhite(int x, int y) {
  if (1 <= x && x <= N && 1 <= y && y <= M) {
    for (auto to : moves_from[x][y]) {
      if (!vis_white[to.first][to.second]) {
        dist_white_goal[to.first][to.second] = 1 + dist_white_goal[x][y];
        vis_white[to.first][to.second] = true;
        pos.emplace_back(to.first, to.second);
      }
    }
  }
  if (act + 1 < pos.size()) {
    act++;
    BfsWhite(pos[act].first, pos[act].second);
  }
}
void BfsBlack(int x, int y) {
  if (1 <= x && x <= N && 1 <= y && y <= M) {
    for (auto to : moves_from[x][y]) {
      if (!vis_black[to.first][to.second]) {
        dist_black_goal[to.first][to.second] = 1 + dist_black_goal[x][y];
        vis_black[to.first][to.second] = true;
        pos.emplace_back(to.first, to.second);
      }
    }
  }
  if (act + 1 < pos.size()) {
    act++;
    BfsBlack(pos[act].first, pos[act].second);
  }
}
void Solution() {
  for (int i = (int)(1); i < (int)(N + 1); ++i) {
    for (int j = (int)(1); j < (int)(M + 1); ++j) LegalMoves(i, j);
  }
  vis_white[N / 2][M / 2] = true;
  act = -1;
  BfsWhite(N / 2, M / 2);
  act = -1;
  pos.clear();
  vis_black[N / 2 + 1][M / 2] = true;
  BfsBlack(N / 2 + 1, M / 2);
  if (dist_white_goal[white_x][white_y] + 1 <=
          dist_white_goal[black_x][black_y] &&
      dist_white_goal[white_x][white_y] <= dist_black_goal[black_x][black_y]) {
    cout << "WHITE" << endl;
    while (white_x != N / 2 || white_y != M / 2) {
      for (auto to : moves_from[white_x][white_y]) {
        if (dist_white_goal[to.first][to.second] <
            dist_white_goal[white_x][white_y]) {
          cout << to.first << ' ' << to.second << endl;
          white_x = to.first, white_y = to.second;
          if (white_x == black_x && white_y == black_y) return;
          if (white_x != N / 2 || white_y != M / 2) cin >> black_x >> black_y;
          break;
        }
      }
    }
    return;
  }
  if (dist_black_goal[black_x][black_y] + 2 <=
          dist_black_goal[white_x][white_y] &&
      dist_black_goal[black_x][black_y] + 1 <=
          dist_white_goal[white_x][white_y]) {
    cout << "BLACK" << endl;
    while (black_x != N / 2 + 1 || black_y != M / 2) {
      for (auto to : moves_from[black_x][black_y]) {
        if (dist_black_goal[to.first][to.second] <
            dist_black_goal[black_x][black_y]) {
          cout << to.first << ' ' << to.second << endl;
          black_x = to.first, black_y = to.second;
          if (white_x == black_x && white_y == black_y) return;
          if (black_x != N / 2 + 1 || black_y != M / 2)
            cin >> white_x >> white_y;
          break;
        }
      }
    }
    return;
  }
  if ((white_x + white_y) % 2 != (black_x + black_y) % 2) {
    cout << "WHITE" << endl;
    if (dist_white_goal[white_x][white_y] <=
        dist_black_goal[black_x][black_y]) {
      while (white_x != N / 2 || white_y != M / 2) {
        for (auto to : moves_from[white_x][white_y]) {
          if (dist_white_goal[to.first][to.second] <
              dist_white_goal[white_x][white_y]) {
            cout << to.first << ' ' << to.second << endl;
            white_x = to.first, white_y = to.second;
            if (white_x == black_x && white_y == black_y) return;
            cin >> black_x >> black_y;
            break;
          }
        }
      }
    } else {
      while (white_x != N / 2 + 1 || white_y != M / 2) {
        for (auto to : moves_from[white_x][white_y]) {
          if (dist_black_goal[to.first][to.second] <
              dist_black_goal[white_x][white_y]) {
            cout << to.first << ' ' << to.second << endl;
            if (black_x == to.first && black_y == to.second) return;
            white_x = to.first, white_y = to.second;
            cin >> black_x >> black_y;
            break;
          }
        }
      }
      for (auto to : moves_from[white_x][white_y]) {
        if (black_x == to.first && black_y == to.second) {
          cout << to.first << ' ' << to.second << endl;
          return;
        }
      }
      while (white_x != N / 2 || white_y != M / 2) {
        for (auto to : moves_from[white_x][white_y]) {
          if (dist_white_goal[to.first][to.second] <
              dist_white_goal[white_x][white_y]) {
            cout << to.first << ' ' << to.second << endl;
            if (black_x == to.first && black_y == to.second) return;
            white_x = to.first, white_y = to.second;
            if (white_x != N / 2 || white_y != M / 2) cin >> black_x >> black_y;
            break;
          }
        }
      }
    }
    return;
  } else {
    cout << "BLACK" << endl;
    cin >> white_x >> white_y;
    if (dist_white_goal[white_x][white_y] >=
        dist_black_goal[black_x][black_y]) {
      while (black_x != N / 2 + 1 || black_y != M / 2) {
        for (auto to : moves_from[black_x][black_y]) {
          if (dist_black_goal[to.first][to.second] <
              dist_black_goal[black_x][black_y]) {
            cout << to.first << ' ' << to.second << endl;
            black_x = to.first, black_y = to.second;
            if (white_x == black_x && white_y == black_y) return;
            cin >> white_x >> white_y;
            break;
          }
        }
      }
    } else {
      while (black_x != N / 2 || black_y != M / 2) {
        for (auto to : moves_from[black_x][black_y]) {
          if (dist_white_goal[to.first][to.second] <
              dist_white_goal[black_x][black_y]) {
            cout << to.first << ' ' << to.second << endl;
            black_x = to.first, black_y = to.second;
            if (white_x == black_x && white_y == black_y) return;
            cin >> white_x >> white_y;
            break;
          }
        }
      }
      for (auto to : moves_from[black_x][black_y]) {
        if (white_x == to.first && white_y == to.second) {
          cout << to.first << ' ' << to.second << endl;
          return;
        }
      }
      while (black_x != N / 2 + 1 || black_y != M / 2) {
        for (auto to : moves_from[black_x][black_y]) {
          if (dist_black_goal[to.first][to.second] <
              dist_black_goal[black_x][black_y]) {
            cout << to.first << ' ' << to.second << endl;
            black_x = to.first, black_y = to.second;
            if (white_x == black_x && white_y == black_y) return;
            if (black_x != N / 2 + 1 || black_y != M / 2)
              cin >> white_x >> white_y;
            break;
          }
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> N >> M;
  cin >> white_x >> white_y >> black_x >> black_y;
  Solution();
  return 0;
}
