#include <bits/stdc++.h>
using namespace std;
void Ask(int x1, int y1, int x2, int y2, bool rot = false) {
  if (!rot) {
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
  } else {
    cout << "? " << y1 << ' ' << x1 << ' ' << y2 << ' ' << x2 << endl;
  }
}
int Find(int n, bool rot) {
  int l = 1, r = n;
  while (l < r) {
    int m = (l + r) >> 1;
    Ask(1, 1, m, n, rot);
    int res;
    cin >> res;
    if (res == 0) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  Ask(1, 1, l, n, rot);
  int res;
  cin >> res;
  if (res != 1) {
    return -1;
  }
  int v = l;
  ++l;
  r = n;
  while (l < r) {
    int m = (l + r) >> 1;
    Ask(l, 1, m, n, rot);
    int res;
    cin >> res;
    if (res == 0) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  Ask(v + 1, 1, l, n, rot);
  cin >> res;
  if (res != 1) {
    return -1;
  }
  return v;
}
int FindR(int x1, int y1, int x2, int y2, bool rot) {
  int l = x1, r = x2;
  while (l < r) {
    int m = (l + r) >> 1;
    Ask(x1, y1, m, y2, rot);
    int res;
    cin >> res;
    if (res == 0) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return l;
}
int FindL(int x1, int y1, int x2, int y2, bool rot) {
  int l = x1, r = x2;
  while (l < r) {
    int m = (l + r + 1) >> 1;
    Ask(m, y1, x2, y2, rot);
    int res;
    cin >> res;
    if (res == 0) {
      r = m - 1;
    } else {
      l = m;
    }
  }
  return l;
}
int FindD(int x1, int y1, int x2, int y2, bool rot) {
  int l = y1, r = y2;
  while (l < r) {
    int m = (l + r) >> 1;
    Ask(x1, y1, x2, m, rot);
    int res;
    cin >> res;
    if (res == 0) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return l;
}
int FindU(int x1, int y1, int x2, int y2, bool rot) {
  int l = y1, r = y2;
  while (l < r) {
    int m = (l + r + 1) >> 1;
    Ask(x1, m, x2, y2, rot);
    int res;
    cin >> res;
    if (res == 0) {
      r = m - 1;
    } else {
      l = m;
    }
  }
  return l;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  bool rot = false;
  int line = Find(n, rot);
  if (line == -1) {
    rot = true;
    line = Find(n, rot);
  }
  int x11 = FindL(1, 1, line, n, rot);
  int x12 = FindR(1, 1, line, n, rot);
  int y11 = FindU(1, 1, line, n, rot);
  int y12 = FindD(1, 1, line, n, rot);
  int x21 = FindL(line + 1, 1, n, n, rot);
  int x22 = FindR(line + 1, 1, n, n, rot);
  int y21 = FindU(line + 1, 1, n, n, rot);
  int y22 = FindD(line + 1, 1, n, n, rot);
  if (rot) {
    swap(x11, y11);
    swap(x12, y12);
    swap(x21, y21);
    swap(x22, y22);
  }
  cout << "! " << x11 << ' ' << y11 << ' ' << x12 << ' ' << y12;
  cout << ' ' << x21 << ' ' << y21 << ' ' << x22 << ' ' << y22 << endl;
  return 0;
}
