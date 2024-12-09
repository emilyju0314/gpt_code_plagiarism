#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1024;
char s[MAX_N + 4];
int vs[MAX_N], vids[MAX_N], cns[MAX_N], ds[MAX_N];
vector<int> nbrs[MAX_N];
inline int readvar(char *(&cpt)) {
  while (*cpt != '_') cpt++;
  int l = 0;
  while (*cpt == '_') cpt++, l++;
  return l;
}
inline void setmax(int &a, int b) {
  if (a < b) a = b;
}
int main() {
  scanf("%s", s);
  memset(vids, -1, sizeof(vids));
  int vn = 0, n = 0;
  char *cpt = s;
  while (*cpt != ')') {
    int l = readvar(cpt);
    if (vids[l] < 0) vids[l] = n++;
    vs[vn++] = vids[l];
  }
  cpt += 3;
  while (*cpt != '.') {
    int l0 = readvar(cpt);
    char op = *cpt;
    int l1 = readvar(cpt);
    int v0 = vids[l0], v1 = vids[l1];
    if (op == '<')
      nbrs[v0].push_back(v1), cns[v1]++;
    else
      nbrs[v1].push_back(v0), cns[v0]++;
  }
  queue<int> q;
  for (int i = 0; i < n; i++)
    if (cns[i] == 0) q.push(i);
  int m = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    m++;
    if (ds[u] > 9) {
      puts("false");
      return 0;
    }
    int vd = ds[u] + 1;
    vector<int> &nbru = nbrs[u];
    for (vector<int>::iterator vit = nbru.begin(); vit != nbru.end(); vit++) {
      int v = *vit;
      setmax(ds[v], vd);
      if (--cns[v] == 0) q.push(v);
    }
  }
  if (m < n) {
    puts("false");
    return 0;
  }
  for (int i = 0; i < vn; i++) printf("%d", ds[vs[i]]);
  putchar('\n');
  return 0;
}
