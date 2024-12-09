#include <bits/stdc++.h>
using namespace std;
int nextInt() {
  int x;
  scanf("%d", &x);
  return x;
}
struct Step {
  int speed;
  int time;
  int startTime;
  int endTime;
  int startDist;
  int endDist;
  Step() {}
  Step(int speed, int time, int startDist, int startTime)
      : speed(speed), time(time), startTime(startTime), startDist(startDist) {
    endTime = startTime + time;
    endDist = startDist + time * speed;
  }
};
set<int> getDists(vector<Step> &p) {
  set<int> s;
  s.insert(0);
  for (int i = 0; i < p.size(); ++i) {
    s.insert(p[i].endDist);
  }
  return s;
}
double getMidPoint(Step &s, double t) {
  double y = s.startTime + (t - s.startDist) * (s.endTime - s.startTime) /
                               (s.endDist - s.startDist);
  return y;
}
const double eps = 1e-9;
bool intersect(Step &s1, Step &s2, double t1, double t2) {
  double y11 = getMidPoint(s1, t1);
  double y12 = getMidPoint(s2, t1);
  double y21 = getMidPoint(s1, t2);
  double y22 = getMidPoint(s2, t2);
  return (fabs(y11 - y12) > eps && fabs(y21 - y22) > eps &&
          ((y11 < y12) ^ (y21 < y22)));
}
int countInt(vector<Step> &p1, vector<Step> &p2) {
  set<int> s1 = getDists(p1);
  set<int> s2 = getDists(p2);
  s1.insert(s2.begin(), s2.end());
  vector<int> dists(s1.begin(), s1.end());
  int i = 0, j = 0;
  vector<int> states(dists.size() - 1);
  for (int t = 1; t < dists.size(); ++t) {
    int t1 = dists[t - 1];
    int t2 = dists[t];
    while (i < p1.size() && p1[i].endDist <= t1) ++i;
    while (j < p2.size() && p2[j].endDist <= t1) ++j;
    if (intersect(p1[i], p2[j], t1, t2)) {
      states[t - 1] = 0;
    } else {
      double mid = 0.5 * (t1 + t2);
      double y1 = getMidPoint(p1[i], mid);
      double y2 = getMidPoint(p2[j], mid);
      states[t - 1] = y1 < y2 ? -1 : 1;
    }
  }
  int res = 0;
  for (int i = 1; i < states.size(); ++i) {
    res += states[i] * states[i - 1] == -1;
  }
  for (int i = 0; i < states.size(); ++i) {
    res += states[i] == 0;
  }
  return res;
}
int main() {
  int n = nextInt();
  int s = nextInt();
  vector<vector<Step> > paths(n);
  for (int i = 0; i < n; ++i) {
    int k = nextInt();
    vector<Step> path(k);
    int startTime = 0;
    int startDist = 0;
    for (int j = 0; j < k; ++j) {
      int speed = nextInt();
      int time = nextInt();
      path[j] = Step(speed, time, startDist, startTime);
      startDist += time * speed;
      startTime += time;
    }
    paths[i] = path;
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      res += countInt(paths[i], paths[j]);
    }
  }
  cout << res << endl;
  return 0;
}
