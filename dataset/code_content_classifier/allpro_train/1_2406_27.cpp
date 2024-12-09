/*{{{*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(LL &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const LL &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
LL two[SIZE];
char s[12][12];
int col[12][12];
LL dp[11][11];
LL dp2[11][11];
int N,M;
LL C[11][11];
LL tmp[11][11];
int ng(int x){
    if(x&1)return 1;
    return -1;
}
LL f(int x,int y){
    if(!x||!y)return two[x+y];
    return 2;
}
void pre2(){
    REP(i,11)dp[0][i]=dp[i][0]=two[i];
    FOR(i,1,10)FOR(j,1,10){
        FOR(ii,0,i)FOR(jj,0,j){
            if(ii+jj==0)continue;
            ADD(dp[i][j],dp[i-ii][j-jj]*f(ii,jj)%MOD*C[i][ii]%MOD*C[j][jj]*ng(ii+jj));
        }
    }
}
void pre(){
    two[0]=1;
    REPP(i,1,SIZE)two[i]=two[i-1]*2%MOD;
    REP(i,11){
        C[i][0]=1;
        REPP(j,1,11){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if(C[i][j]>=MOD)C[i][j]-=MOD;
        }
    }
    pre2();
    /*
    FOR(i,0,10)FOR(j,0,10){
        dp[i][j]=calc(i,j);
    }
    */

    dp2[0][0]=1;
    REP(i,11)dp2[0][i]=dp2[i][0]=1;
    FOR(i,1,10)FOR(j,1,10){
        FOR(ii,0,i)FOR(jj,0,j){
            if(ii+jj==0)continue;
            ADD(dp2[i][j],dp2[i-ii][j-jj]*f(ii,jj)%MOD*C[i][ii]%MOD*C[j][jj]*ng(ii+jj));
        }
    }
}
VPII grid[20];
int cnt[20][2];
int ban[20];
LL an;
void dfs(int x,int n,int m){
    if(n>=N-1||m>=M-1)return;
    if(x==N+M){
        REP(i,N+M){
            if(ban[i])continue;
            if(!cnt[i][0]||!cnt[i][1])return;
        }
        ADD(an,dp[n][m]);
        return;
    }
    dfs(x+1,n,m);
    if(x<N){
        for(auto v:grid[x]){
            cnt[v.S+N][col[v.F][v.S]]--;
        }
    }
    else{
        for(auto v:grid[x]){
            cnt[v.F][col[v.F][v.S]]--;
        }
    }
    ban[x]=1;
    dfs(x+1,n+(x<N),m+(x>=N));
    ban[x]=0;
    if(x<N){
        for(auto v:grid[x]){
            cnt[v.S+N][col[v.F][v.S]]++;
        }
    }
    else{
        for(auto v:grid[x]){
            cnt[v.F][col[v.F][v.S]]++;
        }
    }
}
int main(){
    MOD=998244353;
    pre();
    R(N,M);
    REP(i,N)RS(s[i]);
    REP(i,N)REP(j,M){
        grid[i].PB({i,j});
        grid[j+N].PB({i,j});
        int cc=0;
        if(s[i][j]=='#')cc=1;
        col[i][j]=cc;
        cnt[i][cc]++;
        cnt[j+N][cc]++;
    }
    an=dp2[N][M];
    dfs(0,0,0);
    W(an);
    return 0;
}
