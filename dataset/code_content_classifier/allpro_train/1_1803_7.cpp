#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=1010;
int n,a[N],s;
VI d;
PII cmp(PII a,PII b) {
	if (a.fi==b.fi) return mp(0,a.se<b.se?1:-1);
	else if (a.se==b.se) return mp(a.fi<b.fi?1:-1,0);
	else assert(0);
}
vector<PII> generate(VI x) {
	if (SZ(x)==4) {
		return vector<PII>{mp(0,0),mp(1,0),mp(1,1),mp(0,1)};
	} else {
		int m=SZ(x),p=-1;
		vector<PII> c,cc;
		rep(i,0,m) if (x[i]==90&&x[(i+1)%m]==270&&x[(i+2)%m]==90) {
			VI y; rep(j,0,m-2) y.pb(x[(i+2+j)%m]);
			c=generate(y);
			p=i; break;
		}
		if (p>=0) {
			for (auto &q:c) q.fi*=2,q.se*=2;
			PII v=c[0];
			PII d1=cmp(c[0],c[m-3]),d2=cmp(c[0],c[1]);
			c.insert(c.begin(),v);
			c.insert(c.begin(),v);
			c[0].fi+=d1.fi; c[0].se+=d1.se;
			c[1].fi+=d1.fi+d2.fi; c[1].se+=d1.se+d2.se;
			c[2].fi+=d2.fi; c[2].se+=d2.se;
			d.clear();
			for (auto q:c) d.pb(q.fi); sort(all(d)); d.erase(unique(all(d)),d.end()); for (auto &q:c) q.fi=lower_bound(all(d),q.fi)-d.begin();
			d.clear();
			for (auto q:c) d.pb(q.se); sort(all(d)); d.erase(unique(all(d)),d.end()); for (auto &q:c) q.se=lower_bound(all(d),q.se)-d.begin();
			rep(j,0,m) cc.pb(c[(m-p+j)%m]);
//			for (auto p:x) printf("%d ",p); puts("");
//			for (auto p:cc) printf("%d %d\n",p.fi,p.se); puts("");
			return cc;
		}
		rep(i,0,m) if (x[i]==90&&x[(i+1)%m]==270&&x[(i+2)%m]==270) {
			VI y; rep(j,0,m-2) y.pb(x[(i+2+j)%m]);
			c=generate(y);
			p=i; break;
		}
		if (p>=0) {
			for (auto &q:c) q.fi*=2,q.se*=2;
			PII v=c[0];
			PII d1=cmp(c[0],c[m-3]),d2=cmp(c[1],c[0]);
			c.insert(c.begin(),v);
			c.insert(c.begin(),v);
			c[0].fi+=d1.fi; c[0].se+=d1.se;
			c[1].fi+=d1.fi+d2.fi; c[1].se+=d1.se+d2.se;
			c[2].fi+=d2.fi; c[2].se+=d2.se;
			d.clear();
			for (auto q:c) d.pb(q.fi); sort(all(d)); d.erase(unique(all(d)),d.end()); for (auto &q:c) q.fi=lower_bound(all(d),q.fi)-d.begin();
			d.clear();
			for (auto q:c) d.pb(q.se); sort(all(d)); d.erase(unique(all(d)),d.end()); for (auto &q:c) q.se=lower_bound(all(d),q.se)-d.begin();
			rep(j,0,m) cc.pb(c[(m-p+j)%m]);
//			for (auto p:x) printf("%d ",p); puts("");
//			for (auto p:cc) printf("%d %d\n",p.fi,p.se); puts("");
			return cc;
		}
		assert(0);
	}
}
int main() {
	scanf("%d",&n);
/*	n=10;
	rep(i,0,n/2+2) a[i]=90;
	rep(i,n/2+2,n) a[i]=270;
	random_shuffle(a,a+n);*/
	rep(i,0,n) {
		scanf("%d",a+i);
//		printf("%d ",a[i]);
		s+=a[i];
	}
	puts("");
	if (s!=180*(n-2)) {
		puts("-1");
		return 0;
	}
	vector<PII> c=generate(VI(a,a+n));
	for (auto p:c) printf("%d %d\n",p.fi,p.se);
}
