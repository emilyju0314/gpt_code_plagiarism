#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#ifdef LOCAL
void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp2(...) dmpr(cerr,__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif

using uint=unsigned;
using ull=unsigned long long;

template<class t,size_t n>
ostream& operator<<(ostream&os,const array<t,n>&a){
	return os<<vc<t>(all(a));
}

template<int i,class T>
void print_tuple(ostream&,const T&){
}

template<int i,class T,class H,class ...Args>
void print_tuple(ostream&os,const T&t){
	if(i)os<<",";
	os<<get<i>(t);
	print_tuple<i+1,T,Args...>(os,t);
}

template<class ...Args>
ostream& operator<<(ostream&os,const tuple<Args...>&t){
	os<<"{";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<"}";
}

template<class t>
void print(t x,int suc=1){
	cout<<x;
	if(suc==1)
		cout<<"\n";
	if(suc==2)
		cout<<" ";
}

ll read(){
	ll i;
	cin>>i;
	return i;
}

vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=read()+off;
	return v;
}

pi readpi(int off=0){
	int a,b;cin>>a>>b;
	return pi(a+off,b+off);
}

template<class t,class u>
void print(const pair<t,u>&p,int suc=1){
	print(p.a,2);
	print(p.b,suc);
}

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}

string readString(){
	string s;
	cin>>s;
	return s;
}

template<class T>
T sq(const T& t){
	return t*t;
}

//#define CAPITAL
void yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<"\n";
	#else
	cout<<"Yes"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<"\n";
	#else
	cout<<"Possible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<"\n";
	#else
	cout<<"Impossible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}

constexpr ll ten(int n){
	return n==0?1:ten(n-1)*10;
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}
ll mask(int i){
	return (ll(1)<<i)-1;
}

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll rand_int(ll l, ll r) { //[l, r]
	#ifdef LOCAL
	static mt19937_64 gen;
	#else
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
void myshuffle(vc<t>&a){
	rep(i,si(a))swap(a[i],a[rand_int(0,i)]);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

vvc<int> readGraph(int n,int m){
	vvc<int> g(n);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		//sc.read(a,b);
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return g;
}

vvc<int> readTree(int n){
	return readGraph(n,n-1);
}

int getval(){
	int a;cin>>a;
	if(a>0){
		return (a-1)*2;
	}else{
		return -a*2-1;
	}
}

int convval(int a){
	if(a%2==0)return a/2+1;
	else return -(a/2+1);
}

struct checker{
	vi buf;
	void add(int v){
		if(v%2==0){
			buf.pb(v/2);
		}else{
			assert(si(buf));
			assert(buf.back()==v/2);
			buf.pop_back();
		}
	}
};

void slv(){
	int n;cin>>n;
	vi up(2*n,-1),uppos(2*n,-1),lw(2*n,-1),lwpos(2*n,-1);
	vi nx(2*n,-1),lf(2*n),rt(2*n);
	rep(i,2*n){
		lf[i]=i;
		rt[i]=i;
	}
	set<pi> s;
	auto add=[&](int i,int j){
		assert(lf[i]==i);
		rt[i]=j;
		assert(rt[j]==j);
		lf[j]=i;
		if(up[i]%2==0&&lw[j]%2==1)
			s.emplace(i,j);
	};
	rep(i,2*n){
		int a=getval(),b=getval();
		up[i]=a;
		lw[i]=b;
		uppos[a]=i;
		lwpos[b]=i;
		add(i,i);
	}
	while(si(s)){
		auto itr=s.bg;
		auto [c,d]=*itr;
		s.erase(itr);
		int b=lwpos[lw[d]^1];
		int a=lf[b];
		int e=uppos[up[c]^1];
		int f=rt[e];
		if(a==e)no();
		dmp2(a,b,c,d,e,f);
		s.erase(pi(a,b));
		s.erase(pi(c,d));
		assert(nx[b]==-1);
		nx[b]=c;
		assert(nx[d]==-1);
		nx[d]=e;
		add(a,f);
	}
	vc<bool> rs(2*n,true);
	rep(i,2*n)if(nx[i]!=-1)rs[nx[i]]=false;
	map<pi,pi> buf;
	rep(i,2*n)if(rs[i]&&up[i]%2==0){
		int j=rt[i];
		assert(lw[j]%2==0);
		buf[pi(up[i]/2,lw[j]/2)]=pi(i,j);
	}
	rep(i,2*n)if(rs[i]&&up[i]%2==1){
		int j=rt[i];
		assert(lw[j]%2==1);
		pi p(up[i]/2,lw[j]/2);
		if(buf.count(p)){
			nx[buf[p].b]=i;
			rs[i]=false;
		}else{
			no();
		}
	}
	vc<pi> ans;
	rep(i,2*n)if(rs[i]){
		int x=i;
		while(x!=-1){
			ans.eb(up[x],lw[x]);
			x=nx[x];
		}
	}
	dmp(ans);
	assert(si(ans)==2*n);
	
	yes(0);
	for(auto [a,b]:ans){
		cout<<convval(a)<<" "<<convval(b)<<"\n";
	}
	
	checker upc,lwc;
	for(auto [a,b]:ans){
		upc.add(a);
		lwc.add(b);
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}
