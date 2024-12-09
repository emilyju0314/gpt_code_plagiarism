#include <bits/stdc++.h>
using namespace std;
void iterate(int l, int r, vector<vector<char>> &v_copy, vector<vector<char>> v,
             int k) {
  int n = v_copy.size();
  int m = v_copy[0].size();
  int count = 0;
  int left = r, right = r, depth = l;
  vector<pair<int, int>> v_pair;
  while (left >= 0 && right < m && depth >= 0) {
    if (v[depth][left] == '*' && v[depth][right] == '*') {
      count = count + 2;
      v_pair.push_back(make_pair(depth, left));
      v_pair.push_back(make_pair(depth, right));
    } else if (v[depth][left] == '.' || v[depth][right] == '.') {
      break;
    }
    depth--;
    left--;
    right++;
  }
  if (count >= (2 * k + 2)) {
    for (auto &it : v_pair) {
      v_copy[it.first][it.second] = '*';
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> v;
    for (int i = 0; i < n; i++) {
      vector<char> temp;
      for (int j = 0; j < m; j++) {
        char a;
        cin >> a;
        temp.push_back(a);
      }
      v.push_back(temp);
    }
    vector<vector<char>> v_copy(n, vector<char>(m, '.'));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (v[i][j] == '*') {
          iterate(i, j, v_copy, v, k);
        }
      }
    }
    if (v_copy == v)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
