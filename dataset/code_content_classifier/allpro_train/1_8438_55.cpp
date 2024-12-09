#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int ADD(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int SUB(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int MUL(long long a, long long b) { return a * b % mod; }
const int maxN = 300;
const int maxM = 300;
int n, m;
int H[maxN][maxM];
int tp, tu, td, t;
int sumR1[maxN][maxM + 1], sumR2[maxN][maxM + 1];
int sumC1[maxM][maxN + 1], sumC2[maxM][maxN + 1];
int Get(int, int);
int SumRow1(int r, int c1, int c2) { return sumR1[r][c2] - sumR1[r][c1]; }
int SumCol1(int c, int r1, int r2) { return sumC1[c][r2] - sumC1[c][r1]; }
int SumRow2(int r, int c1, int c2) { return sumR2[r][c1] - sumR2[r][c2]; }
int SumCol2(int c, int r1, int r2) { return sumC2[c][r1] - sumC2[c][r2]; }
int CalcTime(pair<int, int> upLeft, int r, int c) {
  return abs(SumRow1(upLeft.first, upLeft.second, c) +
             SumCol1(c, upLeft.first, r) + SumRow2(r, upLeft.second, c) +
             SumCol2(upLeft.second, upLeft.first, r) - t);
}
int CalcTimeBrut(pair<int, int> p1, pair<int, int> p2) {
  p1.first--;
  p1.second--;
  p2.first--;
  p2.second--;
  int res = 0;
  for (int j = (p1.second), _b(p2.second); j < _b; ++j)
    res += Get(H[p1.first][j], H[p1.first][j + 1]);
  for (int i = (p1.first), _b(p2.first); i < _b; ++i)
    res += Get(H[i][p2.second], H[i + 1][p2.second]);
  for (int j = (p2.second) - 1, _b(p1.second); j >= _b; --j)
    res += Get(H[p2.first][j + 1], H[p2.first][j]);
  for (int i = (p2.first) - 1, _b(p1.first); i >= _b; --i)
    res += Get(H[i + 1][p1.second], H[i][p1.second]);
  return res;
}
int CalcC(pair<int, int> upLeft, int r, int& c) {
  int Lc = upLeft.second + 2, Rc = m - 1, res = -1;
  while (Lc + 12 <= Rc) {
    int dc = (Rc - Lc) / 3;
    int c1 = Lc + dc;
    int c2 = Rc - dc;
    int d1 = CalcTime(upLeft, r, c1);
    int d2 = CalcTime(upLeft, r, c2);
    if (d1 < d2) {
      res = d1;
      c = c1;
      Rc = c2;
    } else {
      res = d2;
      c = c2;
      Lc = c1;
    }
  }
  for (int j = (Lc), _b(Rc + 1); j < _b; ++j) {
    int dd = CalcTime(upLeft, r, j);
    if (res == -1 || dd < res) {
      res = dd;
      c = j;
    }
  }
  return res;
}
int CalcRC(pair<int, int> upLeft, pair<int, int>& downRight) {
  int Lr = upLeft.first + 2, Rr = n - 1, res = -1;
  while (Lr + 12 <= Rr) {
    int dr = (Rr - Lr) / 3;
    int r1 = Lr + dr, c1;
    int r2 = Rr - dr, c2;
    int d1 = CalcC(upLeft, r1, c1);
    int d2 = CalcC(upLeft, r2, c2);
    if (d1 < d2) {
      Rr = r2;
      res = d1;
      downRight = pair<int, int>(r1, c1);
    } else {
      Lr = r1;
      res = d2;
      downRight = pair<int, int>(r2, c2);
    }
  }
  for (int i = (Lr), _b(Rr + 1); i < _b; ++i) {
    int cc;
    int dd = CalcC(upLeft, i, cc);
    if (res == -1 || dd < res) {
      res = dd;
      downRight = pair<int, int>(i, cc);
    }
  }
  return res;
}
pair<pair<int, int>, pair<int, int> > Calc() {
  pair<int, int> upLeft, downRight;
  int dt = 1000000000;
  for (int i = (0), _b(n); i < _b; ++i) {
    for (int j = (0), _b(m); j < _b; ++j) {
      pair<int, int> _rightDown;
      int currDt = CalcRC(pair<int, int>(i, j), _rightDown);
      if (currDt == -1) continue;
      if (currDt < dt) {
        dt = currDt;
        upLeft = pair<int, int>(i + 1, j + 1);
        ;
        downRight = pair<int, int>(_rightDown.first + 1, _rightDown.second + 1);
      }
    }
  }
  return make_pair(upLeft, downRight);
}
int Get(int ot, int ku) {
  if (ot < ku) return tu;
  if (ot > ku) return td;
  return tp;
}
int main() {
  cin >> n >> m >> t;
  cin >> tp >> tu >> td;
  for (int i = (0), _b(n); i < _b; ++i) {
    for (int j = (0), _b(m); j < _b; ++j) {
      cin >> H[i][j];
    }
  }
  for (int i = (0), _b(n); i < _b; ++i) {
    sumR1[i][0] = 0;
    for (int j = (1), _b(m); j < _b; ++j) {
      sumR1[i][j] = sumR1[i][j - 1] + Get(H[i][j - 1], H[i][j]);
    }
    sumR2[i][m - 1] = 0;
    for (int j = (m - 1) - 1, _b(0); j >= _b; --j) {
      sumR2[i][j] = sumR2[i][j + 1] + Get(H[i][j + 1], H[i][j]);
    }
  }
  for (int j = (0), _b(m); j < _b; ++j) {
    sumC1[j][0] = 0;
    for (int i = (1), _b(n); i < _b; ++i) {
      sumC1[j][i] = sumC1[j][i - 1] + Get(H[i - 1][j], H[i][j]);
    }
    sumC2[j][n - 1] = 0;
    for (int i = (n - 1) - 1, _b(0); i >= _b; --i) {
      sumC2[j][i] = sumC2[j][i + 1] + Get(H[i + 1][j], H[i][j]);
    }
  }
  pair<pair<int, int>, pair<int, int> > res = Calc();
  cout << res.first.first << " " << res.first.second << " ";
  cout << res.second.first << " " << res.second.second << endl;
  return 0;
}
