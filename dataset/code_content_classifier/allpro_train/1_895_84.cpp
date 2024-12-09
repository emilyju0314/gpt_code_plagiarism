#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int INF = 1000 * 1000 * 1000;
const double EPS = 1e-9;
const int MXN = 101010;
int a[MXN];
int p[MXN], np[MXN], c[20][MXN], nc[MXN];
int cnt[MXN];
int lns[MXN];
int N;
map<int, int> inv;
void compress() {
  map<int, int> compressor;
  for (int i = (0); i < (N); ++i) {
    compressor.insert(make_pair(a[i], 0));
  }
  int q = 0;
  for (map<int, int>::iterator it = compressor.begin(); it != compressor.end();
       ++it) {
    it->second = q++;
    inv.insert(make_pair(it->second, it->first));
  }
  for (int i = (0); i < (N); ++i) {
    a[i] = compressor[a[i]];
  }
}
void buildSuffixArray() {
  for (int i = (0); i < (N); ++i) {
    ++cnt[a[i]];
  }
  for (int i = (1); i < (MXN); ++i) {
    cnt[i] += cnt[i - 1];
  }
  for (int i = N - 1; i >= 0; --i) {
    p[--cnt[a[i]]] = i;
  }
  int clsNum = 0;
  for (int i = (1); i < (N); ++i) {
    if (a[p[i]] != a[p[i - 1]]) {
      ++clsNum;
    }
    c[0][p[i]] = clsNum;
  }
  int fint = 0;
  for (int t = 0; (1 << t) < N; ++t) {
    for (int i = (0); i < (N); ++i) {
      np[i] = p[i] - (1 << t);
      if (np[i] < 0) {
        np[i] += N;
      }
    }
    memset(cnt, 0, sizeof cnt);
    for (int i = (0); i < (N); ++i) {
      ++cnt[c[t][np[i]]];
    }
    for (int i = (1); i < (clsNum + 1); ++i) {
      cnt[i] += cnt[i - 1];
    }
    for (int i = N - 1; i >= 0; --i) {
      p[--cnt[c[t][np[i]]]] = np[i];
    }
    clsNum = 0;
    nc[p[0]] = 0;
    for (int i = (1); i < (N); ++i) {
      if (c[t][p[i]] != c[t][p[i - 1]] ||
          c[t][(p[i] + (1 << t)) % N] != c[t][(p[i - 1] + (1 << t)) % N]) {
        ++clsNum;
      }
      nc[p[i]] = clsNum;
    }
    for (int i = (0); i < (N); ++i) {
      c[t + 1][i] = nc[i];
    }
    fint = t + 1;
  }
}
bool compare(int stp1, int stp2, int len) {
  if (stp2 + len > N) {
    return false;
  }
  int t = lns[len];
  if (c[t][stp1] != c[t][stp2] &&
      c[t][stp1 + len - (1 << t)] != c[t][stp2 + len - (1 << t)]) {
    return false;
  }
  return true;
}
int main() {
  scanf("%d", &N);
  for (int i = (0); i < (N); ++i) {
    scanf("%d", &a[i]);
  }
  compress();
  buildSuffixArray();
  for (int i = (2); i < (N + 1); ++i) {
    lns[i] = lns[i >> 1] + 1;
  }
  map<int, vector<int> > df;
  for (int i = (0); i < (N); ++i)
    if (df.find(a[i]) != df.end()) {
      df[a[i]].push_back(i);
    } else {
      vector<int> tin;
      tin.push_back(i);
      df.insert(make_pair(a[i], tin));
    }
  vector<pair<int, int> > rpt;
  for (map<int, vector<int> >::iterator it = df.begin(); it != df.end(); ++it) {
    vector<int> cur = it->second;
    for (int i = (0); i < ((int)cur.size() - 1); ++i)
      for (int j = (i + 1); j < ((int)cur.size()); ++j) {
        int idl = cur[i], idr = cur[j], len = idr - idl;
        if (compare(idl, idr, len)) {
          rpt.push_back(make_pair(len << 1, idl));
        }
      }
  }
  sort(rpt.begin(), rpt.end());
  int pt = -1;
  for (int i = (0); i < ((int)rpt.size()); ++i)
    if (rpt[i].second >= pt) {
      pt = rpt[i].second + (rpt[i].first >> 1);
    }
  if (pt == -1) {
    printf("%d\n", N);
    for (int i = (0); i < (N); ++i) {
      printf("%d ", inv[a[i]]);
    }
  } else {
    printf("%d\n", N - pt);
    for (int i = (pt); i < (N); ++i) {
      printf("%d ", inv[a[i]]);
    }
  }
  return 0;
}
