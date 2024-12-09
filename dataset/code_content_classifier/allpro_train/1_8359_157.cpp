#include <bits/stdc++.h>
using namespace std;
template <class telem>
telem MAX(telem a, telem b) {
  return (a > b) ? a : b;
}
template <class telem>
telem MIN(telem a, telem b) {
  return (a < b) ? a : b;
}
template <class telem>
telem GCD(telem a, telem b) {
  return b ? GCD(b, a % b) : a;
}
template <class telem>
telem LCM(telem a, telem b) {
  return a / GCD(a, b) * b;
}
template <class telem>
telem UNSIGNED(telem a) {
  return (a > 0) ? a : a * (-1);
}
template <class telem>
void bez_swop(telem &a, telem &b) {
  telem c = a;
  a = b;
  b = c;
}
void swop(int &a, int &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
vector<pair<int, int> > mas[10];
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    q;
int n, m, ras[10];
void dacstra(int u) {
  pair<int, int> a;
  int i, v, r;
  for (i = 1; i <= n; i++) {
    ras[i] = 2 * 1000000005;
  }
  ras[u] = 0;
  q.push(make_pair(ras[u], u));
  while (!q.empty()) {
    a = q.top();
    q.pop();
    if (a.first > ras[a.second]) continue;
    for (i = 0; i < mas[a.second].size(); i++) {
      v = mas[a.second][i].first;
      r = mas[a.second][i].second;
      if (ras[v] > ras[a.second] + r) {
        ras[v] = ras[a.second] + r;
        q.push(make_pair(ras[v], v));
      }
    }
  }
}
int main() {
  int a, b, x1, x2, y1, y2;
  scanf("%d %d %d %d %d", &n, &x1, &y1, &x2, &y2);
  mas[1].push_back(make_pair(2, n));
  mas[1].push_back(make_pair(4, n));
  mas[2].push_back(make_pair(3, n));
  mas[2].push_back(make_pair(1, n));
  mas[3].push_back(make_pair(2, n));
  mas[3].push_back(make_pair(4, n));
  mas[4].push_back(make_pair(1, n));
  mas[4].push_back(make_pair(4, n));
  a = 0;
  if (x1 == 0 && y1 == 0) {
    a = 1;
  }
  if (x1 == n && y1 == 0) {
    a = 2;
  }
  if (x1 == 0 && y1 == n) {
    a = 4;
  }
  if (x1 == n && y1 == n) {
    a = 3;
  }
  if (!a) {
    a = 5;
    if (x1 == 0) {
      mas[1].push_back(make_pair(5, y1));
      mas[4].push_back(make_pair(5, n - y1));
      mas[5].push_back(make_pair(1, y1));
      mas[5].push_back(make_pair(4, n - y1));
    }
    if (y1 == 0) {
      mas[1].push_back(make_pair(5, x1));
      mas[2].push_back(make_pair(5, n - x1));
      mas[5].push_back(make_pair(1, x1));
      mas[5].push_back(make_pair(2, n - x1));
    }
    if (y1 == n) {
      mas[4].push_back(make_pair(5, x1));
      mas[3].push_back(make_pair(5, n - x1));
      mas[5].push_back(make_pair(4, x1));
      mas[5].push_back(make_pair(3, n - x1));
    }
    if (x1 == n) {
      mas[2].push_back(make_pair(5, y1));
      mas[3].push_back(make_pair(5, n - y1));
      mas[5].push_back(make_pair(2, y1));
      mas[5].push_back(make_pair(3, n - y1));
    }
  }
  b = 0;
  if (x2 == 0 && y2 == 0) {
    b = 1;
  }
  if (x2 == n && y2 == 0) {
    b = 2;
  }
  if (x2 == 0 && y2 == n) {
    b = 4;
  }
  if (x2 == n && y2 == n) {
    b = 3;
  }
  if (!b) {
    b = 6;
    if (x2 == 0) {
      mas[1].push_back(make_pair(6, y2));
      mas[4].push_back(make_pair(6, n - y2));
      mas[6].push_back(make_pair(1, y2));
      mas[6].push_back(make_pair(4, n - y2));
    }
    if (y2 == 0) {
      mas[1].push_back(make_pair(6, x2));
      mas[2].push_back(make_pair(6, n - x2));
      mas[6].push_back(make_pair(1, x2));
      mas[6].push_back(make_pair(2, n - x2));
    }
    if (y2 == n) {
      mas[4].push_back(make_pair(6, x2));
      mas[3].push_back(make_pair(6, n - x2));
      mas[6].push_back(make_pair(4, x2));
      mas[6].push_back(make_pair(3, n - x2));
    }
    if (x2 == n) {
      mas[2].push_back(make_pair(6, y2));
      mas[3].push_back(make_pair(6, n - y2));
      mas[6].push_back(make_pair(2, y2));
      mas[6].push_back(make_pair(3, n - y2));
    }
  }
  if (x1 == x2 && a != 1 && a != 2 && a != 3 && a != 4 && b != 1 && b != 2 &&
      b != 3 && b != 4 && (x1 == n || x1 == 0)) {
    mas[a].push_back(make_pair(b, UNSIGNED(y1 - y2)));
    mas[b].push_back(make_pair(a, UNSIGNED(y1 - y2)));
  }
  if (y1 == y2 && a != 1 && a != 2 && a != 3 && a != 4 && b != 1 && b != 2 &&
      b != 3 && b != 4 && (y1 == n || y1 == 0)) {
    mas[a].push_back(make_pair(b, UNSIGNED(x1 - x2)));
    mas[b].push_back(make_pair(a, UNSIGNED(x1 - x2)));
  }
  n = 6;
  dacstra(a);
  printf("%d", ras[b]);
  return 0;
}
