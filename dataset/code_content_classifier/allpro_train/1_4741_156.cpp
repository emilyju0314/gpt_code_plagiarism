#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int n;
double x[200000],y[200000];
char d[200000][2];
int dx[]{1,-1,0,0},dy[]{0,0,1,-1};
map<char,int>dir;

double f(double t,int mode){
  double Min=-1,Max=-1;
  for(int i = 0; i < n; i++) {
    double X;
    if(mode == 0) X = x[i] + dx[dir[d[i][0]]] * t;
    else X = y[i] + dy[dir[d[i][0]]] * t;
    if(i == 0) Min = Max = X;
    else Min = min(Min, X), Max = max(Max, X);
  } return Max - Min;
}

int main() {
  dir['R'] = 0; dir['L'] = 1;
  dir['U'] = 2; dir['D'] = 3;
  cin >> n;
  rep(i, n) scanf("%lf%lf%s",&x[i],&y[i],d[i]);
  double l = 0, r = 1e15;
  for(int i = 0; i < 200; i++) {
    double l1 = (l + l + r) / 3;
    double l2 = (l + r + r) / 3;
    if(f(l1, 0) * f(l1, 1) < f(l2, 0) * f(l2, 1))
      r = l2; else l = l1;
  } printf("%.12lf\n", f(l, 0) * f(l, 1));
}
