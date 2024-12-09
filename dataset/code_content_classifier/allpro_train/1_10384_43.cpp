#include<iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int n,m,p,X,Y,Z,res,b[9][9][9];
int dx[] = {1,0,0,1,1,0,-1,-1, 0,1, 1, 1,-1};
int dy[] = {0,1,0,1,0,1, 1, 0,-1,1, 1,-1, 1};
int dz[] = {0,0,1,0,1,1, 0, 1, 1,1,-1, 1, 1};

inline int check(int col){
  rep(i,n)rep(j,n)rep(k,n){
    if(b[i][j][k]==col){
      rep(t,13){
	int c=0,tx=i,ty=j,tz=k;
	while(c<m && 0<=tx && tx<n && 0<=ty && ty<n && 0<=tz && tz<n){
	  if(b[tx][ty][tz] == b[i][j][k])c++;
	  else break;
	  tx += dx[t]; ty += dy[t]; tz += dz[t];
	}
	if(c==m)return b[i][j][k];
      }
    }
  }
  return -1;
}

int main(){
  std::ios::sync_with_stdio(false);
  while(cin >> n >> m >> p,n+m+p){
    rep(i,n)rep(j,n)rep(k,n)b[i][j][k] = -1;

    bool f = true;
    rep(i,p){
      cin >> X >> Y;
      if(f){
	X--; Y--;Z=0;
	while(b[X][Y][Z]>=0)Z++;
	b[X][Y][Z] = i&1;
	
	res = check(i&1);
	if(res==0){
	  cout << "Black " << i+1 << endl;
	  f = false;
	}else if(res==1){
	  cout << "White " << i+1 << endl;
	  f = false;
	}
      }
    }
    if(f)cout << "Draw\n";
  }
}