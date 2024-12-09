//
// Problem: Kimagagure Cleaner
// Solution by: MORI Shingo
// O(n*2^(n3/8))
//
// implement1 & debug1 214min
// implement2 86min
// debug2 122min
// 
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);
const int INF = 2e+9 + 3;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))


struct Node {
  int v;
  int sum;
  Node() : v(0), sum(0) {;}
  Node(int v) : v(v), sum(0) {;}
};
inline Node Merge(Node left, Node right) {
  return Node(max(left.v + left.sum, right.v + right.sum));
}

struct SegmentTree {
  static const int MAX_DEPTH = 17;
  static const int SIZE = 1 << (MAX_DEPTH + 1);

  bool updated[SIZE];
  Node data[SIZE];
  SegmentTree() {
    memset(updated, false, sizeof(updated));
    MEMSET(data, 0);
  }
  void change(int left, int right, int v) {
    assert(left <= right);
    return in_set(v, 0, 1, left, right);
  }
  int get(int left, int right) {
    assert(left <= right);
    Node node = in_get(0, 1, left, right);
    return node.v + node.sum;
  }

private:
  void Divide(int node) {
    if (!updated[node] || node >= (1 << MAX_DEPTH)) { return; }
    updated[node] = false;
    updated[node * 2] = true;
    updated[node * 2 + 1] = true;
    data[node * 2].sum += data[node].sum;
    data[node * 2 + 1].sum += data[node].sum;
    data[node].v += data[node].sum;
    data[node].sum = 0;
  }

  void in_set(int v, int depth, int node, int left, int right) {
    int width = 1 << (MAX_DEPTH - depth);
    int index = node - (1 << depth);
    int node_left = index * width;
    int node_mid = node_left + (width >> 1);
    Divide(node);
    if (right - left + 1 == width && left == node_left) {
      updated[node] = true;
      data[node].sum += v;
    } else {
      if (right < node_mid) {
        in_set(v, depth + 1, node * 2, left, right);
      } else if (left >= node_mid) {
        in_set(v, depth + 1, node * 2 + 1, left, right);
      } else {
        in_set(v, depth + 1, node * 2, left, node_mid - 1);
        in_set(v, depth + 1, node * 2 + 1, node_mid, right);
      }
      data[node] = Merge(data[node * 2], data[node * 2 + 1]);
    }
  }

  Node in_get(int depth, int node, int left, int right) {
    int width = 1 << (MAX_DEPTH - depth);
    int index = node - (1 << depth);
    int node_left = index * width;
    int node_mid = node_left + (width >> 1);
    Divide(node);
    if (right - left + 1 == width && left == node_left) {
      return data[node];
    } else if (right < node_mid) {
      return in_get(depth + 1, node * 2, left, right);
    } else if (left >= node_mid) {
      return in_get(depth + 1, node * 2 + 1, left, right);
    }
    return Merge(in_get(depth + 1, node * 2, left, node_mid - 1), in_get(depth + 1, node * 2 + 1, node_mid, right));
  }
};

struct Rect {
  ll dirs;
  int initial_dir;
  int dir;
  ll x1, y1, x2, y2;
  Rect() : dirs(0), initial_dir(0) {;}
  Rect(int dir, ll x1, ll y1, ll x2, ll y2) : dirs(0), initial_dir(dir), dir(dir), x1(x1), y1(y1), x2(x2), y2(y2) {;}
  void Move(int d, ll lower, ll upper, int index) {
    assert(dir != -1);
    assert(d == 1 || d == -1);
    if (d == 1) {
      dirs |= 1LL << index;
    }
    dir = (dir + d + 4) % 4;
    if (dir == 0) { Expand(lower, 0, upper, 0); }
    if (dir == 1) { Expand(0, lower, 0, upper); }
    if (dir == 2) { Expand(-upper, 0, -lower, 0); }
    if (dir == 3) { Expand(0, -upper, 0, -lower); }
  }
  void Move2(int pm, ll lower, ll upper, int index) {
    assert(dir != -1);
    assert(pm == 0 || pm == 1);
    if (pm == 1) {
      dirs |= 1LL << index;
    }
    int ds[2] = { -1, 1 };
    REP(i, 2) {
      int ndir = (dir + ds[i] + 4) % 4;
      // cout << pm << " " << dir << " " << ndir << endl;
      if ((pm == 0 && ndir >= 2) ||
          (pm == 1 && ndir <= 1)) { dir = ndir; break; } // set flag direction
    }
    if (dir == 0) { Expand(lower, 0, upper, 0); }
    if (dir == 1) { Expand(0, lower, 0, upper); }
    if (dir == 2) { Expand(-upper, 0, -lower, 0); }
    if (dir == 3) { Expand(0, -upper, 0, -lower); }
  }
  void Expand(ll lx, ll ly, ll ux, ll uy) {
    x1 += lx; y1 += ly; x2 += ux; y2 += uy;
  }
};
bool Hit(Rect r1, Rect r2) {
  return r1.x1 <= r2.x2 && r2.x1 <= r1.x2 && r1.y1 <= r2.y2 && r2.y1 <= r1.y2;
}
ostream &operator<<(ostream &os, const Rect &rhs) {
  os << "(" << rhs.x1 << ", " << rhs.y1 << ", " << rhs.x2 << ", " << rhs.y2 << ")";
  return os;
}

