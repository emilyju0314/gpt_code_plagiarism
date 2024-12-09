#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second

typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N;

int C[1<<22];
int O[1<<22];
bool ex[1<<22];

short cnt[1<<22][22];

signed main(){
    scanf("%lld",&N);
    rep(i,N){
        int x=0;
        int k;scanf("%lld",&k);
        while(k--){
            int a;scanf("%lld",&a);
            a--;
            x^=1<<a;
        }
        cnt[x][0]++;
        O[x]=x;
    }

    for(int i=1<<22;i>=0;i--){
        for(int j=0;j<22;j++){
            if(i>>j&1)O[i^(1<<j)]|=O[i];
        }
    }

    int ans=0;

    for(int i=1<<22;i>=0;i--){
        for(int j=0;j<22;j++){
            if(i>>j&1){
                cnt[i^(1<<j)][j]+=cnt[i][j];
            }
            if(j!=21)cnt[i][j+1]+=cnt[i][j];
        }
        if(cnt[i][21]>=3)chmax(ans,__builtin_popcount(i)*__builtin_popcount(O[i]));
    }
    cout<<ans<<endl;
}