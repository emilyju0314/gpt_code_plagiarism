#include <bits/stdc++.h>
using namespace std;
const int dx[]={0,1,0,-1,1,-1,-1,1};
const int dy[]={-1,0,1,0,1,1,-1,-1};
const int dx2[] = {1,-1,-2,-2,-1,1,2,2};
const int dy2[] = {2,2,1,-1,-2,-2,-1,1};
const int INF = 1<<30;
const double EPS = 1e-8;
#define PB push_back
#define mk make_pair
#define fr first
#define sc second
#define ll long long
#define reps(i,j,k) for(int i = (j); i < (k); i++)
#define rep(i,j) reps(i,0,j)
#define MOD 1000000007
#define lengthof(x) (sizeof(x) / sizeof(*(x)))
typedef pair<int,int> Pii;
typedef pair<Pii,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
int T[128][128];
int W,H;
vector < Pii > target;
char stage[128][128];
P s,g;
int D[8][8];
int dp[1<<8][8];
struct data
{
    Pii p;
    int cost;
    data(){}
    data(Pii _p,int _cost){
        p = _p;
        cost = _cost;
    }
    bool operator<(const data &a)const{
        return a.cost < cost;
    }
};
void getPath(int a){
    int m[128][128];
    memset(m,-1,sizeof(m));    
    priority_queue < data > PQ;
    PQ.push(data(target[a],0));
    while(!PQ.empty()){
        data d = PQ.top();PQ.pop();
        if(m[d.p.fr][d.p.sc] != -1)continue;
        m[d.p.fr][d.p.sc] = d.cost;
        rep(i,4){
            int ny = d.p.fr + dy[i];
            int nx = d.p.sc + dx[i];
            if(ny < 0 || ny > H-1 || nx < 0 || nx > W-1)continue;
            if(m[ny][nx] != -1 || stage[ny][nx] == '#')continue;
            PQ.push(data(Pii(ny,nx),d.cost+T[d.p.fr][d.p.sc]));
        }
    }

    rep(i,target.size()){
        if(i == a)D[a][i] = 0;
        D[a][i] = m[target[i].fr][target[i].sc];
    }
    return ;
}
int getMin(int bit,int prev){
    if(dp[bit][prev] != -1)return dp[bit][prev];
    int ret = INF;
    rep(i,target.size()){
        if(i == g.sc)continue;
        if(!(1&(bit>>i))){
            ret = min(ret,D[prev][i]+getMin(bit|1<<i,i));
        }
    }
    if(ret == INF)ret = D[prev][g.sc];
    return dp[bit][prev] = ret;
}
int main(){
    scanf("%d%d",&W,&H);
    bool memo[128][128] = {{false}};
    fill((int*)T,(int*)(T+lengthof(T)),1);
    queue < P > Q;
    rep(i,H){
        scanf("%s",&stage[i]);
        rep(j,W){
            if(stage[i][j] == 'S'){
                s.fr.fr = i;
                s.fr.sc = j;
                s.sc = target.size();
                target.PB(Pii(i,j));
                stage[i][j] = '.';
            }
            if(stage[i][j] == 'G'){
                g.fr.fr = i;
                g.fr.sc = j;
                g.sc = target.size();
                target.PB(Pii(i,j));
                stage[i][j] = '.';
            }
            if(stage[i][j] == '#'){
                memo[i][j] = true;
                T[i][j] = 0;
                Q.push(P(Pii(i,j),3));
            }
            if(stage[i][j] == 'M'){
                target.PB(Pii(i,j));
            }
        }
    }
    while(!Q.empty()){
        P p = Q.front();Q.pop();
        if(p.sc == 1)continue;
        rep(i,8){
            int ny = p.fr.fr + dy[i]*(4-p.sc);
            int nx = p.fr.sc + dx[i]*(4-p.sc);
            if(ny < 0 || ny > H-1 || nx < 0 || nx > W-1)continue;
            if(memo[ny][nx]++)continue;
            T[ny][nx] = p.sc;
            Q.push(P(Pii(p.fr.fr,p.fr.sc),p.sc-1));
        }
        if(p.sc == 2){
            rep(i,8){
                int ny = p.fr.fr + dy2[i];
                int nx = p.fr.sc + dx2[i];
                if(ny < 0 || ny > H-1 || nx < 0 || nx > W-1)continue;
                if(memo[ny][nx]++)continue;
                T[ny][nx] = p.sc;
                Q.push(P(Pii(p.fr.fr,p.fr.sc),p.sc-1));       
            }
        }
    }
    rep(i,target.size()){
        getPath(i);
    }
    fill((int*)dp,(int*)(dp+lengthof(dp)),-1);
    printf("%d\n",getMin(1<<(s.sc),s.sc));
    return 0;
}