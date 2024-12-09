
#include <iostream>
#include <string.h>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

int n,k,l,p,q;
int dsu[2][200010];
map<PII,ll> cnt;

int fi(int x,int idx) {
    return dsu[idx][x]==x?x:(dsu[idx][x]=fi(dsu[idx][x],idx));
}

int main() {
    scanf("%d%d%d",&n,&k,&l);
    memset(dsu,0,sizeof(dsu));
    for (int i=1;i<=n;i++) {
        dsu[0][i]=dsu[1][i]=i;
    }
    for (int i=0;i<k;i++) {
        scanf("%d%d",&p,&q);
        dsu[0][fi(p,0)]=fi(q,0);
    }
    for (int i=0;i<l;i++) {
        scanf("%d%d",&p,&q);
        dsu[1][fi(p,1)]=fi(q,1);
    }
    for (int i=1;i<=n;i++) {
        cnt[mp(fi(i,0),fi(i,1))]++;
    }
    for (int i=1;i<=n;i++) {
        printf("%lld ",cnt[mp(fi(i,0),fi(i,1))]);
    }
    printf("\n");
}