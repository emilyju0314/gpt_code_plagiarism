#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n;i++)
vector<vector<bool>>used(129,vector<bool>(129,true));
vector<string>graph(130);
int n;
bool inrange(int x,int y){return(0<=x&&x<n&&0<=y&&y<n);}
void bfs(int y,int x){
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
    used[y][x]=false;
    
    using pii =pair<int,int>;
    queue<pii>q;
    q.push(pii(y,x));
    while(!q.empty()){
        pii now=q.front(); q.pop();
        rep(i,4){
            int _x=now.second+dx[i];
            int _y=now.first+dy[i];
            if((!inrange(_x,_y))||
               graph[_y][_x]=='x')continue;
            if(!used[_y][_x])continue;
            q.push(pii(_y,_x));
            used[_y][_x]=false;
        }
    }
}
int main(){
    cin>>n;
    rep(i,n)cin>>graph[i];
    int cnt=0;
    rep(i,n)rep(j,graph[i].size()){
        if(graph[i][j]=='o'&&used[i][j]){bfs(i,j); cnt++;}
        //ep(i,n){rep(j,graph[i].size())if(used[i][j])cout<<"o";else cout<<"x"; cout<<endl;}
    }
    cout<<cnt/3<<endl;
}