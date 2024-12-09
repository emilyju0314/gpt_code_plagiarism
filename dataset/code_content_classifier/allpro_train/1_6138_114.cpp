#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n;i++)
const int INF=1e9;
using namespace std;

vector<vector<char>>v(31,vector<char>(31,'.'));
int h,w,n;
bool simulate(vector<vector<char>>graph){
    
    vector<vector<bool>>flag(h+1,vector<bool>(w+1,true));
    rep(i,h)rep(j,w)if(graph[i][j]=='.')flag[i][j]=false;
    vector<vector<char>>temp(h+1,vector<char>(w+1,'.'));
    for(int dx=w-1; dx>=0;dx--){
        int index=h-1;
        for(int dy=h-1;dy>=0&&index>=0;dy--)if(flag[dy][dx])temp[index--][dx]=graph[dy][dx];
    }
    graph=temp;
    //rep(i,h){rep(j,w){cout<<graph[i][j];}cout<<endl;}cout<<endl;
    while(true){
        bool changeble=false;
        vector<vector<bool>>init(h+1,vector<bool>(w+1,true));
        flag=init;
        rep(i,h)rep(j,w)if(graph[i][j]=='.')flag[i][j]=false;
        for(int y=0; y<h;y++){
            for(int x=0; x<w;x++){
                if(graph[y][x]=='.')continue;
                int cnt=0;
                for(int dx=x; dx<w;dx++){
                    //if(graph[y][dx]=='.')continue;
                    if(graph[y][dx]==graph[y][x])cnt++; else break;
                }
                if(cnt>=n){
                    for(int dx=x;cnt>0&&dx<w;dx++){
                        if(graph[y][dx]=='.')continue;
                        flag[y][dx]=false;
                        --cnt;
                        changeble=true;
                    }
                }
                cnt=0;
                for(int dy=y; dy<h;dy++){
                    //if(graph[dy][x]=='.')continue;
                    if(graph[dy][x]==graph[y][x])cnt++; else break;
                }
                if(cnt>=n){
                    for(int dy=y;dy<h&&cnt>0;dy++){
                        if(graph[dy][x]=='.')continue;
                        flag[dy][x]=false;
                        --cnt;
                        changeble=true;
                    }
                }
            }
        }
        /*?????????????????¨???*/
        vector<vector<char>>temp(h+1,vector<char>(w+1,'.'));
        for(int dx=w-1; dx>=0;dx--){
            int index=h-1;
            for(int dy=h-1;dy>=0&&index>=0;dy--)if(flag[dy][dx])temp[index--][dx]=graph[dy][dx];
        }
        graph=temp;
        if(!changeble)break;
    }
    bool ans=true;
    rep(i,h)rep(j,w)if(graph[i][j]!='.')ans=false;
    return ans;
}
bool solve(){
    bool hoge=false;
    rep(i,h)rep(j,w){
        vector<vector<char>>y(31,vector<char>(31,'.'));
        vector<vector<char>>x(31,vector<char>(31,'.'));
        y=v; x=v;
        //if(i<h-1){swap(y[i][j],y[i+1][j]);if(simulate(y))hoge=true;}
        if(j<w-1){swap(x[i][j],x[i][j+1]);if(simulate(x))hoge=true;}
    }
    return hoge;
}
int main(){
    cin>>h>>w>>n;
    rep(i,h)rep(j,w)cin>>v[i][j];
    if(solve())cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}