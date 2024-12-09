#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

/*
vector<vector<int>>??§??¨????????????????????§???
???????´???????mod=10^9+n??¨?????§?¨??????????
*/

const int mod=1000000007;
typedef vector<int>vec;
typedef vector<vec>mat;


int mod_pow(int n,int m){
    int ret=1;
    while(m){
        if(m&1)ret=ret*n%mod;
        n=n*n%mod;
        m>>=1;
    }
    return ret;
}

mat mul(const mat &A,const mat &B){
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<A.size();i++){
        for(int j=0;j<B[0].size();j++){
            for(int k=0;k<A[0].size();k++){
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%mod;
            }
        }
    }
    return C;
}

//??£?????????only
int det(mat A){
    int ret=1;
    for(int i=0;i<A.size();i++){
        int idx=-1;
        for(int j=i;j<A.size();j++)if(A[j][i]!=0)idx=j;
        if(idx==-1)return 0;
        if(i!=idx){
            ret=(mod-ret)%mod;
            swap(A[i],A[idx]);
        }
        ret=ret*A[i][i]%mod;
        int inv=mod_pow(A[i][i],mod-2);
        for(int j=0;j<A.size();j++)A[i][j]=A[i][j]*inv%mod;
        for(int j=i+1;j<A.size();j++){
            int a=A[j][i];
            for(int k=0;k<A.size();k++)A[j][k]=(A[j][k]-A[i][k]*a%mod+mod)%mod;
        }
    }
    return ret;
}

int MatrixTreeTheorem(vector<int>vs,vector<int>A,vector<int>B){
    if(vs.size()==1)return 1;

    sort(vs.begin(),vs.end());
    vs.erase(unique(vs.begin(),vs.end()),vs.end());
    for(int i=0;i<A.size();i++){
        A[i]=lower_bound(vs.begin(),vs.end(),A[i])-vs.begin();
        B[i]=lower_bound(vs.begin(),vs.end(),B[i])-vs.begin();
    }

    mat M(vs.size()-1,vec(vs.size()-1));
    for(int i=0;i<A.size();i++){
        if(A[i]+1!=vs.size())M[A[i]][A[i]]++;
        if(B[i]+1!=vs.size())M[B[i]][B[i]]++;
        if(A[i]+1!=vs.size()&&B[i]+1!=vs.size()){
            M[A[i]][B[i]]=mod-1;
            M[B[i]][A[i]]=mod-1;
        }
    }

    return det(M);
}


struct UF{
    vector<int>par,sz;
    void init(int n){
        par.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            sz[i]=1;
        }
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        sz[x]+=sz[y];
        par[y]=x;
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
    int size(int x){
        return sz[find(x)];
    }
};

signed main(){
    int N,M;cin>>N>>M;
    vector<tuple<int,int,int>>es;
    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        es.pb(make_tuple(c,a,b));
    }
    sort(all(es));
    UF uf;uf.init(N);
    int w;
    rep(i,M){
        int a,b,c;
        tie(c,a,b)=es[i];
        uf.unite(a,b);
        if(uf.size(0)==N){
            w=c;
            break;
        }
    }

    uf.init(N);
    rep(i,M){
        int a,b,c;
        tie(c,a,b)=es[i];
        if(c==w)break;
        uf.unite(a,b);
    }

    int rootid[100]={};
    int num=0;
    rep(i,N){
        if(uf.find(i)==i){
            rootid[i]=num++;
        }
    }
    rep(i,N){
        rootid[i]=rootid[uf.find(i)];
    }

    int ans=0;
    for(int i=0;i<(1<<num);i++){
        if(i==0||i==(1<<num)-1)continue;
        int tmp=1;
        for(int j=0;j<2;j++){
            vector<int>vs,A,B;
            for(int k=0;k<M;k++){
                int a,b,c;
                tie(c,a,b)=es[k];
                if((i>>rootid[a]&1)==j&&(i>>rootid[b]&1)==j){
                    A.pb(a);B.pb(b);
                }
            }
            for(int k=0;k<N;k++)if((i>>rootid[k]&1)==j)vs.push_back(k);
            tmp=tmp*MatrixTreeTheorem(vs,A,B)%mod;
        }
        ans=(ans+tmp)%mod;
    }

    cout<<w<<" "<<ans<<endl;
    return 0;
}