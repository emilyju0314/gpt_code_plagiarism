#include<iostream>
#include<queue>
#include<numeric>
#include<cstdio>
#include<queue>
#include<cassert>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
const int inf = 100;
const int N = 5;
const int dy[]={1,1,-1,-1};
const int dx[]={0,1,0, -1};

const int wdy[2] = {-1,1};
int edge[66605][N][N];
int wdcost[N+1][66605];
class st{
public:
  int mat[N][N];
  st(){
    rep(i,N)rep(j,N)mat[i][j] = 0;
    rep(i,N)mat[i][i] = N-i;
    mat[0][0] = N-1;
  }
  bool operator<(const st & a)const{
    rep(i,N)rep(j,N)if (mat[i][j] != a.mat[i][j])return mat[i][j] < a.mat[i][j];
    return false;
  }
};

int getst(st &now,map<st,int> & M){
  int index = M.size();
  if (M.count(now) == 0)M[now] = index;
  return M[now];
}

map<st,int> NUM;
void makeall(){
  map<st,int> M;
  queue<st> Q;
  st ini;
  Q.push(ini);
  M.insert(make_pair(ini,0));
  while(!Q.empty()){
    st now = Q.front();Q.pop();
    int nownum = getst(now,NUM);
    int tc = M[now];
    wdcost[N][nownum] = tc;
    rep(i,N){
      if (accumulate(now.mat[i],now.mat[i+1],0) == N-i)continue;
      rep(j,N){
	rep(k,2){
	  int ney = i+wdy[k];
	  if (ney == -1 || ney == N)continue;
	  if (now.mat[ney][j] == 0)continue;
	  st next = now;
	  next.mat[i][j]++;
	  next.mat[ney][j]--;
	  int nextnum = getst(next,NUM);
	  edge[nownum][ney][j] = nextnum;
	  if (M.count(next) == 0){
	    M.insert(make_pair(next,tc+1));
	    Q.push(next);
	  }
	}
      }
    }
  }
}

int row[15];
int col[15];
void precalcWD(){
  const int ori[N][N]={
    1,3,6,10,15,
    2,5,9,14,0,
    4,8,13,0,0,
    7,12,0,0,0,
    11,0,0,0,0,
  };
  rep(i,N){
    rep(j,N){
      if (ori[i][j] == 1 || ori[i][j] == 0)continue;
      row[ori[i][j]] = i;
      col[ori[i][j]] = j;
    }
  }
}

pair<int,int> getWD(int n,int cpy[N][N]){
  if (n != 5)return make_pair(0,0);
  st r,c;
  int inp[N][N]={0};
  rep(j,N){
    int p = 0;
    rep(i,N){
      if (cpy[i][j] == 0)continue;
      inp[p++][j] = cpy[i][j];
    }
  }
  int matr[N][N]={},matc[N][N]={};
  rep(i,N){
    rep(j,N){
      if (inp[i][j] == 0 || inp[i][j] == 1)continue;
      matr[i][row[inp[i][j]]]++;
      matc[j][col[inp[i][j]]]++;
    }
  }


  //int wdr,wdc;
  rep(i,N)rep(j,N)r.mat[i][j] = matr[i][j];
  rep(i,N)rep(j,N)c.mat[i][j] = matc[i][j];
  return make_pair(NUM[r],NUM[c]);
}

void initWD(){
  rep(i,66605)rep(j,N)rep(k,N)edge[i][j][k] = -1;
  makeall();
  precalcWD();
}

//-------------------------------------------------------------------------------------
int mcost[N*N][N][N];
void precalc(int n){
  int pos[n][n];
  int p=0;
  rep(i,n){
    rep(j,i+1){
      rep(k,n)rep(l,k+1)mcost[p][k][l] = inf;
      mcost[p][i][j] = 0;
      pos[i][j] = p;
      p++;
    }
  }
  while(true){
    bool isupdate=false;
    rep(ii,n){
      rep(jj,ii+1){
	int now = pos[ii][jj];
	rep(i,n){
	rep(j,i+1){
	  rep(k,4){
	    int ney = i+dy[k],nex = j+dx[k];
	    if (ney == -1 || nex == -1 || ney == n || ney < nex)continue;
	    if (ney == i && nex == i+1)continue;
	    if (mcost[now][ney][nex] > mcost[now][i][j]+1){
	      isupdate = true;
	      mcost[now][ney][nex] = mcost[now][i][j]+1;
	    }
	    if (mcost[now][i][j] > mcost[now][ney][nex] + 1){
	      isupdate = true;
	      mcost[now][i][j] = mcost[now][ney][nex]+1;
	    }
	  }
	}
	}
      }
    }
    if (!isupdate)break;
  }
}
//-------------------------------------------------------------------------------------

int in[N][N];
int geth(int n){
  rep(i,n)rep(j,i+1)mcost[0][i][j] = 0;

  int ret = 0;
  rep(i,n){
    rep(j,i+1){
      ret += mcost[in[i][j]-1][i][j];
    }
  }
  return ret;
}

int ans;
bool solve(int n,int cnt,int lim,int py,int px,int prev,int h,int wdr,int wdc,int y,int x){
  if (h == 0){
    ans = min(ans,cnt);
    return true;
  }
  if (cnt + h > lim){
    return false;
  }
  if (n == 5 && cnt + wdcost[5][wdr] + wdcost[5][wdc] > lim){
    return false;
  }
  rep(k,4){
    int ney = y+dy[k],nex = x+dx[k];
    if (ney == -1 || nex == -1 || ney == n || ney < nex)continue;
    if (in[ney][nex] == prev)continue;

    int nexth = h + (mcost[in[ney][nex]-1][y][x]-mcost[in[ney][nex]-1][ney][nex]);
    int nextwdr=wdr,nextwdc=wdc;
    if (n == 5){
      if (k == 0 || k == 2){//wdr -> nextwdr
	assert(nex == x);
	int base = x;
	nextwdr = edge[wdr][ney-base][row[in[ney][nex]]];
      }else {//wdc -> nextwdc
	nextwdc = edge[wdc][nex][col[in[ney][nex]]];
      }
    }
    swap(in[y][x],in[ney][nex]);
    bool ret;
    ret = solve(n,cnt+1,lim,-1,-1,in[y][x],nexth,nextwdr,nextwdc,ney,nex);
    swap(in[y][x],in[ney][nex]);
    if (ret)return true;
  }
  return false;
}

int main(){
  initWD();
  int n;
  int tc = 1;
  while(cin>>n && n){
    ans = inf;
    rep(i,n){
      rep(j,i+1){
	cin>>in[i][j];
      }
    }
    precalc(n);
    int sy,sx;
    rep(i,n)rep(j,i+1)if (in[i][j] == 1)sy = i,sx=j;
    int mod = mcost[0][sy][sx];
    int h = geth(n);
    int beg = 0;
    
    pair<int,int> wd = getWD(n,in);
    int wdr=wd.first,wdc=wd.second;

    if (mod%2 != 0)beg++;
    for(int i=beg;;i+=2){
      ans = inf;
      bool ret = solve(n,0,i,-1,-1,-1,h,wdr,wdc,sy,sx);
      if (ret){break;}
    }
    cout <<"Case " << tc++ << ": " << ans << endl;
  }
  return 0;
}