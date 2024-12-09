#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int UKU=LLONG_MAX/2;
const int INF=1001001001001001001ll;

int N,F;
int X[10][10];

int M[1<<8][1<<8][8];
int m[1<<8][1<<8][8];
int dp[1<<8][1<<8][8];
int calcM(int b,int bb,int pr,int t){
    int &ret=M[b][bb][pr];
    if(ret!=UKU)return ret;
    ret=-INF;
    if(t==2*N+1){
        ret=0;
    }
    else if(t&1){
        rep(i,N){
            if(b>>i&1)continue;
            int tmp=calcM(b|(1<<i),bb,i,t+1);
            if(t!=1)tmp+=X[i][pr];
            chmax(ret,tmp);
        }
    }
    else{
        rep(i,N){
            if(bb>>i&1)continue;
            int tmp=calcM(b,bb|(1<<i),i,t+1);
            tmp-=X[pr][i];
            chmax(ret,tmp);
        }
    }
    return ret;
}

int calcm(int b,int bb,int pr,int t){
    int &ret=m[b][bb][pr];
    if(ret!=UKU)return ret;
    ret=INF;
    if(t==2*N+1){
        ret=0;
    }
    else if(t&1){
        rep(i,N){
            if(b>>i&1)continue;
            int tmp=calcm(b|(1<<i),bb,i,t+1);
            if(t!=1)tmp+=X[i][pr];
            chmin(ret,tmp);
        }
    }
    else{
        rep(i,N){
            if(bb>>i&1)continue;
            int tmp=calcm(b,bb|(1<<i),i,t+1);
            tmp-=X[pr][i];
            chmin(ret,tmp);
        }
    }
    return ret;
}


int calcdp(int b,int bb,int pr,int t){
    int &ret=dp[b][bb][pr];
    if(ret!=UKU)return ret;
    if(t==2*N+1){
        ret=0;
    }
    else if(t&1){
        ret=-INF;
        rep(i,N){
            if(b>>i&1)continue;
            int tmp=calcdp(b|(1<<i),bb,i,t+1);
            if(t!=1)tmp+=X[i][pr];
            chmax(ret,tmp);
        }
    }
    else{
        ret=INF;
        rep(i,N){
            if(bb>>i&1)continue;
            int tmp=calcdp(b,bb|(1<<i),i,t+1);
            tmp-=X[pr][i];
            chmin(ret,tmp);
        }
    }
    return ret;
}

int ei[1<<8][1<<8][8];

int latte(int b,int bb,int pr,int t,int tx){
    if(t==tx){
        if(tx&1)return -M[b][bb][pr];
        return -m[b][bb][pr];
    }
    int &ret=ei[b][bb][pr];
    if(ret!=UKU)return ret;

    if(t&1){
        ret=INF;
        rep(i,N){
            if(b>>i&1)continue;
            int tmp=latte(b|(1<<i),bb,i,t+1,tx);
            if(t!=1)tmp-=X[i][pr];
            chmin(ret,tmp);
        }
    }
    else{
        ret=-INF;
        rep(i,N){
            if(bb>>i&1)continue;
            int tmp=latte(b,bb|(1<<i),i,t+1,tx);
            tmp+=X[pr][i];
            chmax(ret,tmp);
        }
    }
    return ret;
}


signed main(){
    N=8;F=0;
    cin>>N>>F;
    rep(i,N)rep(j,N)cin>>X[i][j];

    fill_n(**M,(1<<8)*(1<<8)*8,UKU);
    fill_n(**m,(1<<8)*(1<<8)*8,UKU);
    fill_n(**dp,(1<<8)*(1<<8)*8,UKU);

    calcM(0,0,0,1);
    calcm(0,0,0,1);
    calcdp(0,0,0,1);

    if(dp[0][0][0]+F==0){
        cout<<"Draw"<<endl;
        cout<<2*N<<endl;
        return 0;
    }

    if(dp[0][0][0]+F>0){
        cout<<"First"<<endl;
        for(int i=2;i<=2*N;i+=2){
            fill_n(**ei,(1<<8)*(1<<8)*8,UKU);
            if(latte(0,0,0,1,i)<F){
                cout<<i<<endl;
                return 0;
            }
        }
    }
    else{
        cout<<"Second"<<endl;
        for(int i=1;i<=2*N;i+=2){
            fill_n(**ei,(1<<8)*(1<<8)*8,UKU);
            if(latte(0,0,0,1,i)>F){
                cout<<i<<endl;
                return 0;
            }
        }
    }

    return 0;
}

