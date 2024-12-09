#include <bits/stdc++.h>
using namespace std;
struct Parameter {
  int a, b, i;
};
deque<array<int, 2> > getHamiltonianCycle(int n, int m, int x, int y) {
  deque<array<int, 2> > ret;
  ret.push_back({1, 1});
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 1) {
      for (int j = 2; j <= m; j++) {
        ret.push_back({i, j});
      }
    } else {
      for (int j = m; j >= 2; j--) {
        ret.push_back({i, j});
      }
    }
  }
  for (int i = n; i >= 2; i--) {
    ret.push_back({i, 1});
  }
  while (ret[0][0] != x || ret[0][1] != y) {
    ret.push_back(ret.front());
    ret.pop_front();
  }
  return ret;
}
deque<array<int, 2> > getHamiltonianPath(int n, int m, int x, int y) {
  assert((x + y) % 2 == 0);
  if (y == 1) {
    deque<array<int, 2> > ret = getHamiltonianPath(n, m, x, m);
    for (auto &x : ret) {
      x[1] = m + 1 - x[1];
    }
    return ret;
  }
  if (x == n) {
    deque<array<int, 2> > ret = getHamiltonianPath(n, m, 1, y);
    for (auto &x : ret) {
      x[0] = n + 1 - x[0];
    }
    return ret;
  }
  deque<array<int, 2> > ret;
  if (x % 2 == 1) {
    for (int i = x; i >= 1; i--) {
      ret.push_back({i, y});
    }
    for (int i = 1; i <= x; i++) {
      if (i % 2 == 1) {
        for (int j = y - 1; j >= 1; j--) {
          ret.push_back({i, j});
        }
      } else {
        for (int j = 1; j <= y - 1; j++) {
          ret.push_back({i, j});
        }
      }
    }
    for (int j = 1; j <= y; j++) {
      if (j % 2 == 1) {
        for (int i = x + 1; i <= n; i++) {
          ret.push_back({i, j});
        }
      } else {
        for (int i = n; i >= x + 1; i--) {
          ret.push_back({i, j});
        }
      }
    }
    for (int i = n; i >= 1; i--) {
      if ((n - i + 1) % 2 == 1) {
        for (int j = y + 1; j <= m; j++) {
          ret.push_back({i, j});
        }
      } else {
        for (int j = m; j >= y + 1; j--) {
          ret.push_back({i, j});
        }
      }
    }
  } else {
    for (int i = x; i >= 1; i--) {
      ret.push_back({i, y});
    }
    for (int i = 1; i <= x - 1; i++) {
      if (i % 2 == 1) {
        for (int j = y - 1; j >= 1; j--) {
          ret.push_back({i, j});
        }
      } else {
        for (int j = 1; j <= y - 1; j++) {
          ret.push_back({i, j});
        }
      }
    }
    for (int j = 1; j <= y - 1; j++) {
      if (j % 2 == 1) {
        for (int i = x; i <= n; i++) {
          ret.push_back({i, j});
        }
      } else {
        for (int i = n; i >= x; i--) {
          ret.push_back({i, j});
        }
      }
    }
    for (int i = n; i >= x + 1; i--) {
      if ((n - i + 1) % 2 == 1) {
        for (int j = y; j <= m; j++) {
          ret.push_back({i, j});
        }
      } else {
        for (int j = m; j >= y; j--) {
          ret.push_back({i, j});
        }
      }
    }
    for (int i = x; i >= 1; i--) {
      if ((n - i + 1) % 2 == 1) {
        for (int j = y + 1; j <= m; j++) {
          ret.push_back({i, j});
        }
      } else {
        for (int j = m; j >= y + 1; j--) {
          ret.push_back({i, j});
        }
      }
    }
  }
  return ret;
}
vector<vector<int> > getCycle(Parameter p1, Parameter p2) {
  deque<array<int, 2> > hc = getHamiltonianCycle(p1.a, p2.a, p1.b, p2.b);
  vector<vector<int> > ret;
  for (int i = 0; i < hc.size(); i++) {
    ret.push_back({hc[i][0], hc[i][1]});
  }
  return ret;
}
vector<vector<int> > processCycle(vector<vector<int> > &cycle, Parameter p) {
  deque<array<int, 2> > hc = getHamiltonianCycle(cycle.size(), p.a, 1, p.b);
  vector<vector<int> > ret;
  for (int i = 0; i < hc.size(); i++) {
    vector<int> vec;
    for (auto x : cycle[hc[i][0] - 1]) {
      vec.push_back(x);
    }
    vec.push_back(hc[i][1]);
    ret.push_back(vec);
  }
  return ret;
}
vector<vector<int> > getPath(Parameter p1, Parameter p2) {
  deque<array<int, 2> > hp = getHamiltonianPath(p1.a, p2.a, p1.b, p2.b);
  vector<vector<int> > ret;
  for (int i = 0; i < hp.size(); i++) {
    ret.push_back({hp[i][0], hp[i][1]});
  }
  return ret;
}
vector<vector<int> > processPaths1(vector<vector<int> > &path, Parameter p) {
  deque<array<int, 2> > hp = getHamiltonianPath(path.size(), p.a, 1, p.b);
  vector<vector<int> > ret;
  for (int i = 0; i < hp.size(); i++) {
    vector<int> vec;
    for (auto x : path[hp[i][0] - 1]) {
      vec.push_back(x);
    }
    vec.push_back(hp[i][1]);
    ret.push_back(vec);
  }
  return ret;
}
vector<vector<int> > processPaths2(vector<vector<int> > &path1,
                                   vector<vector<int> > &path2) {
  deque<array<int, 2> > hp =
      getHamiltonianPath(path1.size(), path2.size(), 1, 1);
  vector<vector<int> > ret;
  for (int i = 0; i < hp.size(); i++) {
    vector<int> vec;
    for (auto x : path1[hp[i][0] - 1]) {
      vec.push_back(x);
    }
    for (auto x : path2[hp[i][1] - 1]) {
      vec.push_back(x);
    }
    ret.push_back(vec);
  }
  return ret;
}
vector<array<int, 2> > parse(vector<vector<int> > &vec) {
  vector<array<int, 2> > ret;
  for (int i = 1; i < vec.size(); i++) {
    int ind = -1, diff = -2;
    for (int j = 0; j < vec[i].size(); j++) {
      if (vec[i][j] == vec[i - 1][j]) continue;
      assert(ind == -1);
      ind = j;
      diff = vec[i][j] - vec[i - 1][j];
    }
    ret.push_back({diff, ind});
  }
  return ret;
}
int check(vector<Parameter> p, int m) {
  int cnt0 = 1, cnt1 = 0, sum = 0;
  for (int i = 0; i < m; i++) {
    int even = p[i].a >> 1;
    int odd = p[i].a - even;
    int ncnt0 = cnt0 * even + cnt1 * odd;
    int ncnt1 = cnt1 * even + cnt0 * odd;
    cnt0 = ncnt0;
    cnt1 = ncnt1;
    sum += p[i].b;
  }
  if (cnt0 > cnt1 && sum % 2 != 0) {
    return false;
  }
  if (cnt0 < cnt1 && sum % 2 != 1) {
    return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int m;
  cin >> m;
  vector<Parameter> p(m);
  int tot = 1;
  for (int i = 0; i < m; i++) {
    cin >> p[i].a;
    p[i].i = i;
    tot *= p[i].a;
  }
  for (int i = 0; i < m; i++) {
    cin >> p[i].b;
  }
  if (m == 1) {
    if (p[0].a == 2) {
      cout << "Cycle" << '\n';
      if (p[0].b == 1) {
        cout << "inc 1" << '\n';
        cout << "dec 1" << '\n';
      } else {
        cout << "dec 1" << '\n';
        cout << "inc 1" << '\n';
      }
    } else if (p[0].b == 1) {
      cout << "Path" << '\n';
      for (int i = 1; i < p[0].a; i++) {
        cout << "inc 1" << '\n';
      }
    } else if (p[0].b == p[0].a) {
      cout << "Path" << '\n';
      for (int i = 1; i < p[0].a; i++) {
        cout << "dec 1" << '\n';
      }
    } else {
      cout << "No" << '\n';
    }
    exit(0);
  }
  if (tot % 2 == 0) {
    for (int i = 1; i < m; i++) {
      if (p[i].a % 2 == 0) {
        swap(p[0], p[i]);
        break;
      }
    }
    vector<vector<int> > cycle = getCycle(p[0], p[1]);
    for (int i = 2; i < m; i++) {
      cycle = processCycle(cycle, p[i]);
    }
    for (auto &x : cycle) {
      vector<int> vec(m);
      for (int i = 0; i < m; i++) {
        vec[p[i].i] = x[i];
      }
      x = vec;
    }
    cycle.push_back(cycle.front());
    vector<array<int, 2> > answer = parse(cycle);
    cout << "Cycle" << '\n';
    for (auto x : answer) {
      if (x[0] == 1)
        cout << "inc";
      else
        cout << "dec";
      cout << " " << x[1] + 1 << '\n';
    }
    exit(0);
  }
  if (!check(p, m)) {
    cout << "No" << '\n';
    exit(0);
  }
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      if (p[j].b % 2 == 0) {
        swap(p[i], p[j]);
        break;
      }
    }
  }
  int ind = 0;
  vector<vector<int> > path;
  for (; ind < m; ind += 2) {
    if (p[ind].b % 2 != 0) break;
    assert(p[ind + 1].b % 2 == 0);
    vector<vector<int> > curpath = getPath(p[ind], p[ind + 1]);
    if (path.empty()) {
      path = curpath;
    } else {
      path = processPaths2(path, curpath);
    }
  }
  if (path.empty()) {
    path = getPath(p[ind], p[ind + 1]);
    ind += 2;
  }
  for (int i = ind; i < m; i++) {
    assert(p[i].b % 2 == 1);
    path = processPaths1(path, p[i]);
  }
  for (auto &x : path) {
    vector<int> vec(m);
    for (int i = 0; i < m; i++) {
      vec[p[i].i] = x[i];
    }
    x = vec;
  }
  vector<array<int, 2> > answer = parse(path);
  cout << "Path" << '\n';
  for (auto x : answer) {
    if (x[0] == 1)
      cout << "inc";
    else
      cout << "dec";
    cout << " " << x[1] + 1 << '\n';
  }
  return 0;
}
