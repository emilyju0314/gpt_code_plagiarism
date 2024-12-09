#include <bits/stdc++.h>
using namespace std;
struct node {
  int b;
  double t;
  node(){};
  node(int B, double T) {
    b = B;
    t = T;
  }
};
struct edge {
  double x, y, z;
  edge(){};
  edge(double X, double Y, double Z) {
    x = X;
    y = Y;
    z = Z;
  }
};
int n;
double f[100005][5], siz[100005];
vector<node> G[100005];
bool cmp(edge a, edge b) { return a.y * b.x < b.y * a.x; }
void dfs(int x, int fa) {
  vector<edge> fuck;
  siz[x] = 1;
  for (int i = 0; i < G[x].size(); i++) {
    int tmp = G[x][i].b, tot = G[x][i].t;
    if (fa != tmp) {
      dfs(tmp, x);
      f[x][1] += f[tmp][1], siz[x] += siz[tmp];
      fuck.push_back(edge(siz[tmp], f[tmp][2] + tot * 2, tot));
    }
  }
  sort(fuck.begin(), fuck.end(), cmp);
  for (int i = 0; i < fuck.size(); i++) {
    f[x][1] += (f[x][2] + fuck[i].z) * fuck[i].x;
    f[x][2] += fuck[i].y;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    double t;
    scanf("%d %d %lf", &a, &b, &t);
    G[a].push_back(node(b, t));
    G[b].push_back(node(a, t));
  }
  dfs(1, 0);
  printf("%.6lf\n", f[1][1] / (siz[1] - 1));
  return 0;
}
