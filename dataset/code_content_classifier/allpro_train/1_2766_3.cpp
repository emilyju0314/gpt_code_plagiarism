#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;

int n;
int a[100005], b[100005], c[100005], d[100005];
int dp[100005];

struct seg{int a,b,p,i;}st[200005];
bool cmp(seg a, seg b){return a.a < b.a;}

struct rmq{
    int lim, tree[530000];
    void init(int n){
        for(lim = 1; lim <= n; lim <<= 1);
    }
    void ins(int s, int v){
        s += lim;
        tree[s] = v;
        while(s>1){
            s >>= 1;
            tree[s] = max(tree[2*s],tree[2*s+1]);
        }
    }
    int q(int s, int e){
        s += lim;
        e += lim;
        int r = 0;
        while(s<e){
            if(s%2 == 1) r = max(r,tree[s++]);
            if(e%2 == 0) r = max(r,tree[e--]);
            s >>= 1;
            e >>= 1;
        }
        if(s == e) r = max(r,tree[s]);
        return r;
    }
}rmq;

void input(){
    vector<int> vu, vd;
    scanf("%d",&n);
    rmq.init(2*n);
    for (int i=0; i<n; i++) {
        scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
        vu.push_back(a[i]);
        vu.push_back(b[i]);
        vd.push_back(c[i]);
        vd.push_back(d[i]);
    }
    sort(vu.begin(),vu.end());
    sort(vd.begin(),vd.end());
    for (int i=0; i<n; i++) {
        a[i] = (int)(lower_bound(vu.begin(),vu.end(),a[i]) - vu.begin());
        b[i] = (int)(lower_bound(vu.begin(),vu.end(),b[i]) - vu.begin());
        c[i] = (int)(lower_bound(vd.begin(),vd.end(),c[i]) - vd.begin());
        d[i] = (int)(lower_bound(vd.begin(),vd.end(),d[i]) - vd.begin());
        st[2*i] = {a[i],c[i],0,i};
        st[2*i+1] = {b[i],d[i],1,i};
    }
    sort(st,st+2*n,cmp);
}

vector<pi> v;

int main(){
    input();
    for (int i=0; i<2*n; i++) {
        if(st[i].p == 0){
            dp[st[i].i] = rmq.q(0,st[i].b) + 1;
        }
        else{
            rmq.ins(st[i].b,dp[st[i].i]);
        }
    }
    int mcnt = *max_element(dp,dp+n);
    printf("%d\n",mcnt);
}