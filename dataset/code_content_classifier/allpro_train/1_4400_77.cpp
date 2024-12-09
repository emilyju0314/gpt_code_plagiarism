#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
const int P=1e9+7,maxn=2e5+10;
int n,s[maxn],l[maxn],r[maxn],dp[maxn],tot,ans,fxk,j;
struct psc{int x,v,id;}a[maxn];
struct ask{int l,r;}b[maxn];
inline bool operator <(psc a,psc b){return a.v<b.v;}
inline bool cmp(psc a,psc b){return a.x<b.x;}
inline bool operator <(ask a,ask b){return a.l<b.l||a.l==b.l&&a.r<b.r;}
int main(){
    scanf("%d",&n);
    rep(i,1,n) scanf("%d%d",&a[i].x,&a[i].v);
    sort(a+1,a+n+1);
    rep(i,1,n) a[i].id=i;
    sort(a+1,a+n+1,cmp);fxk=n+1;
    per(i,n,1) fxk=min(fxk,a[i].id),l[a[i].id]=fxk;
    fxk=0;
    rep(i,1,n) fxk=max(fxk,a[i].id),r[a[i].id]=fxk;
    //rep(i,1,n) printf("%d %d\n",l[i],r[i]);
    rep(i,1,n) b[i].l=l[i],b[i].r=r[i];sort(b+1,b+n+1);
    dp[0]=tot=1;
    rep(i,1,n){
        while(j<i&&b[j].r+1<b[i].l) tot=(tot-dp[j]+P)%P,++j;
        dp[i]=tot;tot=(tot+dp[i])%P;
    }
    j=n;
    while(b[j].r==n) ans=(ans+dp[j])%P,--j;
    printf("%d\n",ans);
    return 0;
}