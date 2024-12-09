#include <bits/stdc++.h>
using namespace std;
void ToVertical(int i, int j, vector<vector<char>> &status,
                vector<pair<int, int>> &ret);
void ToHorizontal(int i, int j, vector<vector<char>> &status,
                  vector<pair<int, int>> &ret);
vector<pair<int, int>> Relay(vector<vector<char>> status) {
  int n = status.size();
  int m = status[0].size();
  if (n % 2 == 1) {
    vector<vector<char>> new_status(m, vector<char>(n));
    for (int i = 0; i < int(n); ++i)
      for (int j = 0; j < int(m); ++j) {
        new_status[j][i] = status[i][j];
        if (new_status[j][i] == 'L') {
          new_status[j][i] = 'U';
        } else if (new_status[j][i] == 'U') {
          new_status[j][i] = 'L';
        } else if (new_status[j][i] == 'D') {
          new_status[j][i] = 'R';
        } else if (new_status[j][i] == 'R') {
          new_status[j][i] = 'D';
        }
      }
    auto ret = Relay(new_status);
    for (auto &it : ret) {
      swap(it.first, it.second);
    }
    return ret;
  }
  vector<pair<int, int>> ret;
  for (int j = 0; j < int(m); ++j) {
    for (int i = 0; i < int(n); ++i)
      if (status[i][j] == 'L') {
        ToVertical(i, j, status, ret);
      }
  }
  return ret;
}
void ToVertical(int i, int j, vector<vector<char>> &status,
                vector<pair<int, int>> &ret) {
  if (status[i + 1][j] == 'U') {
    ToHorizontal(i + 1, j, status, ret);
  }
  ret.push_back({i, j});
  status[i][j] = status[i][j + 1] = 'U';
  status[i + 1][j] = status[i + 1][j + 1] = 'D';
}
void ToHorizontal(int i, int j, vector<vector<char>> &status,
                  vector<pair<int, int>> &ret) {
  if (status[i][j + 1] == 'L') {
    ToVertical(i, j + 1, status, ret);
  }
  ret.push_back({i, j});
  status[i][j] = status[i + 1][j] = 'L';
  status[i][j + 1] = status[i + 1][j + 1] = 'R';
}
vector<vector<char>> ReadStatus(int n, int m) {
  vector<vector<char>> status(n, vector<char>(m));
  for (int i = 0; i < int(n); ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < int(m); ++j) status[i][j] = s[j];
  }
  return status;
}
int Main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  auto steps1 = Relay(ReadStatus(n, m));
  auto steps2 = Relay(ReadStatus(n, m));
  reverse(steps2.begin(), steps2.end());
  cout << steps1.size() + steps2.size() << endl;
  for (auto it : steps1) cout << it.first + 1 << " " << it.second + 1 << endl;
  for (auto it : steps2) cout << it.first + 1 << " " << it.second + 1 << endl;
  return 0;
}
int main() { return Main(); }
