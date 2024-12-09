#include<bits/stdc++.h>
using namespace std;
struct SegmentTree
{
  vector< set< pair< int, int > > > seg, add;
  int sz;
  SegmentTree(int n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz - 1, set< pair< int, int > >());
    add.assign(2 * sz - 1, set< pair< int, int > >());
  }
  bool Check(set< pair< int, int > >& seg, int x, int y)
  {
    if(!seg.empty()) {
      auto pos = seg.lower_bound({x, y});
      if(pos != seg.begin()) {
        --pos;
        if(pos -> second > x) return(true);
        ++pos;
      }
      if(pos != seg.end()) {
        if(pos -> first < y) return(true);
      }
    }
    return(false);
  }
  bool Query(const int a, const int b, const int x, const int y, int k, int l, int r)
  {
    if(a >= r || b <= l) return(false);
    if(a <= l && r <= b) return(Check(seg[k], x, y) || Check(add[k], x, y));
    return(Check(add[k], x, y) || Query(a, b, x, y, 2 * k + 1, l, (l + r) >> 1) || Query(a, b, x, y, 2 * k + 2, (l + r) >> 1, r));
  }
  bool Query(int a, int x, int b, int y)
  {
    return(Query(a, b, x, y, 0, 0, sz));
  }
  inline void Insert(set< pair< int, int > >& seg, const int x, const int y)
  {
    if(seg.empty()) {
      seg.insert({x, y});
    } else {
      bool flag = true;
      pair< int, int > range(x, y);
      while(!seg.empty() && flag) {
        auto pos = seg.lower_bound(range);
        flag = false;
        if(pos != seg.begin()) {
          --pos;
          if(pos -> second > x) {
            range = {min(pos -> first, range.first), max(pos -> second, range.second)};
            flag = true;
            pos = seg.erase(pos);
          } else {
            ++pos;
          }
        }
        if(pos != seg.end()) {
          if(pos -> first < y) {
            range = {min(pos -> first, range.first), max(pos -> second, range.second)};
            flag = true;
            seg.erase(pos);
          }
        }
      }
      seg.insert(range);
    }
  }
 
  void Add(const int a, const int b, const int x, const int y, int k, int l, int r)
  {
    if(a >= r || b <= l) return;
    if(a <= l && r <= b) {
      Insert(add[k], x, y);
      return;
    }
    Add(a, b, x, y, 2 * k + 1, l, (l + r) >> 1);
    Add(a, b, x, y, 2 * k + 2, (l + r) >> 1, r);
    Insert(seg[k], x, y);
  }
  void Add(int a, int x, int b, int y)
  {
    Add(a, b, x, y, 0, 0, sz);
  }
};
 
 
int main()
{
  int W, H, N;
  scanf("%d %d", &W, &H);
  SegmentTree tree(100000);
  scanf("%d", &N);
  long long sum = 0;
  while(N--) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    --x1, --y1;
    if(!tree.Query(x1, y1, x2, y2)) {
      sum += 1LL * (x2 - x1) * (y2 - y1);
      tree.Add(x1, y1, x2, y2);
    }
    printf("%lld\n", sum);
  }
}