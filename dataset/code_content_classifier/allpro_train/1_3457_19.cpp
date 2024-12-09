#include<iostream>
using namespace std;
typedef long long ll;

char dc[]={'N','E','S','W'};
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

int change(char ch){
  for(int i=0;i<4;i++)if(dc[i]==ch)return i;
}

int H,W,sx,sy,sdir;
ll L;
char t[100][100];
string str;

void input();
void solve();
void dfs(int,int,int,int,ll);

int main(){
  while(1){
    cin>>H>>W>>L;
    if(H==0&&W==0&&L==0)break;
    input();
    solve();
  }
  return 0;
}

void input(){
  for(int i=0;i<H;i++){
    cin>>str;
    for(int j=0;j<W;j++){
      if(str[j]!='#'&&str[j]!='.'){
	t[i][j]='.';
	sy=i;
	sx=j;
	sdir=change(str[j]);
      }else t[i][j]=str[j];
    }
  }  
}

ll vd[100][100][4];

void solve(){
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      for(int k=0;k<4;k++){
	vd[i][j][k]=-1;
      }
    }
  }

  dfs(sy,sx,sdir,0,0);
}



void dfs(int y,int x,int dir,int dir2,ll cnt){
  dir%=4;

  if(cnt>=L){
    cout<<y+1<<' '<<x+1<<' '<<dc[dir]<<endl;
    return;
  }
  
  if( L-cnt>=50000LL && vd[y][x][dir]!=-1 ){
    ll ncnt;
    ncnt=(L-cnt)%(cnt-vd[y][x][dir]);
    dfs(y,x,dir2,dir2,L-ncnt-(cnt-vd[y][x][dir]));
    return;
  }

  vd[y][x][dir]=cnt;
  
  int ny=y+dy[dir];
  int nx=x+dx[dir];
  if(ny<0||nx<0)dfs(y,x,dir+1,dir,cnt);
  else if(ny>=H||nx>=W)dfs(y,x,dir+1,dir,cnt);
  else if(t[ny][nx]=='#')dfs(y,x,dir+1,dir,cnt);
  else dfs(ny,nx,dir,dir,cnt+1);

}