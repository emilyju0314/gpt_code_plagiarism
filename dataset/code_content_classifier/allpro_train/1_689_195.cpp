#include<cstdio>

using namespace std;

#define rep(i, n) for(i = 0;i < n;++i)
#define int2(x, y) int x, y; scanf("%d%d",&x, &y)

int G[100][100] = {0};
int inf = 0;
bool warshallfloyd(int v){
  int i, j, k;
  rep(k, v)rep(i, v)rep(j, v)if(G[i][k] != inf && G[k][j] != inf && G[i][j] > G[i][k] + G[k][j])G[i][j] = G[i][k] + G[k][j];
  rep(i, v)if(G[i][i] < 0)return false;
  return true;
}

signed main(void){
  int i, j;
  int2(v, e);
  rep(i, e){
    int2(a, b);
    G[a][b] = -1;
  }
  puts(warshallfloyd(v) ? "0" : "1");

  return 0;
}