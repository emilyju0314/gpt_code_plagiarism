#include<bits/stdc++.h>
typedef long long ll;
const int p=1e9+7;
int c[200010],w[200010],n,x,y;
int b[200010],f[200010],a,d;
int anc(int x){return f[x]?f[x]=anc(f[x]):x;}
void merge(int x,int y){if(anc(x)!=anc(y))f[anc(x)]=anc(y);}
int to[200010],nxt[200010],fst[200010],tot;
void add(int u,int v){to[++tot]=v,nxt[tot]=fst[u],fst[u]=tot;}
int inv[200010],r[200010],ans=1;
int main()
{
    scanf("%d%d%d",&n,&x,&y),w[0]=1e9;
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&c[i],&w[i]);
        if(w[b[c[i]]]>w[i])b[c[i]]=i;
        if(w[a]>w[i])a=i;
    }
    for(int i=1;i<=n;++i)
    {
        if(w[i]+w[b[c[i]]]<=x)merge(i,b[c[i]]);
        if(c[i]!=c[a]&&w[i]+w[a]<=y)merge(i,a);
        if(c[i]!=c[a]&&w[d]>w[i])d=i;
    }
    for(int i=1;i<=n;++i)
        if(c[i]==c[a]&&w[i]+w[d]<=y)merge(i,d);
    for(int i=1;i<=n;++i)add(anc(i),c[i]);
    inv[1]=1;
    for(int i=2;i<=n;++i)
        inv[i]=-(ll)p/i*inv[p%i]%p+p;
    for(int i=1;i<=n;++i)
    {
        for(int e=fst[i];e;e=nxt[e])
        {
            ans=(ll)ans*++r[0]%p;
            ans=(ll)ans*inv[++r[to[e]]]%p;
        }
        for(int e=fst[i];e;e=nxt[e])--r[0],--r[to[e]];
    }
    printf("%d\n",ans);
    return 0;
}
