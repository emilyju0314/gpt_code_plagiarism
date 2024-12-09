#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
//#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

//永続segtree
#define sz (1<<17)
struct per_seg{
	vector<int>root;
	int L[20000005],R[20000005],id;
	int seg[20000005];
	void make(){
		for(int i=0;i<sz-1;i++) L[i] = i*2+1,R[i] = i*2+2;
		root.push_back(0); id = 2*sz;
	}
	int update(int a,int k,int l,int r){
		if(l==r){
			seg[id] = 1;
			return id++;
		}
		if(l<=a && a<=(l+r)/2){
			int x = update(a,L[k],l,(l+r)/2);
			seg[id] = (seg[x]+seg[R[k]]);
			L[id] = x; R[id] = R[k];
			return id++;
		}
		else{
			int x = update(a,R[k],(l+r)/2+1,r);
			seg[id] = (seg[L[k]]+seg[x]);
			L[id] = L[k]; R[id] = x;
			return id++;
		}
	}
	void update(int pos){
		int R = root.back();
		int nw = update(pos,R,0,sz-1);
		root.push_back(nw);
	}
	pair<int,ll> query(vector<int>k,int l,int r,ll zan){
		if(l == r) return mp(l,zan);
        ll sum = 0;
        rep(x,k.size()) sum += seg[L[k[x]]];
        if(sum >= zan) {
            rep(x,k.size()) k[x] = L[k[x]];
            return query(k,l,(l+r)/2,zan);
        }
        else{
            rep(x,k.size()) k[x] = R[k[x]];
            return query(k,1+(l+r)/2,r,zan-sum);
        }
	}
    pair<int,ll> query(vector<int>ver,ll zan){
        rep(i,ver.size()) ver[i] = root[ver[i]];
		return query(ver,0,sz-1,zan);
	}
}kaede;


int n,m,q;
ll a[100005],b[100005],sum[100005];
ll ten[19];
ll rui[100005];
vector<pair<ll,int>>query,query2;
vector<pair<ll,int>>solve[100005];
int ans[300005];
int calc_digit(int i,int j,int x){
    ll V = a[i]*b[j]; //cout << V << " " << x << endl;
    vector<int>vi;
    while(V){vi.pb(V%10);V/=10;}
    reverse(vi.begin(),vi.end());
    assert(vi.size() >= x);
    return vi[x-1];
}
int main(){
    scanf("%d%d",&n,&m);
    repn(i,n) {sum[i] = m; scanf("%lld",&a[i]);}
    repn(j,m) scanf("%lld",&b[j]);
    ten[0] = 1;
    for(int i=1;i<=18;i++) ten[i] = ten[i-1]*10LL;
    repn(i,n){
        repn(j,18){
            ll dv = (ten[j]+a[i]-1)/a[i];
            query.pb(mp(dv,-i));
        }
    }
    repn(j,m) query.pb(mp(b[j],1));
    repn(j,m) query2.pb(mp(-b[j],j)); 
    SORT(query); reverse(query.begin(),query.end());
    SORT(query2); 

    int cur = 0;
    rep(i,query.size()){
        if(query[i].sc == 1) cur++;
        else sum[-query[i].sc]+=cur;
    }
    //repn(i,n) cout << sum[i] << endl;
    repn(i,n) rui[i] = rui[i-1]+sum[i];
    scanf("%d",&q);
    repn(i,q){
        ll x; scanf("%lld",&x);
        //rui[i] >= x min i
        if(rui[n] < x) { ans[i ]= -1; continue;}
        int xx = lower_bound(rui+1,rui+n+1,x)-rui;
        solve[xx].pb(mp(x-rui[xx-1],i));
        //cout << xx << " " << x-rui[xx-1] << " " << i << endl;
    }
    kaede.make();
    rep(i,query2.size()){
        kaede.update(query2[i].sc);
    }
    repn(i,n){
        vector<int>rt;
        for(int j=0;j<=18;j++){
            ll dv = (ten[j]+a[i]-1)/a[i];
            //dv以上の値を追加したときの永続segtreeのトップを求める
            int a = lower_bound(query2.begin(),query2.end(),mp(-dv,INF))-query2.begin();
            rt.pb(a); //if(i == 2) cout << a << " ";
        }
        //19個のsegtreeで上から舐める
        rep(j,solve[i].size()){
            pair<int,ll>ret = kaede.query(rt,solve[i][j].fi);
            //cout << i << ret.fi << ret.sc << endl;
            ans[solve[i][j].sc] = calc_digit(i,ret.fi,ret.sc);
        }
    }
    repn(i,q){
        if(ans[i] == -1) printf("x");
        else printf("%d",ans[i]);
    }
    puts("");
    return 0;
}
