#include <bits/stdc++.h>
#pragma comment(linker, "/stack:32000000")
using namespace std;
int GetReversed(int col) {
  if (col == 1) {
    return 2;
  } else {
    return 1;
  }
}
long long n, m, x, y, k1, k2;
bool met[100010];
int col[100010], ans[100010];
vector<int> edge[100010];
vector<int> d1, d2;
bool nb[100010];
void DFS(int index, int color) {
  met[index] = true;
  col[index] = color;
  if (color == 1) {
    d1.push_back(index);
    ++k1;
  } else {
    d2.push_back(index);
    ++k2;
  }
  for (int i = 0; i < edge[index].size(); ++i) {
    if (!met[edge[index][i]]) {
      DFS(edge[index][i], GetReversed(color));
    }
  }
}
void colorize(int initCol) {
  int tec = initCol;
  int nm = 0;
  for (int i = 0; i < k1; ++i) {
    if (ans[d1[i]] == 0) {
      if (nm == 3) {
        nm = 0;
        ++tec;
      }
      ++nm;
      ans[d1[i]] = tec;
    }
  }
  for (int i = 0; i < k2; ++i) {
    if (ans[d2[i]] == 0) {
      if (nm == 3) {
        nm = 0;
        ++tec;
      }
      ++nm;
      ans[d2[i]] = tec;
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    if (!met[i]) {
      DFS(i, 1);
    }
  }
  if (k1 % 3 == 0) {
    colorize(1);
  }
  if (k1 % 3 == 2) {
    d1.clear();
    d2.clear();
    for (int i = 1; i <= n; ++i) {
      col[i] = GetReversed(col[i]);
      if (col[i] == 1) {
        d1.push_back(i);
      } else {
        d2.push_back(i);
      }
    }
    swap(k1, k2);
  }
  if (k1 % 3 == 1) {
    int mn = 0;
    for (int i = 1; i < k1; ++i) {
      if (edge[d1[i]].size() < edge[d1[mn]].size()) {
        mn = i;
      }
    }
    if (edge[d1[mn]].size() > k2 - 2) {
      int met = 0;
      for (int i = 0; (i < k2) && (met != 2); ++i) {
        if (edge[d2[i]].size() <= k1 - 2) {
          nb[d2[i]] = true;
          for (int j = 0; j < edge[d2[i]].size(); ++j) {
            nb[edge[d2[i]][j]] = true;
          }
          ++met;
          ans[d2[i]] = met;
          int meted = 0;
          for (int j = 1; meted != 2; ++j) {
            if ((!nb[j]) && (col[j] != col[d2[i]])) {
              ++meted;
              ans[j] = met;
            }
          }
          for (int j = 1; j <= n; ++j) {
            nb[j] = false;
          }
        }
      }
      if (met != 2) {
        cout << "NO" << endl;
        return 0;
      } else {
        colorize(3);
      }
    } else {
      nb[d1[mn]] = true;
      for (int i = 0; i < edge[d1[mn]].size(); ++i) {
        nb[edge[d1[mn]][i]] = true;
      }
      ans[d1[mn]] = 1;
      int meted = 0;
      for (int i = 1; meted != 2; ++i) {
        if ((!nb[i]) && (col[i] != col[d1[mn]])) {
          ++meted;
          ans[i] = 1;
        }
      }
      colorize(2);
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; ++i) {
    if (i != 1) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
