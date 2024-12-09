#include<iostream>
#include<cstring>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

string g[12];
bool vis[12][12];
bool clr[12][12];
const int dy[] = {-1,0,1,0}, dx[] = {0,1,0,-1};

int dfs(int y,int x,int col){
  if(g[y][x] != col)return 0;
  if(vis[y][x])return 0;
  vis[y][x] = true;

  int res = 1;
  rep(i,4){
    int ny = y+dy[i], nx = x+dx[i];
    if(ny<0 || nx<0 || ny>=12 || nx>=6)continue;
    res += dfs(ny,nx,col);
  }
  return res;
}


int chain(void){
  memset(clr,0,sizeof(clr));
  rep(i,12){
    rep(j,6){
      if(g[i][j] != '.' && g[i][j] != 'O' && !clr[i][j]){
	memset(vis,0,sizeof(vis));
	if(dfs(i,j,g[i][j])>=4){
	  rep(ii,12)rep(jj,6)clr[ii][jj] |= vis[ii][jj];
	}
      }
    }
  }

  rep(i,12){
    rep(j,6){
      if(g[i][j] == 'O'){
	rep(k,4){
	  int ny = i+dy[k], nx = j+dx[k];
	  if(ny<0 || nx<0 || ny>=12 || nx>=6)continue;
	  if(g[ny][nx] != 'O' && clr[ny][nx]){
	    clr[i][j] = true;
	  }
	}
      }
    }
  }

  int num = 0;
  rep(i,12){
    rep(j,6){
      if(clr[i][j])g[i][j] = '.', num++;
    }
  }
  if(num==0)return 0;

  rep(i,6){
    for(int j=11;j>=0;j--){
      if(g[j][i] != '.'){
	for(int k=j+1;k<12;k++){
	  if(g[k][i] == '.')swap(g[k][i],g[k-1][i]);
	  else break;
	}
      }
    }
  }

  return chain()+1;
}

int main(){
  int n;
  cin >> n;
  while(n--){
    rep(i,12)cin >> g[i];
    cout << chain() << endl;
  }
}