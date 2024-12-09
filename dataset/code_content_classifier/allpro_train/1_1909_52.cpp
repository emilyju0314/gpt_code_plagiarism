#include <bits/stdc++.h>
using namespace std;
bitset<2000> a[2000];
int parent[2000];
char s[2000 + 1];
int Find(int i) { return (parent[i] == i) ? i : parent[i] = Find(parent[i]); }
bool Union(int i, int j) {
  i = Find(i), j = Find(j);
  if (i == j) {
    return 0;
  }
  if (i > j) {
    swap(i, j);
  }
  parent[j] = i;
  return 1;
}
void Reset() {
  for (int i = 0; i < 2000; ++i) {
    parent[i] = i;
    a[i].reset();
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    vector<tuple<int, int, int> > edges;
    scanf("%d%d", &n, &m);
    Reset();
    int targetMSTWeight = -m;
    for (int x = 0; x < m; ++x) {
      scanf("%s", s);
      for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
          a[i].set(x);
          ++targetMSTWeight;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int w = (a[i] & a[j]).count();
        edges.push_back(make_tuple(w, i, j));
      }
    }
    sort(edges.begin(), edges.end(), greater<tuple<int, int, int> >());
    vector<pair<int, int> > ans;
    int mstWeight = 0;
    for (auto edge : edges) {
      int k, i, j;
      tie(k, i, j) = edge;
      if (Union(i, j)) {
        mstWeight += k;
        ans.push_back(make_pair(i, j));
      }
    }
    if (mstWeight != targetMSTWeight) {
      printf("NO\n");
    } else {
      printf("YES\n");
      for (auto p : ans) {
        int i, j;
        tie(i, j) = p;
        printf("%d %d\n", i + 1, j + 1);
      }
    }
  }
  return 0;
}
