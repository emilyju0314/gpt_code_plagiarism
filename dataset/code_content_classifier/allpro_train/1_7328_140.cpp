#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2510;
const int MAXM = 2510;
int n, m, q;
map<tuple<int, int, int, int>, pair<unsigned long long, unsigned long long> >
    mp;
pair<unsigned long long, unsigned long long> bit[MAXN][MAXM];
inline int lowbit(int x) { return x & (-x); }
inline void update(int r, int c,
                   pair<unsigned long long, unsigned long long> num) {
  for (int i = r; i <= n; i += lowbit(i))
    for (int j = c; j <= m; j += lowbit(j)) {
      bit[i][j].first += num.first;
      bit[i][j].second += num.second;
    }
}
inline pair<unsigned long long, unsigned long long> query(int r, int c) {
  pair<unsigned long long, unsigned long long> ret(0ULL, 0ULL);
  for (int i = r; i; i -= lowbit(i))
    for (int j = c; j; j -= lowbit(j)) {
      ret.first += bit[i][j].first;
      ret.second += bit[i][j].second;
    }
  return ret;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  srand(2333);
  for (int i = 0; i < q; ++i) {
    int t, r1, c1, r2, c2;
    pair<unsigned long long, unsigned long long> num, mnum;
    scanf("%d%d%d%d%d", &t, &r1, &c1, &r2, &c2);
    switch (t) {
      case 1:
        num.first = rand();
        num.second = rand();
        mnum.first = -num.first;
        mnum.second = -num.second;
        mp[make_tuple(r1, c1, r2, c2)] = num;
        update(r2, c2, num);
        update(r1 - 1, c1 - 1, num);
        update(r1 - 1, c2, mnum);
        update(r2, c1 - 1, mnum);
        break;
      case 2:
        num = mp[make_tuple(r1, c1, r2, c2)];
        mnum.first = -num.first;
        mnum.second = -num.second;
        update(r2, c2, mnum);
        update(r1 - 1, c1 - 1, mnum);
        update(r1 - 1, c2, num);
        update(r2, c1 - 1, num);
        break;
      case 3:
        if (query(r1 - 1, c1 - 1) == query(r2 - 1, c2 - 1))
          printf("Yes\n");
        else
          printf("No\n");
        break;
    }
  }
  return 0;
}
