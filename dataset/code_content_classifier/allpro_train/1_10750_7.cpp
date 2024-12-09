#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n, m;
int fa[N + 3], deg[N + 3], ans[N + 3];
vector<pair<long long, int> > qry[N + 3];
vector<int> cnt[N + 3];
inline long long QRead() {
  long long resu = 0;
  char c = (char)getchar();
  while ('0' > c || c > '9') c = (char)getchar();
  while ('0' <= c && c <= '9')
    resu = (resu << 1) + (resu << 3) + c - '0', c = (char)getchar();
  return resu;
}
void Merge(vector<int> &A, vector<int> &B) {
  if (A.size() < B.size()) swap(A, B);
  for (int i = 1; i <= B.size(); i++) A[A.size() - i] += B[B.size() - i];
}
int main() {
  n = (int)QRead();
  for (int i = 1; i <= n; i++) {
    fa[i] = (int)QRead();
    deg[fa[i]]++;
  }
  m = (int)QRead();
  for (int i = 1; i <= m; i++) {
    long long x = QRead();
    int y = (int)QRead();
    qry[y].push_back(make_pair(x, i));
  }
  queue<int> lev;
  for (int i = 1; i <= n; i++) {
    if (!deg[i]) lev.push(i);
    cnt[i].push_back(1);
  }
  while (!lev.empty()) {
    int u = lev.front();
    lev.pop();
    for (int i = 0; i < (int)qry[u].size(); i++) {
      pair<long long, int> now = qry[u][i];
      if (now.first >= (int)cnt[u].size())
        ans[now.second] = 0;
      else
        ans[now.second] = cnt[u][cnt[u].size() - 1 - now.first];
    }
    cnt[u].push_back(0);
    Merge(cnt[fa[u]], cnt[u]);
    deg[fa[u]]--;
    if (!deg[fa[u]]) lev.push(fa[u]);
  }
  for (int u = 1; u <= n; u++)
    if (deg[u]) {
      int cop = u, siz = 0;
      vector<int> cir;
      do {
        deg[cop] = 0;
        vector<int> cpy = cnt[cop];
        Merge(cir, cpy);
        siz++;
        cir.push_back(0);
        cop = fa[cop];
      } while (cop != u);
      for (int i = 1; i + siz <= cir.size(); i++)
        cir[cir.size() - i - siz] += cir[cir.size() - i];
      do {
        Merge(cir, cnt[cop]);
        for (int i = 0; i < qry[cop].size(); i++) {
          long long qm = qry[cop][i].first;
          int id = qry[cop][i].second;
          qm = cir.size() - 1 - qm;
          if (qm < 0) qm = (qm % siz + siz) % siz;
          ans[id] = cir[qm];
        }
        cop = fa[cop];
        cir.push_back(0);
      } while (cop != u);
    }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
