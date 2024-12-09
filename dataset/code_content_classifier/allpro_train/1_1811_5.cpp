#include <bits/stdc++.h>
using namespace std;
 
int n,m,q,a[51][51],dx[2][6]={{-1,-1,-1,0,1,0},{0,-1,0,1,1,1}},dy[6]={1,0,-1,-1,0,1};
bool u[51][51],u2[51][51];
bool check(int x, int y) {return (x>=0&&y>=0&&x<n&&y<m);}
 
int dfs(int x, int y, int k, bool o) {
  if(k!=a[x][y]) return 0;
  u[x][y]=u2[x][y]=true;
  if(o) a[x][y]=0;
  int sum=0;
  for(int i=0; i<6; i++) {
    if(check(x+dx[y%2][i],y+dy[i]) && !u2[x+dx[y%2][i]][y+dy[i]]) sum+=dfs(x+dx[y%2][i],y+dy[i],k,o);
  }
  return sum+1;
}
 
int main() {
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      char c;
      cin >> c;
      a[i][j]=(int)c;
    }
  }
  cin >> q;
  for(int t=0; t<=q; t++) {
    if(t) {
      int x,y;
      cin >> y >> x;
      x=n-x-1;
      int cnt=0;
      for(int i=0; i<6; i++) if(check(x+dx[y%2][i],y+dy[i])) cnt++;
      if(cnt==6) for(int i=0; i<5; i++) swap(a[x+dx[y%2][i]][y+dy[i]],a[x+dx[y%2][i+1]][y+dy[i+1]]);
    }
    while(1) {
      for(int i=n*2-1; i>=0; i--) {
        for(int j=i%2; j<m; j+=2) {
          int h=i/2;
          while(h<n-1 && a[h][j]) {
            for(int k=3; k<6; k++) if(check(h+dx[j%2][k],j+dy[k]) && a[h+dx[j%2][k]][j+dy[k]]) goto end;
            h++;
            swap(a[h][j],a[h-1][j]);
          }
        end:;
        }
      }
      bool ck=true;
      memset(u,0,sizeof(u));
      for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
          memset(u2,0,sizeof(u2));
          if(!u[i][j] && a[i][j] && dfs(i,j,a[i][j],0)>=3) {
            memset(u2,0,sizeof(u2));
            dfs(i,j,a[i][j],1);
            ck=false;
          }
        }
      }
      if(ck) break;
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) cout << (a[i][j]?(char)a[i][j]:'.');
    cout << endl;
  }
  return 0;
}
