#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iostream>
#include<cmath>
#include<map>
#include<set>
#include<climits>
using namespace std;
typedef vector<string>vs;
typedef vector<int>vi;
typedef vector<vi>vvi;
typedef vector<double>vd;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef vector<ll>vl;
typedef pair<int,pii>piii;
#define rrep(i,x,n) for(int i=(x);i<(n);++i)
#define rep(i,x) rrep(i,0,(x))
#define fi first
#define se second
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define pb push_back
#define maxs(a,b) (a)=max(a,b)
#define mins(a,b) (a)=min(a,b)
///#include<sstream>
///#include<cstring>
///#include<stack>
///#include<complex>


const int dx[]={0,0,-1,1};
const int dy[]={-1,1,0,0};
struct State{
    int fld[20][20];
    int H,W;
    int y,x;
    int dir;
    void CTR(char c){
        if(c=='S')Fire();
        else Move(c);
    }
    void Move(char c){
        if(c=='U')dir=0;
        else if(c=='D')dir=1;
        else if(c=='L')dir=2;
        else if(c=='R')dir=3;

        int ty=y+dy[dir];
        int tx=x+dx[dir];
        if(ty<0||ty>=H||tx<0||tx>=W)return;
        if(fld[ty][tx]!=0)return;
        fld[y][x]=0;
        y=ty;x=tx;
        fld[y][x]=-1;
    }
    void Fire(){
        int ny=y,nx=x;
        while(true){
            ny+=dy[dir];
            nx+=dx[dir];
            if(ny<0||ny>=H||nx<0||nx>=W)break;
            if(fld[ny][nx]==0||fld[ny][nx]==3)continue;
            if(fld[ny][nx]==1){
                fld[ny][nx]=0;
                break;
            }
            if(fld[ny][nx]==2)break;
        }
    }
};

void solve(){
    State state;
    scanf("%d%d",&state.H,&state.W);
    rep(i,state.H){
        char str[36];
        scanf("%s",str);
        rep(j,state.W){
            if(str[j]=='.')state.fld[i][j]=0;
            else if(str[j]=='*')state.fld[i][j]=1;
            else if(str[j]=='#')state.fld[i][j]=2;
            else if(str[j]=='-')state.fld[i][j]=3;
            else{
                state.fld[i][j]=-1;
                state.y=i;state.x=j;
                if(str[j]=='^')state.dir=0;
                else if(str[j]=='v')state.dir=1;
                else if(str[j]=='<')state.dir=2;
                else if(str[j]=='>')state.dir=3;
            }
        }
    }

    int len;
    char opr[128];
    scanf("%d%s",&len,opr);

    rep(i,len){
        state.CTR(opr[i]);
    }


    char p[]="^v<>",o[]=".*#-";
    rep(i,state.H){
        rep(j,state.W){
            if(state.fld[i][j]==-1)printf("%c",p[state.dir]);
            else printf("%c",o[state.fld[i][j]]);
        }
        puts("");
    }
}

int main(){
    int N;
    scanf("%d",&N);
    bool flag=false;
    while(N--){
        if(flag)puts("");
        else flag=true;
        solve();
    }
}