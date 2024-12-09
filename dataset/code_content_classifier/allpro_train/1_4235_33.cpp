#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <complex>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

typedef complex<double> Point;

struct Line : public vector<Point> {
  Line() {;}
  Line(Point a, Point b) { push_back(a); push_back(b); }
};

inline double cross(const Point &a, const Point &b) {
  return imag(conj(a) * b);
}

inline double dot(const Point &a, const Point &b) {
  return real(conj(a) * b);
}

inline int ccw(Point a, Point b, Point c) {
  b -= a;
  c -= a;
  if (cross(b, c) > 0) { return 1; }
  if (cross(b, c) < 0) { return -1; }
  if (dot(b, c) < 0) { return 2; }
  if (norm(b) < norm(c)) { return -2; }
  return 0;
}

inline bool intersecgtPP(const Point &p, const Point &q) {
  return abs(p - q) < EPS;
}

inline bool intersectSS(const Line &s, const Line &t) {
  return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
         ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}

inline bool intersectSP(const Line &s, const Point &p) {
  return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPS;
}

int n;
bool visit[1100];
Line line[1100];
int ans[10];

void dfs(int index, vector<int> &indexs, int &edge, int &mid) {
  if (visit[index]) { return; }
  visit[index] = true;
  indexs.push_back(index);
  REP(i, n) {
    if (i == index) { continue; }
    if (line[index][0] == line[i][0] ||
        line[index][0] == line[i][1] ||
        line[index][1] == line[i][0] ||
        line[index][1] == line[i][1]) {
      edge++;
      dfs(i, indexs, edge, mid);
      continue;
    }
    if (intersectSP(line[index], line[i][0]) ||
        intersectSP(line[index], line[i][1]) ||
        intersectSP(line[i], line[index][0]) ||
        intersectSP(line[i], line[index][1])) {
      mid++;
      dfs(i, indexs, edge, mid);
      continue;
    }      
  }
}

int main() {
  while (scanf("%d", &n), n) {
    MEMSET(visit, false);
    MEMSET(ans, 0);
    REP(i, n) {
      double x1, y1, x2, y2;
      scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
      line[i] = Line(Point(x1, y1), Point(x2, y2));
    }
    REP(i, n) {
      if (visit[i]) { continue; }
      vector<int> indexs;
      int edge = 0;
      int mid = 0;
      dfs(i, indexs, edge, mid);
      //cout << indexs.size() << " " << edge << " " << mid << endl;
      assert(edge % 2 == 0 && mid % 2 == 0);
      edge /= 2;
      mid /= 2;
      if (indexs.size() == 1) {
        ans[1]++;
      } else if (indexs.size() == 3) {
        if (mid == 1 && edge == 1) { ans[4]++; }
        else if (mid == 0 && edge == 2) { ans[7]++; }
        else { assert(false); }
      } else if (indexs.size() == 4) {
        if (mid == 0 && edge == 4) { ans[0]++; }
        else if (mid == 1 && edge == 2) { ans[3]++; }
        else if (mid == 1 && edge == 3) { ans[9]++; }
        else { assert(false); }
      } else if (indexs.size() == 5) {
        if (mid == 1 && edge == 4) { ans[6]++; }
        else if (mid == 2 && edge == 4) { ans[8]++; }
        else if (mid == 0 && edge == 4) {
          int last = indexs[4];
          REP(j, indexs.size()) {
            int index = indexs[j];
            if (intersectSS(line[last], line[index])) {
              Point s, m, e;
              if (line[last][0] == line[index][0]) {
                s = line[last][1];
                m = line[last][0];
                e = line[index][1];
              } else if (line[last][0] == line[index][1]) {
                s = line[last][1];
                m = line[last][0];
                e = line[index][0];
              } else if (line[last][1] == line[index][0]) {
                s = line[last][0];
                m = line[last][1];
                e = line[index][1];
              } else if (line[last][1] == line[index][1]) {
                s = line[last][0];
                m = line[last][1];
                e = line[index][0];
              }
              if (ccw(s, m, e) <= 0) { ans[2]++; }
              else { ans[5]++; }
              break;
            }
            if (j == 4) { assert(false); }
          }
        } else { assert(false); }
      } else {
        assert(false);
      }
    }
    REP(i, 10) {
      if (i != 0) { putchar(' '); }
      printf("%d", ans[i]);
    }
    puts("");
  }
}