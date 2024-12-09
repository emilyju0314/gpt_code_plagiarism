#include <bits/stdc++.h>
using namespace std;
const int arraysize = 5000005;
typedef struct SetItem {
  int x, y;
  double contribution;
  bool operator<(const SetItem b) const {
    return contribution < b.contribution;
  }
  bool operator>(const SetItem b) const {
    return contribution > b.contribution;
  }
};
typedef struct maxheap *Heap;
typedef struct maxheap {
  int last, maxsize;
  SetItem *heap;
} Maxheap;
Heap MaxHeapInit(int HeapSize) {
  Heap H = (Heap)malloc(sizeof *H);
  H->maxsize = HeapSize;
  H->heap = (SetItem *)malloc((H->maxsize + 1) * sizeof(SetItem));
  H->last = 0;
  return H;
}
void MaxHeapPush(SetItem x, Heap H) {
  int i;
  i = ++H->last;
  while (i != 1 && x > H->heap[i / 2]) {
    H->heap[i] = H->heap[i / 2];
    i /= 2;
  }
  H->heap[i] = x;
}
void MaxHeapPop(Heap H) {
  int i, ci;
  SetItem x, y;
  x = H->heap[1];
  y = H->heap[H->last--];
  i = 1;
  ci = 2;
  while (ci <= H->last) {
    if (ci < H->last && H->heap[ci + 1] > H->heap[ci]) ci++;
    if (H->heap[ci] < y) break;
    H->heap[i] = H->heap[ci];
    i = ci;
    ci *= 2;
  }
  H->heap[i] = y;
}
SetItem Top(Heap H) { return H->heap[1]; }
bool Empty(Heap H) { return H->last == 0; }
int Size(Heap H) { return H->last; }
int n, m, r, k;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
map<pair<int, int>, int> mp;
void ReadData() { scanf("%d%d%d%d", &n, &m, &r, &k); }
double GetContribution(int x, int y) {
  int dx = min(x, n - r + 1) - max(1, x - r + 1) + 1;
  int dy = min(y, m - r + 1) - max(1, y - r + 1) + 1;
  return (double)dx * dy / (n - r + 1) / (m - r + 1);
}
void BFS(Heap H, double &ans) {
  int cnt = 0;
  while (cnt < k) {
    SetItem heap = Top(H);
    MaxHeapPop(H);
    ans += heap.contribution;
    cnt++;
    for (int i = 0; i < 4; i++) {
      int newx = heap.x + dir[i][0];
      int newy = heap.y + dir[i][1];
      if (newx < 0 || newx > n || newy < 0 || newy > m) continue;
      if (mp.count(make_pair(newx, newy)) != 0) continue;
      mp[make_pair(newx, newy)] = 1;
      SetItem tmp;
      tmp.x = newx, tmp.y = newy;
      tmp.contribution = GetContribution(newx, newy);
      MaxHeapPush(tmp, H);
    }
  }
}
void Work() {
  Heap H = MaxHeapInit(arraysize);
  int x = (n + 1) / 2, y = (m + 1) / 2;
  mp[make_pair(x, y)] = 1;
  SetItem tmp;
  tmp.x = x, tmp.y = y, tmp.contribution = GetContribution(x, y);
  MaxHeapPush(tmp, H);
  double ans = 0;
  BFS(H, ans);
  printf("%.12lf\n", ans);
}
int main() {
  ReadData();
  Work();
  return 0;
}
