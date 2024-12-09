#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string a[n];
    for (auto &i : a) cin >> i;
    int k{};
    vector<pair<int, int>> v;
    for (int i = 0; i < n - 2; i++) {
      for (int j = 0; j < m - 1; j++) {
        if (a[i][j] == '1') {
          v.push_back(make_pair(i, j));
          a[i][j] = '0';
          v.push_back(make_pair(i + 1, j));
          if (a[i + 1][j] == '1')
            a[i + 1][j] = '0';
          else
            a[i + 1][j] = '1';
          if (a[i][j + 1] == '1') {
            v.push_back(make_pair(i, j + 1));
            a[i][j + 1] = '0';
          } else {
            v.push_back(make_pair(i + 1, j + 1));
            if (a[i + 1][j + 1] == '0')
              a[i + 1][j + 1] = '1';
            else
              a[i + 1][j + 1] = '0';
          }
        } else {
          if (a[i][j + 1] == '1') {
            v.push_back(make_pair(i, j + 1));
            a[i][j + 1] = '0';
            v.push_back(make_pair(i + 1, j + 1));
            if (a[i + 1][j + 1] == '0')
              a[i + 1][j + 1] = '1';
            else
              a[i + 1][j + 1] = '0';
            v.push_back(make_pair(i + 1, j));
            if (a[i + 1][j] == '1')
              a[i + 1][j] = '0';
            else
              a[i + 1][j] = '1';
          }
        }
      }
    }
    for (int j = 0; j < m - 2; j++) {
      int i = n - 2;
      if (a[i][j] == '1') {
        v.push_back(make_pair(i, j));
        a[i][j] = '0';
        v.push_back(make_pair(i, j + 1));
        if (a[i][j + 1] == '1')
          a[i][j + 1] = '0';
        else
          a[i][j + 1] = '1';
        if (a[i + 1][j] == '1') {
          v.push_back(make_pair(i + 1, j));
          a[i + 1][j] = '0';
        } else {
          v.push_back(make_pair(i + 1, j + 1));
          if (a[i + 1][j + 1] == '0')
            a[i + 1][j + 1] = '1';
          else
            a[i + 1][j + 1] = '0';
        }
      } else {
        if (a[i + 1][j] == '1') {
          v.push_back(make_pair(i + 1, j));
          a[i + 1][j] = '0';
          v.push_back(make_pair(i + 1, j + 1));
          if (a[i + 1][j + 1] == '0')
            a[i + 1][j + 1] = '1';
          else
            a[i + 1][j + 1] = '0';
          v.push_back(make_pair(i, j + 1));
          if (a[i][j + 1] == '1')
            a[i][j + 1] = '0';
          else
            a[i][j + 1] = '1';
        }
      }
    }
    bool done = false;
    int x1 = n - 2, x2 = n - 1, y1 = m - 2, y2 = m - 1;
    while (!done) {
      if (a[x1][y1] - '0' + a[x1][y2] - '0' + a[x2][y1] - '0' + a[x2][y2] -
              '0' ==
          4) {
        v.push_back(make_pair(x1, y1));
        v.push_back(make_pair(x1, y2));
        v.push_back(make_pair(x2, y1));
        a[x1][y1] = '0';
        a[x1][y2] = '0';
        a[x2][y1] = '0';
      }
      if (a[x1][y1] - '0' + a[x1][y2] - '0' + a[x2][y1] - '0' + a[x2][y2] -
              '0' ==
          1) {
        if (a[x1][y1] - '0') {
          v.push_back(make_pair(x1, y1));
          v.push_back(make_pair(x1, y2));
          v.push_back(make_pair(x2, y1));
          a[x1][y1] = '0';
          a[x1][y2] = '1';
          a[x2][y1] = '1';
        } else if (a[x1][y2] - '0') {
          v.push_back(make_pair(x1, y1));
          v.push_back(make_pair(x1, y2));
          v.push_back(make_pair(x2, y1));
          a[x1][y1] = '1';
          a[x1][y2] = '0';
          a[x2][y1] = '1';
        } else if (a[x2][y1] - '0') {
          v.push_back(make_pair(x1, y1));
          v.push_back(make_pair(x1, y2));
          v.push_back(make_pair(x2, y1));
          a[x1][y1] = '1';
          a[x1][y2] = '1';
          a[x2][y1] = '0';
        } else if (a[x2][y2] - '0') {
          v.push_back(make_pair(x1, y1));
          v.push_back(make_pair(x1, y2));
          v.push_back(make_pair(x2, y2));
          a[x1][y1] = '1';
          a[x1][y2] = '1';
          a[x2][y2] = '0';
        }
      }
      if (a[x1][y1] - '0' + a[x1][y2] - '0' + a[x2][y1] - '0' + a[x2][y2] -
              '0' ==
          2) {
        int count = 1;
        if (a[x1][y1] - '0') {
          count--;
          v.push_back(make_pair(x1, y1));
          a[x1][y1] = '0';
        } else {
          v.push_back(make_pair(x1, y1));
          a[x1][y1] = '1';
        }
        if (a[x1][y2] - '0') {
          if (count) {
            count--;
            v.push_back(make_pair(x1, y2));
            a[x1][y2] = '0';
          }
        } else {
          v.push_back(make_pair(x1, y2));
          a[x1][y2] = '1';
        }
        if (a[x2][y2] - '0') {
          if (count) {
            count--;
            v.push_back(make_pair(x2, y2));
            a[x2][y2] = '0';
          }
        } else {
          v.push_back(make_pair(x2, y2));
          a[x2][y2] = '1';
        }
        if (a[x2][y1] - '0') {
          if (count) {
            count--;
            v.push_back(make_pair(x2, y1));
            a[x2][y1] = '0';
          }
        } else {
          v.push_back(make_pair(x2, y1));
          a[x2][y1] = '1';
        }
      }
      if (a[x1][y1] - '0' + a[x1][y2] - '0' + a[x2][y1] - '0' + a[x2][y2] -
              '0' ==
          3) {
        done = true;
        if (a[x1][y1] - '0') {
          v.push_back(make_pair(x1, y1));
          a[x1][y1] = '0';
        }
        if (a[x1][y2] - '0') {
          v.push_back(make_pair(x1, y2));
          a[x1][y2] = '0';
        }
        if (a[x2][y1] - '0') {
          v.push_back(make_pair(x2, y1));
          a[x2][y1] = '0';
        }
        if (a[x2][y2] - '0') {
          v.push_back(make_pair(x2, y2));
          a[x2][y2] = '0';
        }
      }
      if (a[x1][y1] - '0' + a[x1][y2] - '0' + a[x2][y1] - '0' + a[x2][y2] -
              '0' ==
          0) {
        done = true;
      }
    }
    k = v.size() / 3;
    cout << k << endl;
    for (int i = 0; i < v.size(); i += 3) {
      cout << v[i].first + 1 << " " << v[i].second + 1 << " ";
      cout << v[i + 1].first + 1 << " " << v[i + 1].second + 1 << " ";
      cout << v[i + 2].first + 1 << " " << v[i + 2].second + 1 << endl;
    }
  }
}
