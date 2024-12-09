#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int H,W;
int t[30][30],u[30][30];
ll dfs(int y,int x){
  if(x==W)return dfs(y+1,0);
  if(y==H)return 1;
  if(t[y][x]==1)return dfs(y,x+1);
  ll res=0;
  if(x+1<W&&t[y][x]==0&&t[y][x+1]==0){
    if(u[y][x]<2&&u[y+1][x]<2&&u[y][x+2]<2&&u[y+1][x+2]<2){
      u[y][x]++;u[y+1][x]++;u[y][x+2]++;u[y+1][x+2]++;
      t[y][x]=t[y][x+1]=1;
      res+=dfs(y,x+1);
      t[y][x]=t[y][x+1]=0;
      u[y][x]--;u[y+1][x]--;u[y][x+2]--;u[y+1][x+2]--;
    }
  }
  if(y+1<H&&t[y][x]==0&&t[y+1][x]==0){
    if(u[y][x]<2&&u[y+2][x]<2&&u[y][x+1]<2&&u[y+2][x+1]<2){
      u[y][x]++;u[y+2][x]++;u[y][x+1]++;u[y+2][x+1]++;
      t[y][x]=t[y+1][x]=1;
      res+=dfs(y,x+1);
      t[y][x]=t[y+1][x]=0;
      u[y][x]--;u[y+2][x]--;u[y][x+1]--;u[y+2][x+1]--;
    }
  }
  return res;
}

int main(){
  while(1){
    cin>>H>>W;
    if(H==0&&W==0)break;
    cout<<dfs(0,0)<<endl;
  }
  return 0;
}