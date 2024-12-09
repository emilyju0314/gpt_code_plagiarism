#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 10005;

vector<int> G[MAX_N];
int kind[MAX_N];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	int t[3];
	cin >> n >> t[0] >> t[1] >> t[2];
	int mn[3];
	vi vec[3];
	rep(i,3){
		vec[i].resize(t[i]);
	}
	rep(i,n){
		kind[i] = -1;
	}
	rep(i,3){
		mn[i] = INF;
		rep(j,t[i]){
			cin >> vec[i][j];
			vec[i][j]--;
			kind[vec[i][j]] = i;
			cmn(mn[i],vec[i][j]);
		}
	}
	int m;
	cin >> m;
	rep(i,m){
		int a,b;
		cin >> a >> b;
		--a,--b;
		if(kind[a] >= 0){
			a = mn[kind[a]];
		}
		if(kind[b] >= 0){
			b = mn[kind[b]];
		}
		G[a].pb(b),G[b].pb(a);
	}
	vp d[3];
	rep(i,3){
		queue<int> que;
		d[i].resize(n,P(INF/10,INF/10));
		d[i][mn[i]] = P(0,mn[i]);
		que.push(mn[i]);
		while(!que.empty()){
			int p = que.front();
			que.pop();
			each(v,G[p]){
				if(d[i][p].fi+1 < d[i][v].fi){
					d[i][v] = P(d[i][p].fi+1,min(d[i][p].se,v));
					que.push(v);
				}else if(d[i][p].fi+1 == d[i][v].fi && d[i][v].se > d[i][p].se){
					d[i][v].se = d[i][p].se;
					que.push(v);
				}
			}
		}
	}
	P ans = P(INF,INF);
	rep(i,n){
		cmn(ans,P(d[0][i].fi+d[1][i].fi+d[2][i].fi,min({d[0][i].se,d[1][i].se,d[2][i].se})));
	}
	cout << ans.fi << " " << ans.se+1 << "\n";
	return 0;
}
