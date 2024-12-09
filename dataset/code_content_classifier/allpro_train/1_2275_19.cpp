#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > ans, v;
void move(int a, int b, int type) {
  vector<int> t;
  if (type == 1) {
    t.push_back(a);
    t.push_back(b);
    t.push_back(a + 1);
    t.push_back(b);
    t.push_back(a);
    t.push_back(b + 1);
    v[a][b] ^= 1;
    v[a + 1][b] ^= 1;
    v[a][b + 1] ^= 1;
  } else if (type == 2) {
    t.push_back(a);
    t.push_back(b);
    t.push_back(a);
    t.push_back(b + 1);
    t.push_back(a + 1);
    t.push_back(b + 1);
    v[a][b] ^= 1;
    v[a + 1][b + 1] ^= 1;
    v[a][b + 1] ^= 1;
  } else if (type == 3) {
    t.push_back(a);
    t.push_back(b + 1);
    t.push_back(a + 1);
    t.push_back(b + 1);
    t.push_back(a + 1);
    t.push_back(b);
    v[a][b + 1] ^= 1;
    v[a + 1][b + 1] ^= 1;
    v[a + 1][b] ^= 1;
  } else if (type == 4) {
    t.push_back(a + 1);
    t.push_back(b + 1);
    t.push_back(a + 1);
    t.push_back(b);
    t.push_back(a);
    t.push_back(b);
    v[a][b] ^= 1;
    v[a + 1][b] ^= 1;
    v[a + 1][b + 1] ^= 1;
  }
  ans.push_back(t);
}
int type(int a, int b) {
  if (v[a][b] == 0 and v[a][b + 1] == 0 and v[a + 1][b] == 0 and
      v[a + 1][b + 1] == 0)
    return 1;
  if (v[a][b] == 0 and v[a][b + 1] == 0 and v[a + 1][b] == 0 and
      v[a + 1][b + 1] == 1)
    return 2;
  if (v[a][b] == 0 and v[a][b + 1] == 0 and v[a + 1][b] == 1 and
      v[a + 1][b + 1] == 0)
    return 3;
  if (v[a][b] == 0 and v[a][b + 1] == 0 and v[a + 1][b] == 1 and
      v[a + 1][b + 1] == 1)
    return 4;
  if (v[a][b] == 0 and v[a][b + 1] == 1 and v[a + 1][b] == 0 and
      v[a + 1][b + 1] == 0)
    return 5;
  if (v[a][b] == 0 and v[a][b + 1] == 1 and v[a + 1][b] == 0 and
      v[a + 1][b + 1] == 1)
    return 6;
  if (v[a][b] == 0 and v[a][b + 1] == 1 and v[a + 1][b] == 1 and
      v[a + 1][b + 1] == 0)
    return 7;
  if (v[a][b] == 0 and v[a][b + 1] == 1 and v[a + 1][b] == 1 and
      v[a + 1][b + 1] == 1)
    return 8;
  if (v[a][b] == 1 and v[a][b + 1] == 0 and v[a + 1][b] == 0 and
      v[a + 1][b + 1] == 0)
    return 9;
  if (v[a][b] == 1 and v[a][b + 1] == 0 and v[a + 1][b] == 0 and
      v[a + 1][b + 1] == 1)
    return 10;
  if (v[a][b] == 1 and v[a][b + 1] == 0 and v[a + 1][b] == 1 and
      v[a + 1][b + 1] == 0)
    return 11;
  if (v[a][b] == 1 and v[a][b + 1] == 0 and v[a + 1][b] == 1 and
      v[a + 1][b + 1] == 1)
    return 12;
  if (v[a][b] == 1 and v[a][b + 1] == 1 and v[a + 1][b] == 0 and
      v[a + 1][b + 1] == 0)
    return 13;
  if (v[a][b] == 1 and v[a][b + 1] == 1 and v[a + 1][b] == 0 and
      v[a + 1][b + 1] == 1)
    return 14;
  if (v[a][b] == 1 and v[a][b + 1] == 1 and v[a + 1][b] == 1 and
      v[a + 1][b + 1] == 0)
    return 15;
  if (v[a][b] == 1 and v[a][b + 1] == 1 and v[a + 1][b] == 1 and
      v[a + 1][b + 1] == 1)
    return 16;
}
void func(int a, int b, int type) {
  if (type == 2) {
    move(a, b, 2);
    move(a, b, 4);
    move(a, b, 3);
  } else if (type == 3) {
    move(a, b, 1);
    move(a, b, 4);
    move(a, b, 3);
  } else if (type == 4) {
    move(a, b, 2);
    move(a, b, 1);
  } else if (type == 5) {
    move(a, b, 3);
    move(a, b, 1);
    move(a, b, 2);
  } else if (type == 6) {
    move(a, b, 4);
    move(a, b, 1);
  } else if (type == 7) {
    move(a, b, 4);
    move(a, b, 2);
  } else if (type == 8) {
    move(a, b, 3);
  } else if (type == 9) {
    move(a, b, 2);
    move(a, b, 4);
    move(a, b, 1);
  } else if (type == 10) {
    move(a, b, 1);
    move(a, b, 3);
  } else if (type == 11) {
    move(a, b, 3);
    move(a, b, 2);
  } else if (type == 12) {
    move(a, b, 4);
  } else if (type == 13) {
    move(a, b, 4);
    move(a, b, 3);
  } else if (type == 14) {
    move(a, b, 2);
  } else if (type == 15) {
    move(a, b, 1);
  } else if (type == 16) {
    move(a, b, 1);
    move(a, b, 2);
    move(a, b, 4);
    move(a, b, 3);
  }
}
int main() {
  int te;
  cin >> te;
  for (int w = 0; w < te; w++) {
    int n, m;
    cin >> n >> m;
    v.clear();
    vector<int> t(m);
    v.resize(n, t);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        int a = c - '0';
        v[i][j] = a;
      }
    ans.clear();
    for (int i = 0; i < n; i += 2) {
      for (int j = 0; j < m; j += 2) {
        if (i == n - 1) i -= 1;
        if (j == m - 1) j -= 1;
        int x = type(i, j);
        func(i, j, x);
      }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
      for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] + 1 << " ";
      cout << endl;
    }
  }
}
