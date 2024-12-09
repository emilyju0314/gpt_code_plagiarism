#include <bits/stdc++.h>
using namespace std;
const int H = 7;
vector<int> succ[1 << H];
int fa[1 << H];
inline void work() {
  int h;
  scanf("%d", &h);
  for (int i = 1 << h; --i;) succ[i].clear();
  memset(fa, 0, sizeof(fa));
  if (succ[1].empty()) {
    printf("? %d\n", 1);
    fflush(stdout);
    {
      int k;
      scanf("%d", &k);
      if (!k) exit(0);
      succ[1].resize(k);
      for (int i = k; i--;) scanf("%d", &succ[1][i]);
      if (k == 2) {
        printf("! %d\n", 1);
        fflush(stdout);
        return;
      }
    }
  }
  int node = 1, depth;
  if (succ[node].size() == 1) {
    node = succ[node][0];
    if (h == 2) {
      printf("! %d\n", node);
      fflush(stdout);
      return;
    } else {
      if (succ[node].empty()) {
        printf("? %d\n", node);
        fflush(stdout);
        {
          int k;
          scanf("%d", &k);
          if (!k) exit(0);
          succ[node].resize(k);
          for (int i = k; i--;) scanf("%d", &succ[node][i]);
          if (k == 2) {
            printf("! %d\n", node);
            fflush(stdout);
            return;
          }
        }
      }
    }
  }
  int len[3] = {1, 1, 1};
  for (int i = 3; i--;) {
    int now = succ[node][i];
    if (succ[now].empty()) {
      printf("? %d\n", now);
      fflush(stdout);
      {
        int k;
        scanf("%d", &k);
        if (!k) exit(0);
        succ[now].resize(k);
        for (int i = k; i--;) scanf("%d", &succ[now][i]);
        if (k == 2) {
          printf("! %d\n", now);
          fflush(stdout);
          return;
        }
      }
    }
    for (; succ[now].size() != 1; ++len[i]) {
      now = succ[now][!succ[succ[now][0]].empty()];
      if (succ[now].empty()) {
        printf("? %d\n", now);
        fflush(stdout);
        {
          int k;
          scanf("%d", &k);
          if (!k) exit(0);
          succ[now].resize(k);
          for (int i = k; i--;) scanf("%d", &succ[now][i]);
          if (k == 2) {
            printf("! %d\n", now);
            fflush(stdout);
            return;
          }
        }
      }
    }
  }
  depth = h - min(len[0], len[1]);
  int x = max_element(len, len + 3) - len;
  fa[node] = succ[node][x];
  node = succ[node][x];
  for (int i = len[x] - (h - depth) >> 1; --i; --depth)
    node = fa[node] = succ[node][fa[succ[node][0]] == node];
  depth -= 2;
  node = fa[node] = succ[node][2 - succ[succ[node][1]].empty()];
  if (depth == 1) {
    printf("! %d\n", node);
    fflush(stdout);
    return;
  } else {
    if (succ[node].empty()) {
      printf("? %d\n", node);
      fflush(stdout);
      {
        int k;
        scanf("%d", &k);
        if (!k) exit(0);
        succ[node].resize(k);
        for (int i = k; i--;) scanf("%d", &succ[node][i]);
        if (k == 2) {
          printf("! %d\n", node);
          fflush(stdout);
          return;
        }
      }
    }
  }
  if (h - depth == depth - 1) {
    int now = succ[node][!succ[succ[node][0]].empty()];
    if (succ[now].empty()) {
      printf("? %d\n", now);
      fflush(stdout);
      {
        int k;
        scanf("%d", &k);
        if (!k) exit(0);
        succ[now].resize(k);
        for (int i = k; i--;) scanf("%d", &succ[now][i]);
        if (k == 2) {
          printf("! %d\n", now);
          fflush(stdout);
          return;
        }
      }
    }
    for (int i = 3; --i;) {
      now = succ[now][!succ[succ[now][0]].empty()];
      if (succ[now].empty()) {
        printf("? %d\n", now);
        fflush(stdout);
        {
          int k;
          scanf("%d", &k);
          if (!k) exit(0);
          succ[now].resize(k);
          for (int i = k; i--;) scanf("%d", &succ[now][i]);
          if (k == 2) {
            printf("! %d\n", now);
            fflush(stdout);
            return;
          }
        }
      }
    }
    if (succ[now].size() == 1) {
      node = fa[node] = succ[node][2 - succ[succ[node][1]].empty()];
      if (succ[node].empty()) {
        printf("? %d\n", node);
        fflush(stdout);
        {
          int k;
          scanf("%d", &k);
          if (!k) exit(0);
          succ[node].resize(k);
          for (int i = k; i--;) scanf("%d", &succ[node][i]);
          if (k == 2) {
            printf("! %d\n", node);
            fflush(stdout);
            return;
          }
        }
      }
    } else
      node = fa[node] = succ[node][fa[succ[node][0]] == node];
    --depth;
  }
  int q[8];
  q[1] = node;
  for (int h = 1, t = 2;; ++h)
    for (int i = 3; i--;)
      if (succ[q[h]][i] != fa[q[h]] && fa[succ[q[h]][i]] != q[h]) {
        q[t] = succ[q[h]][i];
        fa[q[t]] = q[h];
        if (t + 1 < 1 << depth) {
          if (succ[q[t]].empty()) {
            printf("? %d\n", q[t]);
            fflush(stdout);
            {
              int k;
              scanf("%d", &k);
              if (!k) exit(0);
              succ[q[t]].resize(k);
              for (int i = k; i--;) scanf("%d", &succ[q[t]][i]);
              if (k == 2) {
                printf("! %d\n", q[t]);
                fflush(stdout);
                return;
              }
            }
          }
        } else {
          printf("! %d\n", q[t]);
          fflush(stdout);
          return;
        }
        ++t;
      }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) work();
}