struct Event {
  int index;
  int inout;
  ll x;
  int y1, y2;
  Event(int index, int inout, ll x, int y1, int y2) : index(index), inout(inout), x(x), y1(y1), y2(y2) {;}
  bool operator<(const Event &rhs) const {
    if (x != rhs.x) { return x < rhs.x; }
    return inout < rhs.inout;
  }
};

void Mirror(vector<Rect> &rect, int init_dir, ll X, ll Y) {
  REP(i, rect.size()) {
    Rect &r = rect[i];
    Rect rev = r;
    rev.x1 = X - r.x2;
    rev.y1 = Y - r.y2;
    rev.x2 = X - r.x1;
    rev.y2 = Y - r.y1;
    rev.dir = rev.initial_dir;;
    rect[i] = rev;
  }
}



int n;
ll X, Y;
int dirs[100];
ll lower[100];
ll upper[100];
ll ans_dirs[100];
ll ans_l[100];

vector<Rect> simulate(const vector<Rect> &rects, int dir, ll l, ll u, int index) {
  int cnt = 0;
  vector<Rect> ret;
  vector<int> ds;
  if (dir != 0) {
    ds.push_back(dir);
    ret.resize(rects.size());
  } else {
    ds.push_back(1);
    ds.push_back(-1);
    ret.resize(rects.size() * 2);
  }
  FORIT(it1, ds) {
    int d = *it1;
    FORIT(it2, rects) {
      Rect r = *it2;
      r.Move(d, l, u, index);
      ret[cnt++] = r;
    }
  }
  return ret;
}

