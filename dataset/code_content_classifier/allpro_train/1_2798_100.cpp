#include <bits/stdc++.h>
using namespace std;
inline void pisz(int n) { printf("%d\n", n); }
template <typename T, typename TT>
ostream &operator<<(ostream &s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream &operator<<(ostream &s, vector<T> t) {
  for (int(i) = 0; (i) < (((int)((t).size()))); ++(i)) s << t[i] << " ";
  return s;
}
template <typename T, typename Aug>
struct AugTreap {
  struct Node {
    T v;
    int pr;
    Node *le, *ri;
    Aug al, ag;
  };
  Node *root;
  AugTreap() : root(0) {}
  inline static void recalc(Node *&n) {
    Aug left = n->le ? n->le->ag + n->al : n->al;
    n->ag = n->ri ? left + n->ri->ag : left;
  }
  inline void rotle(Node *&n) {
    Node *syn = n->le;
    n->le = syn->ri;
    syn->ri = n;
    n = syn;
    recalc(n->ri);
    recalc(n);
  }
  inline void rotri(Node *&n) {
    Node *syn = n->ri;
    n->ri = syn->le;
    syn->le = n;
    n = syn;
    recalc(n->le);
    recalc(n);
  }
  void insert_aux(Node *&n, const T &x, const Aug &aug) {
    if (!n) {
      n = new Node;
      n->v = x;
      n->pr = rand();
      n->le = n->ri = 0;
      n->al = n->ag = aug;
    } else if (x < n->v) {
      insert_aux(n->le, x, aug);
      if (n->pr > n->le->pr)
        rotle(n);
      else
        recalc(n);
    } else if (x > n->v) {
      insert_aux(n->ri, x, aug);
      if (n->pr > n->ri->pr)
        rotri(n);
      else
        recalc(n);
    } else {
      n->al = n->al + aug;
      recalc(n);
    }
  }
  void insert(const T &x, const Aug &aug) { insert_aux(root, x, aug); }
  Aug sumgeq_aux(const T &x, Node *n) {
    if (!n) return Aug();
    if (x > n->v) return sumgeq_aux(x, n->ri);
    if (x < n->v) {
      Aug left = sumgeq_aux(x, n->le) + n->al;
      return n->ri ? left + n->ri->ag : left;
    }
    return n->ri ? n->al + n->ri->ag : n->al;
  }
  Aug sumgeq(const T &x) { return sumgeq_aux(x, root); }
  T upper(const T &x, T min) {
    Node *n = root;
    while (n) {
      if (x < n->v) {
        if (n->v < min) min = n->v;
        n = n->le;
      } else if (x > n->v) {
        n = n->ri;
      } else
        return x;
    }
    return min;
  }
  T lower(const T &x, T max) {
    Node *n = root;
    while (n) {
      if (x > n->v) {
        if (n->v > max) max = n->v;
        n = n->ri;
      } else if (x < n->v) {
        n = n->le;
      } else
        return x;
    }
    return max;
  }
  bool remove(const T &x) { return remove_aux(root, x); }
  bool remove_aux(Node *&n, const T &x) {
    if (!n) return 0;
    if (x < n->v) {
      bool wyn = remove_aux(n->le, x);
      if (wyn) recalc(n);
      return wyn;
    }
    if (x > n->v) {
      bool wyn = remove_aux(n->ri, x);
      if (wyn) recalc(n);
      return wyn;
    }
    remove_node(n);
    return 1;
  }
  void remove_node(Node *&n) {
    if (!n->le) {
      Node *syn = n->ri;
      delete n;
      n = syn;
    } else if (!n->ri) {
      Node *syn = n->le;
      delete n;
      n = syn;
    } else if (n->le->pr < n->ri->pr) {
      rotle(n);
      remove_node(n->ri);
      recalc(n);
    } else {
      rotri(n);
      remove_node(n->le);
      recalc(n);
    }
  }
};
int startsWaiting[100007], wantedFloor[100007], waitingFloor[100007];
vector<int> waitingAtFloor[100007], wantingFloor[100007];
long long res[100007];
AugTreap<int, int> tr;
void add(int p, int x) { tr.insert(p, x); }
void wywal(int p) { tr.remove(p); }
int sum(int a, int b) { return tr.sumgeq(a) - tr.sumgeq(b + 1); }
int min_niezerowy_ponad(int p) { return tr.upper(p + 1, 1001001001); }
int max_niezerowy_ponizej(int p) { return tr.lower(p - 1, -1001001001); }
int main() {
  int(n), (m);
  scanf("%d %d", &(n), &(m));
  for (int(i) = 1; (i) <= (n); ++(i))
    scanf("%d %d %d", startsWaiting + i, waitingFloor + i, wantedFloor + i);
  vector<pair<int, int> > startWaiting;
  for (int(i) = 1; (i) <= (n); ++(i))
    startWaiting.push_back(make_pair(startsWaiting[i], i));
  sort(startWaiting.begin(), startWaiting.end());
  int startWaitingPos = 0;
  long long t = 0;
  int nextDuration = 0;
  int floor = 1;
  int direction = 0;
  while (1) {
    t += nextDuration;
    floor += direction * nextDuration;
    while (startWaitingPos < ((int)((startWaiting).size())) &&
           startWaiting[startWaitingPos].first == t) {
      int i = startWaiting[startWaitingPos++].second;
      waitingAtFloor[waitingFloor[i]].push_back(i);
      add(waitingFloor[i], 1);
    }
    for (typeof(waitingAtFloor[floor].begin()) x =
             waitingAtFloor[floor].begin();
         x != waitingAtFloor[floor].end(); x++) {
      wantingFloor[wantedFloor[*x]].push_back(*x);
      add(wantedFloor[*x], 1);
    }
    waitingAtFloor[floor].clear();
    for (typeof(wantingFloor[floor].begin()) x = wantingFloor[floor].begin();
         x != wantingFloor[floor].end(); x++) {
      res[*x] = t;
    }
    wantingFloor[floor].clear();
    wywal(floor);
    int p_up = sum(floor + 1, m), p_down = sum(1, floor - 1);
    if (p_up + p_down == 0) {
      direction = 0;
      nextDuration = 1001001001;
    } else if (p_up >= p_down) {
      direction = 1;
      nextDuration = min_niezerowy_ponad(floor) - floor;
    } else {
      direction = -1;
      nextDuration = floor - max_niezerowy_ponizej(floor);
    }
    if (startWaitingPos < ((int)((startWaiting).size()))) {
      long long maxDuration = startWaiting[startWaitingPos].first - t;
      if (maxDuration < nextDuration) nextDuration = maxDuration;
    }
    if (nextDuration == 1001001001) break;
  }
  for (int(i) = 1; (i) <= (n); ++(i)) printf("%I64d\n", res[i]);
}
