#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5,p=998244353,g=3,gv=(p+1)/3;
int n,m,rev[N];
ll fc[N],fv[N],iv[N],F[N],G[N],FF[N];
ll qpow(ll a,int b)
{ll ret=1;while(b){if(b&1)ret=ret*a%p;a=a*a%p;b>>=1;}return ret;}
ll inv(ll a){return qpow(a,p-2);}
void getrev(int len)
{for(int i=0;i<len;i++){rev[i]=rev[i>>1]>>1;if(i&1)rev[i]|=len>>1;}}
void ntt(ll *f,int len,int tp){
    getrev(len);
    for(int i=0;i<len;i++)if(i<rev[i])swap(f[i],f[rev[i]]);
    for(int i=2;i<=len;i<<=1){
        int stp=i>>1;ll wn=qpow(tp==1?g:gv,(p-1)/i);
        for(int j=0;j<len;j+=i){
            ll w=1;
            for(int k=j;k<j+stp;k++){
                ll s1=f[k],s2=f[k+stp]*w%p;w=w*wn%p;
                f[k]=(s1+s2)%p,f[k+stp]=(s1-s2+p)%p;
            }
        }
    }
    if(tp==-1){ll lv=inv(len);for(int i=0;i<len;i++)f[i]=f[i]*lv%p;}
}
int main(){
    scanf("%d",&n);
    m=1;F[1]=1;
    fc[0]=fc[1]=fv[0]=fv[1]=iv[1]=1;
    for(int i=2;i<=N-5;i++)fc[i]=fc[i-1]*i%p,
        iv[i]=(p-p/i)*iv[p%i]%p,fv[i]=fv[i-1]*iv[i]%p;
    for(int i=1;i<=n;i++){
        int a,b,m1=m;scanf("%d%d",&a,&b);m+=a-b;
        int len=1;while(len<=(m1*2+m+1))len<<=1;
        for(int j=-m1;j<=m;j++)
            if(b+j>=0&&a-j>=0)G[j+m1]=fv[b+j]*fv[a-j]%p;
            else G[j+m1]=0;
        for(int j=m+m1+1;j<len;j++)G[j]=0;
        for(int j=1;j<=m1;j++)FF[j]=F[j];FF[0]=0;
        for(int j=m1+1;j<len;j++)FF[j]=0;
        //for(int j=0;j<len;j++)cout<<G[j]<<" ";cout<<endl;
        //for(int j=0;j<len;j++)cout<<FF[j]<<" ";cout<<endl;cout<<endl;
        ntt(G,len,1),ntt(FF,len,1);
        for(int j=0;j<len;j++)F[j]=FF[j]*G[j]%p;
        ntt(F,len,-1);
        for(int j=1;j<=m;j++)F[j]=F[j+m1]*fc[a+b]%p;
        for(int j=m+1;j<len;j++)F[j]=0;F[0]=0;
        //for(int j=0;j<len;j++)cout<<F[j]<<" ";cout<<endl;cout<<endl;
    }
    ll ans=0;for(int i=1;i<=m;i++)ans=(ans+F[i])%p;
    printf("%lld\n",ans);

}
