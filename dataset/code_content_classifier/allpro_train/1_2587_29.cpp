#include<bits/stdc++.h>
#define N 101
using namespace std;
 
int w,h,ans;
int m[N][N],f[N][N];
int dx[2][6]={{0,1,0,-1,-1,-1},{1,1,1,0,-1,0}};
  int dy[2][6]={{-1,0,1,1,0,-1},{-1,0,1,1,0,-1}};

int flag;

int dfs(int x,int y,int num,int cnt){
  f[y][x]=1;
  for(int i=0;i<6;i++){
    if(y+dy[num][i]>h || x+dx[num][i]>w || y+dy[num][i]<=0 || x+dx[num][i]<=0){flag=1;continue;}
    if(m[y+dy[num][i]][x+dx[num][i]])cnt++;
    else if(!m[y+dy[num][i]][x+dx[num][i]] && !f[y+dy[num][i]][x+dx[num][i]])cnt=dfs(x+dx[num][i],y+dy[num][i],(y+dy[num][i])%2,cnt);
      }
    if(flag==1) return 0;
    else return cnt;
}
 
int main(){
   cin>>w>>h;
   for(int i=1;i<=h;i++)
    for(int j=1;j<=w;j++)cin>>m[i][j];
 
  for(int i=1;i<=h;i++)
    for(int j=1;j<=w;j++){
      int num=i%2;
    if(m[i][j])ans+=6;
      if(m[i][j]){
    for(int dxy=0;dxy<6;dxy++){
        if(i+dy[num][dxy]>h || j+dx[num][dxy]>w || i+dy[num][dxy]<=0 || j+dx[num][dxy]<=0) continue;
        else if(m[i+dy[num][dxy]][j+dx[num][dxy]])ans--;
    }
      }else {
    if(f[i][j]==0)flag=0,ans-=dfs(j,i,i%2,0);
      }
    }
  cout<<ans<<endl;
  return 0;
}