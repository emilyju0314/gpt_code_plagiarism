#include <bits/stdc++.h>
using namespace std;
int h,w;
int sx,sy,gx,gy;
int cost[20][20][202];
int dx[4] ={0,0,1,-1};
int dy[4] ={1,-1,0,0};
const int INF = 1<< 28;
struct state{
  int x,y,c,t;
  state(){}
  state(int ax,int ay,int ac,int at):x(ax),y(ay),c(ac),t(at){}
  bool operator>(const state& right)const{
    return c > right.c;
  }
};

int main(){
  cin >> h >> w;
  for(int i = 0;i < 20;i++)for(int j = 0;j < 20;j++)for(int k = 0;k < 202;k++)cost[i][j][k] = INF;
  vector<vector<char> > field(h,vector<char>(w));
  
  for(int i = 0;i < h;i++){
    for(int j =0 ;j < w;j++){
      cin >> field[i][j];
      if(field[i][j] == 'S') {
	sx = j;sy = i;
      }else if(field[i][j] == 'G'){
	gx = j;gy = i;
      }	
    }
  }
  
  int n;
  cin >> n;
  vector<vector<vector<char> > > field_n(n+1,vector<vector<char> >(h,vector<char>(w,0)));
  vector<int> time(n);
  for(int j = 0;j < h;j++){
    for(int k = 0;k < w;k++){
      field_n[0][j][k] = field[j][k];
    }
  }
  for(int i = 0;i < n;i++){
    cin >> time[i];
    for(int j = 0;j < h;j++){
      for(int k = 0;k < w;k++){
	cin >> field_n[i+1][j][k];
      }
    }
  }
  priority_queue<state,vector<state>,greater<state> > que;
  que.push(state(sx,sy,0,0));
  while(!que.empty()){
    state cur = que.top();
    que.pop();
    int cx = cur.x;
    int cy = cur.y;
    int cc = cur.c;
    int ct = cur.t;
    int t_index = -1;
    for(int i = 0;i < time.size();i++){
      if(time[i] > ct+1){
	t_index = i;
	break;
      }
    }
    if(t_index == -1)t_index = n;
    if(ct+1>=200)ct=200;
    if(cost[cy][cx][ct+1] > cc && field_n[t_index][cy][cx] != '#'){
      cost[cy][cx][ct+1] = cc;
      que.push(state(cx,cy,cc,ct+1));
    }
    
    for(int i = 0;i < 4;i++){      
      int nx,ny;
      nx = cx+dx[i];ny = cy+dy[i];
      if(nx < 0 || nx >= w || ny < 0 || ny >= h || field_n[t_index][ny][nx] == '#'){

	continue;
      }
      if(cost[ny][nx][ct+1] > cc+1){
	cost[ny][nx][ct+1] = cc+1;
	que.push(state(nx,ny,cc+1,ct+1));
      }	  	  
    }    
  }
  
  int ans = INF;
  for(int i=0;i < 202;i++){
    ans = min(ans,cost[gy][gx][i]);
  }
  cout << (ans!=INF ? ans:-1) << endl;
  
  

  
  return 0;
}
