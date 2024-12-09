#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <array>

using namespace std;

#define loop(i,a,b) for(int i=(a); i<(int)(b); i++)
#define rep(i,b) loop(i,0,b)
#define pb push_back

const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={-1,0,1,-1,1,-1,0,1};
inline bool in(int x, int y){ return 0<=x&&x<4&&0<=y&&y<4; }
int n;
char board[4][5];
array<int,100> v,w,c;
array<string,100> word;
array<array<bool,4>,4> used;
array<int,10001> dp;

void dfs(int i,int x,int y,int si){
    const string& s=word[si];
    used[y][x]=1;
    if(i==(int)s.size()-1){
        c[si]++;
    } else {
        rep(d,8){
            int nx=x+dx[d], ny=y+dy[d];
            if(in(nx,ny) && s[i+1]==board[ny][nx] && !used[ny][nx])
                dfs(i+1,nx,ny,si);
        }
    }
    used[y][x]=0;
}

int main(){
    cin>>n;
    rep(i,n){
        cin>>word[i];
        cin>>v[i];
        w[i]=word[i].size();
    }
    rep(i,4) cin>>board[i];
    rep(si,n)rep(y,4)rep(x,4){
        if(word[si][0]==board[y][x]) dfs(0,x,y,si);
    }
    int sum;cin>>sum;
    rep(i,n){
        if(c[i]==0) continue;
        for(int j=sum; j>=0; j--){
            for(int k=1; k<=c[i] && j-w[i]*k>=0; k++){
                dp[j]=max(dp[j],dp[j-w[i]*k]+v[i]*k);
            }
        }
    }
    cout<<dp[sum]<<endl;
}