#include <bits/stdc++.h>
using namespace std;

using ll=long long;
//#define int ll

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
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

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
#define dmp2(...) dmpr(cerr,"Line:",__LINE__,##__VA_ARGS__)
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

void print(ll x,int suc=1){
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
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
	#endif
	if(ex)exit(0);
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<endl;
	#else
	cout<<"Possible"<<endl;
	#endif
	if(ex)exit(0);
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<endl;
	#else
	cout<<"Impossible"<<endl;
	#endif
	if(ex)exit(0);
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
int mask(int i){
	return (int(1)<<i)-1;
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
    static random_device rd;
    static mt19937_64 gen(rd());
    #endif
    return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

void* dbg_ptr;

//JOISC2013 day4 Spaceships
//TTPC2019 M
//AOJ2450
//XX Open Cup GP of Kazan J

template<class N>
struct toptree{
	struct Node{
		static Node* dbg_buf;
		using np=Node*;
		struct {np p,l,r;} r,c;
		//c.p==0 のときのみ r,rake が意味を持つ．
		np par,mid;
		bool rev;
		int a,b,ra,rb;
		N rake,cmp,raw;
		bool is_root(){
			return c.p==0&&r.p==0&&par==0;
		}
		template<class...Args>
		void init(int aa,int bb,Args&&...args){
			r={0,0,0};
			c={0,0,0};
			par=0;
			mid=0;
			rev=0;
			a=ra=aa;
			b=rb=bb;
			raw.init(a,b,forward<Args>(args)...);
			rake=cmp=raw;
		}
		void reverse(){
			rev^=1;
			cmp.reverse(a,b);
			swap(a,b);
			raw.reverse(ra,rb);
			swap(ra,rb);
			swap(c.l,c.r);
		}
		void push_rake(np x){
			assert(c.p==0);
			if(x){
				assert(x->c.p==0);
				assert(x->r.p==this);
				assert(a==x->a);
				rake.push_rake(a,b,x->b,x->rake);
			}
		}
		void push_cmp(np x){
			if(x){
				assert(x->c.p==this);
				if(rev)
					x->reverse();
				cmp.push_cmp(a,b,x->a,x->b,x->cmp);
			}
		}
		void propagate(){
			//rake
			if(c.p==0){
				push_rake(r.l);
				push_rake(r.r);
				rake.push_cmp(a,b,a,b,cmp);
				rake.clear();
			}
			//cmp
			push_cmp(c.l);
			push_cmp(c.r);
			cmp.push_cmp(a,b,ra,rb,raw);
			if(mid){
				assert(ra==rb);
				assert(mid->c.p==0);
				assert(mid->r.p==0);
				assert(mid->par==this);
				cmp.push_mid(a,b,mid->a,mid->b,mid->rake);
			}
			rev=0;
			cmp.clear();
		}
		//current node doesn't have any rake links
		//involved nodes are NOT updated
		void swap_rake(np x){
			assert(x->c.p==0);
			swap(r,x->r);
			if(r.p){
				if(r.p->r.l==x)r.p->r.l=this;
				if(r.p->r.r==x)r.p->r.r=this;
			}
			if(r.l)
				r.l->r.p=this;
			if(r.r)
				r.r->r.p=this;
			if(r.p==0){
				swap(par,x->par);
				if(par)par->mid=this;
			}
		}
		void update_cmp(){
			cmp=raw.clone();
			
			a=ra,b=rb;
			if(mid){
				assert(mid->c.p==0);
				assert(mid->r.p==0);
				assert(mid->a==a);
				assert(mid->par=this);
				cmp=N::rake(a,b,mid->b,cmp,mid->rake);
			}
			if(c.r){
				assert(c.r->a==b);
				assert(c.r->c.p==this);
				cmp=N::compress(a,b,c.r->b,cmp,c.r->cmp);
				b=c.r->b;
			}
			if(c.l){
				assert(c.l->b==a);
				assert(c.l->c.p==this);
				cmp=N::compress(c.l->a,a,b,c.l->cmp,cmp);
				a=c.l->a;
			}
		}
		int pos_cmp(){
			if(c.p&&c.p->c.l==this)return -1;
			if(c.p&&c.p->c.r==this)return 1;
			return 0;
		}
		void rotate_cmp(){
			np q=c.p,w;
			if(q->c.p==0)
				swap_rake(q);
			if(pos_cmp()==1){
				w=c.l;
				c.l=c.p;
				c.p->c.r=w;
			}else{
				w=c.r;
				c.r=c.p;
				c.p->c.l=w;
			}
			if(w) w->c.p=c.p;
			c.p=c.p->c.p;
			q->c.p=this;
			if(c.p&&c.p->c.l==q)c.p->c.l=this;
			if(c.p&&c.p->c.r==q)c.p->c.r=this;
			q->update_cmp();
		}
		void splay_cmp(){
			while(c.p){
				int x=pos_cmp(),y=c.p->pos_cmp();
				if(y&&x==y)c.p->rotate_cmp();
				if(y&&x!=y)rotate_cmp();
				rotate_cmp();
			}
			update_cmp();
		}
		void update_rake(){
			rake=cmp.clone();
			auto sub=[&](np x){
				if(x==0)return;
				assert(x->c.p==0);
				assert(x->a==a);
				assert(x->r.p==this);
				rake=N::rake(a,b,x->b,rake,x->rake);
			};
			sub(r.l);
			sub(r.r);
		}
		int pos_rake(){
			assert(c.p==0);
			if(r.p&&r.p->r.l==this) return -1;
			if(r.p&&r.p->r.r==this) return 1;
			return 0;
		}
		void rotate_rake(){
			np q=r.p,w;
			if(q->r.p==0){
				swap(par,q->par);
				if(par)par->mid=this;
			}
			if(pos_rake()==1){
				w=r.l;
				r.l=r.p;
				r.p->r.r=w;
			}else{
				w=r.r;
				r.r=r.p;
				r.p->r.l=w;
			}
			if(w) w->r.p=r.p;
			r.p=r.p->r.p;
			q->r.p=this;
			if(r.p&&r.p->r.l==q)r.p->r.l=this;
			if(r.p&&r.p->r.r==q)r.p->r.r=this;
			q->update_rake();
		}
		void splay_rake(){
			while(r.p){
				int x=pos_rake(),y=r.p->pos_rake();
				if(y&&x==y)r.p->rotate_rake();
				if(y&&x!=y)rotate_rake();
				rotate_rake();
			}
			update_rake();
		}
		void prepare(){
			if(c.p){
				assert(r.p==0);
				assert(par==0);
				c.p->prepare();
			}
			else if(r.p){
				assert(par==0);
				r.p->prepare();
			}
			else if(par){
				par->prepare();
			}
			propagate();
		}
		static np merge_rake(np x,np y){
			if(x==0)return y;
			if(y==0)return x;
			while(y->r.l){
				y->propagate();
				y=y->r.l;
			}
			y->propagate();
			y->splay_rake();
			y->r.l=x;
			x->r.p=y;
			y->update_rake();
			return y;
		}
		void expose(){
			prepare();
			for(np x=this;x;x=x->par){
				x->splay_cmp();
				x->splay_rake();
			}
			for(np x=this;x->par;){
				np p=x->par;
				x->par=0;
				assert(p->mid=x);
				np y=p->c.r;
				if(y){
					y->c.p=0;
					y->update_rake();
				}
				np z=x->r.l,w=x->r.r;
				if(z){
					z->r.p=0;
					x->r.l=0;
				}
				if(w){
					w->r.p=0;
					x->r.r=0;
				}
				z=merge_rake(z,w);
				z=merge_rake(z,y);
				p->mid=z;
				if(z)z->par=p;
				p->c.r=x;
				x->c.p=p;
				x=p;
			}
			splay_cmp();
			/*if(!is_root()){
				Node* dbg_buf=(Node*)dbg_ptr;
				cerr<<this-dbg_buf<<" "<<c.p-dbg_buf<<" "<<r.p-dbg_buf<<" "<<par-dbg_buf<<endl;
			}*/
			assert(is_root());
		}
		void merge_mid(np x){
			if(mid)
				mid->par=0;
			mid=merge_rake(mid,x);
			if(mid)
				mid->par=this;
			update_cmp();
		}
		void evert(){
			expose();
			np x=c.l;
			if(x==0)return;
			x->c.p=0;
			c.l=0;
			x->reverse();
			x->update_rake();
			merge_mid(x);
		}
		void link_sub(np x,np y){
			assert(is_root());
			assert(x->is_root());
			assert(c.l==0);
			assert(y);
			y->c.p=this;
			c.l=y;
			update_cmp();
			update_rake();
			x->merge_mid(this);
		}
		//this should be an edge node!!
		void cut_sub(){
			expose();
			assert(ra!=rb);
			assert(c.l);
			assert(c.r);
			assert(mid==0);
			c.l->c.p=0;
			c.r->c.p=0;
		}
	} *x;
	using np=Node*;
	int n;
	vc<np> buf;
	toptree(int nn):n(nn){
		x=new Node[2*n];
		rep(i,n)x[i].init(i,i);
		rep(i,n)buf.pb(x+n+i);
		
		dbg_ptr=(void*)x;
	}
	~toptree(){delete[] x;}
	np evert(int a){
		x[a].evert();
		return x+a;
	}
	np expose_path(int aa,int bb){
		np a=x+aa,b=x+bb;
		a->evert();
		if(a!=b){
			b->expose();
			if(a->is_root())return 0;
		}
		np y=b->c.r;
		if(y){
			y->c.p=0;
			b->c.r=0;
			y->update_rake();
			b->merge_mid(y);
		}
		return b;
	}
	//a<-b
	template<class...Args>
	np link(int aa,int bb,Args&&...args){
		np a=x+aa,b=x+bb;
		a->expose();
		b->evert();
		if(a->is_root()){
			np y=buf.back();buf.pop_back();
			y->init(aa,bb,forward<Args>(args)...);
			b->link_sub(a,y);
			return y;
		}else
			return 0;
	}
	void cut(np y){
		assert(y-x>=n);
		assert(y-x<2*n);
		y->cut_sub();
		buf.pb(y);
	}
	void cutpar(int aa){
		assert(0<=aa&&aa<n);
		np a=x+aa;
		a->expose();
		a=a->c.l;
		assert(a);
		while(a->c.r)a=a->c.r;
		assert(a-x>=n);
		cut(a);
	}
	int lca(int aa,int bb){
		np a=x+aa,b=x+bb;
		a->expose();
		b->expose();
		if(a->is_root())
			return -1;
		int c=-2;
		np d=a;
		while(a!=b){
			if(a->c.p){
				assert(a->r.p==0);
				assert(a->par==0);
				c=a->pos_cmp();
				a=a->c.p;
			}else if(a->r.p){
				assert(a->par==0);
				a=a->r.p;
			}else if(a->par){
				a=a->par;
				d=a;
			}else{
				//cerr<<a-x<<" "<<b-x<<endl;
				assert(false);
			}
		}
		a->expose();
		if(c==1)return b-x;
		return d-x;
	}
};

//push_rake(a,b,cb,c): propagate to a rake child c
//push_cmp(a,b,ca,cb,c): propagate to c, whose path (ca,cb) is a subsegment of (a,b)
//push_mid(a,b,ca,cb,c): propagate to a middle child c
//reverse(a,b): reverse the node
//clear(): clear the lazy tag
//clone(): return a cloned node
//compress(a,m,b,x,y): returns the compressed node xy
//rake(a,b,c,x,y): rake y(a,c) to x(a,b)
//nodes are edge-based, and vertex nodes are identitiy nodes
//note that there exists a non-identity node with 0-length path
//expose をして np->cmp を見るのが基本
//np->a,np->b を見る
//特に evert の時は np->b が重要
//expose_path(a,b) で a が親になる，つまり，Node の端点が a,b となる．(自然)

//empty path に対応するノード，まあ単位元とかだと思ってください(意外とここを適当にやると壊れたり)
//lazy tag をくっつける時は，puttag みたいな関数を使うのが定石

const int nmax=100010;
bool f[nmax];

struct N{
	bool con;
	int w[2],z;
	//void init(int a,int b){
	void init(int,int){
		con=true;
		w[0]=w[1]=0;
		z=0;
	}
	//void push_rake(int a,int b,int cb,N&x){
	void push_rake(int,int,int,N&){
	}
	//void push_cmp(int a,int b,int ca,int cb,N&x){
	void push_cmp(int,int,int,int,N&){
	}
	//void push_mid(int a,int b,int ca,int cb,N&x){
	void push_mid(int,int,int,int,N&){
	}
	//void reverse(int a,int b){
	void reverse(int,int){
		swap(w[0],w[1]);
	}
	void clear(){
	}
	N clone()const{
		return *this;
	}
	static const int ta=0,tb=4;
	static N compress(int a,int m,int b,N x,N y){
		assert(a!=b);
		
		
		if(a==m&&m==b){
			N res;
			res.w[0]=res.w[1]=x.w[0]+y.w[0];
			res.con=true;
			res.z=0;
		if((a==ta&&b==tb)||(a==tb&&b==ta)){
			dmp2(a,m,b);
			dmp(x);
			dmp(y);
			dmp(res);
		}
		
			return res;
		}else if(a==m){
			N res=y;
			res.w[0]+=x.w[0];
			assert(x.w[0]==x.w[1]);
		if((a==ta&&b==tb)||(a==tb&&b==ta)){
			dmp2(a,m,b);
			dmp(x);
			dmp(y);
			dmp(res);
		}
		
			return res;
		}else if(m==b){
			N res=x;
			res.w[1]+=y.w[1];
			assert(y.w[0]==y.w[1]);
		if((a==ta&&b==tb)||(a==tb&&b==ta)){
			dmp2(a,m,b);
			dmp(x);
			dmp(y);
			dmp(res);
		}
		
			return res;
		}
		N res;
		res.w[0]=x.w[0];
		if(x.con&&f[m])
			res.w[0]+=1+x.w[1]-x.z+y.w[0];
		res.w[1]=y.w[1];
		if(y.con&&f[m])
			res.w[1]+=1+y.w[0]-y.z+x.w[1];
		res.con=x.con&&y.con&&f[m];
		if(res.con)
			res.z=1+x.w[1]+y.w[0];
		else
			res.z=0;
		
		if((a==ta&&b==tb)||(a==tb&&b==ta)){
			dmp2(a,m,b);
			dmp(x);
			dmp(y);
			dmp(res);
		}
		
		return res;
	}
	int fromleft(int a,int b)const{
		int res=w[0];
		if(a!=b&&con&&f[b]){
			res+=w[1]+1-z;
		}
		return res;
	}
	static N rake(int a,int b,int cb,const N&x,const N&y){
		assert(a!=cb);
		N res=x;
		res.w[0]+=y.fromleft(a,cb);
		if(a==b)res.w[1]=res.w[0];
		if(res.w[0]==10){
			dmp2(a,b,cb);
			dmp(x);
			dmp(y);
		}
		if((a==ta&&b==tb)||(a==tb&&b==ta)){
			dmp2(a,b,cb);
			dmp(x);
			dmp(y);
			dmp(res);
		}
		
		return res;
	}
	int getans(int a,int b){
		assert(f[a]);
		return fromleft(a,b)+1;
	}
	friend ostream&operator<<(ostream&os,const N&x){
		return os<<x.con<<" "<<x.w[0]<<" "<<x.w[1]<<" "<<x.z;
	}
};


vi g[nmax];

int dfs(int v,int p){
	int res=1;
	for(auto to:g[v])if(to!=p&&f[to]){
		res+=dfs(to,v);
	}
	return res;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,q;cin>>n>>q;
	bool dbg=n<0;
	if(dbg){
		n=-n;
	}
	rep(i,n)f[i]=1;
	toptree<N> tree(n);
	rep(_,n-1){
		int a,b;
		if(dbg){
			a=rand_int(0,_);
			b=_+1;
		}else{
			cin>>a>>b;
			a--;b--;
		}
		//cerr<<a+1<<" "<<b+1<<endl;
		tree.link(a,b);
		
		g[a].pb(b);
		g[b].pb(a);
	}
	rep(_,q){
		int t,v;
		if(dbg){
			v=rand_int(0,n-1);
			if(f[v])
				t=rand_int(1,2);
			else
				t=1;
		}else{
			cin>>t>>v;
			v--;
		}
		//cerr<<t<<" "<<v+1<<endl;
		auto np=tree.evert(v);
		if(t==1){
			f[v]^=1;
		}else{
			dmp2(v,np->a,np->b);
			assert(np->a==v);
			int w=np->cmp.getans(np->a,np->b);
			//int tmp=dfs(v,-1);
			//dmp2(w,tmp);
			//assert(w==tmp);
			print(w);
		}
	}
}