SegmentTree stree;
ll IntersectRect(vector<Rect> &rs1, vector<Rect> &rs2, bool swapxy) {
  if (rs1.size() == 0 || rs2.size() == 0) { return -1; }
  vector<Rect> *rss[2] = { &rs1, &rs2 };
  {
    map<ll, int> ys;
    REP(iter, 2) {
      // cout << iter << endl;
      FORIT(it, *rss[iter]) {
        if (swapxy) {
          swap(it->x1, it->y1);
          swap(it->x2, it->y2);
        }
        // cout << *it << endl;
        ys[it->y1] = 0;
        ys[it->y2] = 0;
      }
    }
    int index = 0;
    FORIT(it, ys) {
      it->second = index++;
    }
    // cout << index << endl;
    REP(iter, 2) {
      FORIT(it, *rss[iter]) {
        it->y1 = ys[it->y1];
        it->y2 = ys[it->y2];
      }
    }
  }
  // cout << rs1.size() << " " << rs2.size() << endl;
  REP(iter, 2) {
    stree = SegmentTree();
    vector<Event> events;
    FORIT(it, *rss[0]) {
      events.push_back(Event(-1, 1, it->x1, it->y1, it->y2));
      events.push_back(Event(-1, -1, it->x2 + 1, it->y1, it->y2));
    }
    int cnt = 0;
    FORIT(it, *rss[1]) {
      events.push_back(Event(cnt, 2, it->x1, it->y1, it->y2));
      events.push_back(Event(cnt, 2, it->x2, it->y1, it->y2));
      cnt++;
    }
    sort(events.begin(), events.end());
    // cout << "Start" << endl;
    FORIT(it, events) {
      Event e = *it;
      // cout << e.x << " " << e.y1 << " " << e.y2 << " " << e.inout << endl;
      if (e.index == -1) { 
        stree.change(e.y1, e.y2, e.inout);
      } else {
        // cout << stree.get(e.y1, e.y2) << endl;
        if (stree.get(e.y1, e.y2) > 0) {
          Rect rect2 = (*rss[1])[e.index];
          REP(i, rss[0]->size()) {
            if (Hit((*rss[0])[i], rect2)) {
              // cout << (*rss[0])[i].dirs << endl;
              // cout << rect2.dirs << endl;
              return (*rss[0])[i].dirs | rect2.dirs;
            }
          }
          assert(false);
        }
      }
    }
    swap(rss[0], rss[1]);
  }
  return -1;
}
ll IntersectRect2(vector<Rect> &rs1, vector<Rect> &rs2, bool swapxy) {
  if (rs1.size() == 0 || rs2.size() == 0) { return -1; }
  vector<Rect> *rss[2] = { &rs1, &rs2 };
  {
    REP(iter, 2) {
      // cout << iter << endl;
      FORIT(it, *rss[iter]) {
        if (swapxy) {
          swap(it->x1, it->y1);
          swap(it->x2, it->y2);
        }
      }
    }
  }
  // cout << rs1.size() << " " << rs2.size() << endl;
  REP(iter, 2) {
    vector<Event> events;
    FORIT(it, *rss[0]) {
      events.push_back(Event(-1, 1, it->x1, it->y1, it->y2));
      events.push_back(Event(-1, -1, it->x2 + 1, it->y1, it->y2));
    }
    int cnt = 0;
    FORIT(it, *rss[1]) {
      events.push_back(Event(cnt, 2, it->x1, it->y1, it->y2));
      events.push_back(Event(cnt, 2, it->x2, it->y1, it->y2));
      cnt++;
    }
    sort(events.begin(), events.end());
    int hit = 0;
    // cout << "Start" << endl;
    FORIT(it, events) {
      Event e = *it;
      // cout << e.x << " " << e.y1 << " " << e.y2 << " " << e.inout << endl;
      if (e.index == -1) { 
        hit += e.inout;
        assert(hit >= 0);
      } else {
        // cout << stree.get(e.y1, e.y2) << endl;
        if (hit > 0) {
          Rect rect2 = (*rss[1])[e.index];
          REP(i, rss[0]->size()) {
            if (Hit((*rss[0])[i], rect2)) {
              // cout << (*rss[0])[i].dirs << endl;
              // cout << rect2.dirs << endl;
              return (*rss[0])[i].dirs | rect2.dirs;
            }
          }
          assert(false);
        }
      }
    }
    swap(rss[0], rss[1]);
  }
  return -1;
}

