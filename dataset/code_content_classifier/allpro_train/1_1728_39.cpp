#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define INF 1000000000000000000
#define MP(a,b,c) make_pair(a,make_pair(b,c))
using namespace std;
typedef long long ll;
typedef pair <ll,pair<int,int> > P;
int h,w,n;
ll mp[1010][1010],D[1010][1010];
bool visited[1010][1010];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

void mk_mp(int x,int y,int t,string str){
  mp[y][x]++;
  while(t--)
    for(int i=0;i<(int)str.size();i++){
      int j=0;//D
      if(str[i]=='U')j=1;
      if(str[i]=='L')j=2;
      if(str[i]=='R')j=3;
      int nx=x+2*dx[j],ny=y+2*dy[j];
      if(nx<1||ny<1||nx>=2*w||ny>=2*h)continue;
      x=nx,y=ny;
      mp[y][x]++;
      mp[y-dy[j]][x-dx[j]]++;
    }  
}

ll dijkstra(int x,int y,int gx,int gy){
  for(int i=0;i<1010;i++)
    for(int j=0;j<=1010;j++) D[i][j]=INF;
  priority_queue <P,vector<P>,greater<P> > Q;
  Q.push(MP(0,x,y));
  D[y][x]=0;
  while(!Q.empty()){
    ll dis=Q.top().first;
    int x=Q.top().second.first;
    int y=Q.top().second.second;
    Q.pop();
    if(x==gx&&y==gy)return dis;
    if(visited[y][x]==1)continue;
    visited[y][x]=1;  
    for(int i=0;i<4;i++){
      int nx=x+dx[i],ny=y+dy[i];
      if(nx<0||ny<0||nx>2*w||ny>2*h||D[ny][nx]<=dis+mp[ny][nx])continue;
      Q.push(MP(dis+mp[ny][nx],nx+dx[i],ny+dy[i]));
      D[ny][nx]=dis+mp[ny][nx];
    }
  }
  return -1;
}

int main() {
  int sx,sy,gx,gy;
  cin>>w>>h>>n;
  cin>>sx>>sy>>gx>>gy;
  for(int i=0;i<n;i++){
    int x,y,t;
    string str;
    cin>>x>>y;
    cin>>t>>str;
    mk_mp(2*x+1,2*y+1,t,str);
  }
  cout << dijkstra(2*sx,2*sy,2*gx,2*gy)<<endl;
  return 0;
}