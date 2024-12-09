#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> board;
vector<string> grid;
vector<string> cpy;
void rot() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cpy[i][j] = grid[n - 1 - j][i];
}
void copyy() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) grid[i][j] = cpy[i][j];
}
void reflecthoriz() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cpy[i][j] = grid[i][n - 1 - j];
}
void reflectvert() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cpy[i][j] = grid[n - 1 - i][j];
}
bool match() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (grid[i][j] != board[i][j]) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < n; j++) {
      string s;
      cin >> s;
      if (i == 1) {
        cpy.push_back(s);
        grid.push_back(s);
      } else
        board.push_back(s);
    }
  bool check = false;
  for (int i = 0; i < 4; i++) {
    if (match()) check = true;
    reflecthoriz();
    copyy();
    if (match()) check = true;
    reflecthoriz();
    copyy();
    reflectvert();
    copyy();
    if (match()) check = true;
    reflectvert();
    copyy();
    rot();
    copyy();
  }
  cout << (check ? "YES\n" : "NO\n");
  return 0;
}