int GetSolvingDir(int depth, int xy, ll flags) {
  if (dirs[depth] != 0) { return -999; }
  if (dirs[depth] == 0 && dirs[depth + 1] == 0) {
    if (xy == depth % 2) { return -1; } // both
    return 0; // tekitou
  }
  return (flags >> depth) & 1;
}
vector<Rect> simulate2(const vector<Rect> &rects, int pm, ll l, ll u, int index) {
  int cnt = 0;
  vector<Rect> ret;
  vector<int> pms;
  if (pm >= 0) {
    pms.push_back(pm);
    ret.resize(rects.size());
  } else {
    pms.push_back(0);
    pms.push_back(1);
    ret.resize(rects.size() * 2);
  }
  FORIT(it1, pms) {
    int v = *it1;
    FORIT(it2, rects) {
      Rect r = *it2;
      r.Move2(v, l, u, index);
      ret[cnt++] = r;
    }
  }
  return ret;
}
ll Solve(ll flags) {
  ll ans_flags[2] = { -1, -1 };
  REP(xy, 2) {
    int center = n;
    // both side search
    vector<Rect> rect1;
    rect1.push_back(Rect(0, 0, 0, 0, 0));
    REP(i, n) {
      int pm = GetSolvingDir(i, xy, flags);
      ll l = lower[i];
      ll u = upper[i];
      if (xy != i % 2) { l = 0; u = 0; }
      if (dirs[i] != 0) {
        rect1 = simulate(rect1, dirs[i], l, u, i);
      } else {
        // cout << "PM: " << pm << endl;
        rect1 = simulate2(rect1, pm, l, u, i);
      }
      if (rect1.size() > (1LL << 7)) {
        center = i + 1;
        break;
      }
    }
    vector<Rect> rect2;
    int left_upper = center % 2;
    rect2.push_back(Rect(left_upper, 0, 0, 0, 0));
    rect2.push_back(Rect(left_upper + 2, 0, 0, 0, 0));
    FOR(i, center, n) {
      int pm = GetSolvingDir(i, xy, flags);
      ll l = lower[i];
      ll u = upper[i];
      if (xy != i % 2) { l = 0; u = 0; }
      if (dirs[i] != 0) {
        rect2 = simulate(rect2, dirs[i], l, u, i);
      } else {
        rect2 = simulate2(rect2, pm, l, u, i);
      }
    }
    ll lx = xy == 0 ? 0 : X;
    ll ly = xy == 0 ? Y : 0;
    Mirror(rect2, left_upper, lx, ly);
    // cout << rect1.size() << " " << rect2.size() << endl;

    vector<Rect> rs1[4];
    vector<Rect> rs2[4];
    if (center != n && dirs[center] == 0 && dirs[center + 1] != 0) {
      // ignore connecting direction
      FORIT(it, rect1) {
        rs1[0].push_back(*it);
      }
      FORIT(it, rect2) {
        rs2[0].push_back(*it);
      }
    } else {
      FORIT(it, rect1) {
        rs1[it->dir].push_back(*it);
      }
      FORIT(it, rect2) {
        rs2[it->dir].push_back(*it);
      }
    }
    // cout << "test A" << endl;
    // FORIT(it, rect1) {
    //   cout << *it << " " << it->dir << endl;
    // }
    // cout << "test B" << endl;
    // FORIT(it, rect2) {
    //   cout << *it << " " << it->dir << endl;
    // }
    ll ans_dir_flags = -1;
    // cout << rect1.size() << " "<< rect2.size() << endl;
    // cout << xy << endl;
    REP(dir, 4) {
      // ans_dir_flags = IntersectRect(rs1[dir], rs2[dir], xy ^ 1);
      ans_dir_flags = IntersectRect2(rs1[dir], rs2[dir], xy ^ 1);
      if (ans_dir_flags != -1) { break; }
    }
    if (ans_dir_flags == -1) { return -1; }
    ans_flags[xy] = ans_dir_flags;
  }
  int dir = 0;
  REP(depth, n) {
    if (dirs[depth] != 0) {
      ans_dirs[depth] = dirs[depth];
    } else {
      int xy = depth % 2;
      ll v = (ans_flags[xy] >> depth) & 1;
      int ds[2] = { -1, 1 };
      REP(i, 2) {
        int ndir = (dir + ds[i] + 4) % 4;
        if ((v == 0 && ndir >= 2) ||
            (v == 1 && ndir <= 1)) {
          // set flag direction
          ans_dirs[depth] = ds[i];
        }
      }
    }
    dir = (dir + ans_dirs[depth] + 4) % 4;
  }
  // REP(i, n) {
  //   cout << (ans_dirs[i] == 1 ? "L" : "R");
  // }
  // cout << endl;
  return 1;
}

ll Dfs(int depth, ll flags) {
  if (depth == n) {
    return Solve(flags);
  }
  if (dirs[depth] == 0 && dirs[depth + 1] != 0) {
    assert(dirs[depth] == 0);
    REP(iter, 2) {
      ll nflags = flags | ((ll)iter << depth);
      if (Dfs(depth + 1, nflags) != -1) { return 1; }
    }
    return -1;
  }
  return Dfs(depth + 1, flags);
}

