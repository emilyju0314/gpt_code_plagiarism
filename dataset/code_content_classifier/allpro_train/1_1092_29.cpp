#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int read() {
  char ch = getchar();
  int f = 1, x = 0;
  while (ch < '0' or ch > '9') {
    if (ch == '-') {
      f = -1;
      ch = getchar();
    }
  }
  while (ch >= '0' and ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct CARD {
  int suit;
  int rank;
  CARD(char s[]) {
    if (s[0] == 'J' and s[1] == '1') {
      suit = 4;
      rank = 0;
      return;
    } else if (s[0] == 'J' and s[1] == '2') {
      suit = 4;
      rank = 1;
      return;
    }
    if (s[1] == 'S') {
      suit = 0;
    } else if (s[1] == 'H') {
      suit = 1;
    } else if (s[1] == 'C') {
      suit = 2;
    } else {
      suit = 3;
    }
    if (s[0] == 'A') {
      rank = 1;
    } else if (s[0] == 'T') {
      rank = 10;
    } else if (s[0] == 'J') {
      rank = 11;
    } else if (s[0] == 'Q') {
      rank = 12;
    } else if (s[0] == 'K') {
      rank = 0;
    } else {
      rank = s[0] - '0';
    }
  }
  CARD(int x = 0) {
    suit = x / 13;
    rank = x % 13;
  }
  int get_val() { return suit * 13 + rank; }
  string tostring() {
    string s = "";
    if (rank == 0) {
      s += 'K';
    } else if (rank == 1) {
      s += 'A';
    } else if (rank == 10) {
      s += 'T';
    } else if (rank == 11) {
      s += 'J';
    } else if (rank == 12) {
      s += 'Q';
    } else {
      s += (rank + '0');
    }
    if (suit == 0) {
      s += 'S';
    } else if (suit == 1) {
      s += 'H';
    } else if (suit == 2) {
      s += 'C';
    } else {
      s += 'D';
    }
    return s;
  }
};
int n, m;
int ans[2];
CARD maze[105][105];
bool hav[105];
bool flush(int x, int y) {
  int a = maze[x][y].suit;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (maze[x + i][y + j].suit != a) {
        return false;
      }
    }
  }
  return true;
}
bool straight(int x, int y) {
  bool vis[15];
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (vis[maze[x + i][y + j].rank]) {
        return false;
      }
      vis[maze[x + i][y + j].rank] = true;
    }
  }
  return true;
}
void dfs(int x) {
  if (x == 0) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = i; k < n; k++) {
          for (int l = 0; l < m; l++) {
            if (abs(i - k) < 3 and abs(j - l) < 3) {
              continue;
            }
            if (i + 3 > n or j + 3 > m or k + 3 > n or l + 3 > m) {
              continue;
            }
            if (!flush(i, j) and !straight(i, j)) {
              continue;
            }
            if (!flush(k, l) and !straight(k, l)) {
              continue;
            }
            cout << "Solution exists." << endl;
            if (hav[52] and hav[53]) {
              cout << "Replace J1 with " << CARD(ans[0]).tostring()
                   << " and J2 with " << CARD(ans[1]).tostring() << "." << endl;
            } else if (hav[52]) {
              cout << "Replace J1 with " << CARD(ans[0]).tostring() << "."
                   << endl;
            } else if (hav[53]) {
              cout << "Replace J2 with " << CARD(ans[1]).tostring() << "."
                   << endl;
            } else {
              cout << "There are no jokers." << endl;
            }
            cout << "Put the first square to (" << i + 1 << ", " << j + 1
                 << ")." << endl;
            cout << "Put the second square to (" << k + 1 << ", " << l + 1
                 << ")." << endl;
            exit(0);
          }
        }
      }
    }
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (maze[i][j].get_val() >= 52) {
        int tmp = maze[i][j].get_val();
        for (int k = 0; k < 52; k++) {
          if (!hav[k]) {
            ans[tmp - 52] = k;
            hav[k] = true;
            maze[i][j] = CARD(k);
            dfs(x - 1);
            hav[k] = false;
          }
        }
        maze[i][j] = CARD(tmp);
      }
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char s[5];
      memset(s, 0, sizeof(s));
      cin >> s;
      maze[i][j] = CARD(s);
      hav[maze[i][j].get_val()] = true;
    }
  }
  dfs(hav[52] + hav[53]);
  cout << "No solution.";
  return 0;
}