void RestoreDistance() {
  Rect r(0, 0, 0, 0, 0);
  {
    vector<Rect> rects(1, r);
    REP(i, n) {
      rects = simulate(rects, ans_dirs[i], lower[i], upper[i], i);
    }
    Rect rect = rects[0];
    // cout << rect << endl;
    // cout << X << " " << Y << endl;
    assert(Hit(Rect(0, X, Y, X, Y), rect));
  }
  REP(i, n) {
    int ndir = (r.dir + ans_dirs[i] + 4) % 4;
    ll l = lower[i];
    ll u = upper[i];
    while (l != u) {
      ll m = (l + u) / 2;
      assert(l < u);
      vector<Rect> rects(1, r);
      rects = simulate(rects, ans_dirs[i], m, m, i);
      FOR(j, i + 1, n) {
        rects = simulate(rects, ans_dirs[j], lower[j], upper[j], j);
      }
      Rect rect = rects[0];
      // cout << ndir << " " << rect << " "<< Y << endl;
      if ((ndir == 0 && rect.x2 < X) ||
          (ndir == 1 && rect.y2 < Y) ||
          (ndir == 2 && X < rect.x1) ||
          (ndir == 3 && Y < rect.y1)) {
        l = m + 1;
      } else {
        // cout << i << "  "<< "test" << endl;
        u = m;
      }
    }
    ans_l[i] = l;
    r.Move(ans_dirs[i], l, l, i);
  }
}

bool Check() {
  vector<Rect> rect(1, Rect(0, 0, 0, 0, 0));
  REP(i, n) {
    if (ans_l[i] < lower[i] || upper[i] < ans_l[i]) { return false; }
    if (dirs[i] != 0 && dirs[i] != ans_dirs[i]) { return false; }
    rect = simulate(rect, ans_dirs[i], ans_l[i], ans_l[i], i);
  }
  // cout << rect[0] << endl;
  // cout << X << " " << Y << endl;
  if (rect[0].x1 != X || rect[0].y1 != Y) { return false; }
  return true;
}

int main() {
  while (scanf("%d %lld %lld", &n, &X, &Y) > 0) {
    int center = n;
    int div = 0;
    REP(i, n) {
      char c;
      int v = scanf(" %c %lld %lld", &c, &lower[i], &upper[i]);
      assert(v == 3);
      if (c == 'L') { dirs[i] = 1; }
      if (c == '?') { dirs[i] = 0; }
      if (c == 'R') { dirs[i] = -1; }
      if (dirs[i] == 0) {
        div++;
        if (div == 21) { center = i; }
      }
    }
    dirs[n] = 0;
    int segment = 0;
    REP(i, n) { if (dirs[i] == 0 && dirs[i + 1] != 0) { segment++; } }
    ll ans_dir = -1;
    // cout << segment << " " << n << " " << n / 4 << endl;
    if (segment > n / 4 + 1) {
      // both side search
      // cout << "Normal" << endl;
      vector<Rect> rect1;
      rect1.push_back(Rect(0, 0, 0, 0, 0));
      REP(i, center) {
        rect1 = simulate(rect1, dirs[i], lower[i], upper[i], i);
      }
      vector<Rect> rect2;
      int left_upper = center % 2;
      rect2.push_back(Rect(left_upper, 0, 0, 0, 0));
      rect2.push_back(Rect(left_upper + 2, 0, 0, 0, 0));
      FOR(i, center, n) {
        rect2 = simulate(rect2, dirs[i], lower[i], upper[i], i);
      }
      // cout << rect1.size() << " " << rect2.size() << endl;
      Mirror(rect2, left_upper, X, Y);

      vector<Rect> rs1[4];
      FORIT(it, rect1) {
        rs1[it->dir].push_back(*it);
      }
      vector<Rect> rs2[4];
      FORIT(it, rect2) {
        rs2[it->dir].push_back(*it);
      }
      // cout << "test" << endl;
      // FORIT(it, rect1) {
      //   cout << *it << " " << it->dir << endl;
      // }
      // cout << "test" << endl;
      // FORIT(it, rect2) {
      //   cout << *it << " " << it->dir << endl;
      // }
      REP(dir, 4) {
        ans_dir = IntersectRect(rs1[dir], rs2[dir], false);
        if (ans_dir != -1) { break; }
      }
      REP(i, n) {
        ans_dirs[i] = ((ans_dir >> i) & 1) ? 1 : -1;
        // cout << (ans_dirs[i] == 1 ? "L" : "R");
      }
      // cout << endl;
    } else {
      // divide
      // cout << "Divide" << endl;
      ans_dir = Dfs(0, 0);
    }
    if (ans_dir == -1) {
      puts("-1");
      goto next;
    }

    // restore
    RestoreDistance();

    // print ans
    printf("%d\n", n);
    REP(i, n) {
      printf("%c %lld\n", ans_dirs[i] == 1 ? 'L' : 'R', ans_l[i]);
    }
    assert(Check());
next:;
  }
}

