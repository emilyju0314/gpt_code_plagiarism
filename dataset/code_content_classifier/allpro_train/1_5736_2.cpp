// PRAGMAS
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

// INCLUDES
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;

// DEFINES
// #define int               long long
#define mp                make_pair
#define pb                push_back
#define eb                emplace_back
#define ins               insert
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define inparr(x,n)       for(int _i = 0; _i < (n); ++_i)cin>>(x)[_i];
#define popcnt            __builtin_popcountll
#define elasped_time      1.0 * clock() / CLOCKS_PER_SEC 

// TYPEDEFS
using ll = long long;
using str = string;
using pii = pair<int,int>;
using vi = vector<int>;
using vii = vector<pii>;
using vvi = vector<vi>;
template<class T> using vec = vector<T>;

// I/O
void setPrec(int prec) { cout << fixed << setprecision(prec); }
void unsyncIO() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }

// INPUT
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}

template<class T, class U> void read(pair<T,U>& p);
template<class T> void read(vector<T>& v);

template<class T> void read(T& x) { cin >> x; }
void read(double& d) { str t; read(t); d = stod(t); }
void read(long double& d) { str t; read(t); d = stold(t); }
template<class T, class ...U> void read(T& t, U&... u) { read(t); read(u...); }
template<class T, class U> void read(pair<T,U>& p) { read(p.fr,p.sc); }
template<class T> void read(vector<T>& x) { for(auto &z: x) read(z); }
template<class T> void readn(vector<T>& x, int n) { x.resize(n); for(auto &z: x) read(z); }

// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	#ifdef LOCAL
		return b ? "true" : "false"; 
	#else 
		return ts((int)b);
	#endif
}

template<size_t SZ> str ts(bitset<SZ> b) { str res = ""; for(int i = 0; i < SZ; ++i) res += char('0'+b[i]); return res; }
template<class T, class U> str ts(pair<T,U> p);
template<class T> str ts(T v) { // containers with begin(), end()
	#ifdef LOCAL
		bool fst = 1; str res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	#else
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;
	#endif
}

template<class T, class U> str ts(pair<T,U> p) {
	#ifdef LOCAL
		return "("+ts(p.fr)+", "+ts(p.sc)+")"; 
	#else
		return ts(p.fr)+" "+ts(p.sc);
	#endif
}
 
// OUTPUT
template<class T> void pr(T x) { cout << ts(x); }
template<class T, class ...U> void pr(const T& t, const U&... u) { pr(t); pr(u...); }
void write() { pr("\n"); } // print w/ spaces
template<class T, class ...U> void write(const T& t, const U&... u) { 
	pr(t); if (sizeof...(u)) pr(" "); write(u...); }
 
// DEBUG
void DBG() { cerr << "]" << endl; }
template<class T,class ...U> void DBG(const T& t, const U&... u) {
	cerr << ts(t); if (sizeof...(u)) cerr << ", ";
	DBG(u...); }
#ifdef LOCAL // compile with -DLOCAL, chk -> fake assert
	#define dbg(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
	#define chk(...) if (!(__VA_ARGS__)) cerr << "Line(" << __LINE__ << ") -> function(" \
		 << __FUNCTION__  << ") -> CHK FAILED: (" << #__VA_ARGS__ << ")" << "\n", exit(0);
#else
	#define dbg(...) 0
	#define chk(...) 0
#endif

// MISC
template<class T> int lwb(vector<T>& a, const T& b) { return lower_bound(all(a),b)-(a).begin(); }
template<class T> void uniq(vector<T>& v) { sort(all(v)); v.erase(unique(all(v)),v.end()); }

// template<typename T>
// using oset = __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const long long inf = 1e18;
const int hell = 1e9+7; // 998244353;
const long double PI = acos((long double)-1);
template<int32_t MOD>
struct mod_field {
	int32_t val;
	mod_field(long long v = 0) {if (v < 0) v = v % MOD + MOD; if (v >= MOD) v %= MOD; val = v; }

	static int32_t mod_inv(int32_t a, int32_t m = MOD) {
		int32_t g = m, r = a, x = 0, y = 1;
		while (r != 0) {
			int32_t q = g / r;
			g %= r; swap(g, r);
			x -= q * y; swap(x, y);
		}
		return x < 0 ? x + m : x;
	}
	static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
		#if !defined(_WIN32) || defined(_WIN64)
		return x % m;
		#endif
		unsigned x_high = x >> 32, x_low = (unsigned) x;
		unsigned quot, rem;
		asm("divl %4\n"
			: "=a" (quot), "=d" (rem)
			: "d" (x_high), "a" (x_low), "r" (m));
		return rem;
	}

	explicit operator int() const {return val; }
	mod_field& operator+=(const mod_field &other) {val += other.val; if (val >= MOD) val -= MOD; return *this; }
	mod_field& operator-=(const mod_field &other) {val -= other.val; if (val < 0) val += MOD; return *this; }
	mod_field& operator*=(const mod_field &other) {val = fast_mod((uint64_t) val * other.val); return *this; }
	mod_field& operator/=(const mod_field &other) {return *this *= other.inv(); }
	friend mod_field operator+(const mod_field &a, const mod_field &b) { return mod_field(a) += b; }
	friend mod_field operator-(const mod_field &a, const mod_field &b) { return mod_field(a) -= b; }
	friend mod_field operator*(const mod_field &a, const mod_field &b) { return mod_field(a) *= b; }
	friend mod_field operator/(const mod_field &a, const mod_field &b) { return mod_field(a) /= b; }
	mod_field& operator++() {val = val == MOD - 1 ? 0 : val + 1; return *this; }
	mod_field& operator--() {val = val == 0 ? MOD - 1 : val - 1; return *this; }
	mod_field operator++(int32_t) { mod_field before = *this; ++*this; return before; }
	mod_field operator--(int32_t) { mod_field before = *this; --*this; return before; }
	mod_field operator-() const {return val == 0 ? 0 : MOD - val; }
	bool operator==(const mod_field &other) const { return val == other.val; }
	bool operator!=(const mod_field &other) const { return val != other.val; }
	mod_field inv() const {return mod_inv(val); }
	friend ostream& operator<<(ostream &stream, const mod_field &m) {return stream << m.val; }
	friend istream& operator>>(istream &stream, mod_field &m) {return stream >> m.val; }

	mod_field pow(long long p) const {
		assert(p >= 0);
		mod_field a = *this, result = 1;
		while (p > 0) {
			if (p & 1)
				result *= a;
			
			a *= a;
			p >>= 1;
		}
		return result;
	}
};
typedef mod_field<hell> mod_int;
const int maxn = 1000006;
str s,t;
vec<str> transform(str &x){
	int len=sz(s)+1;
	vec<str> dog;
	for (int p = 0; p < sz(s)+1; ++p) {
		str cat="";
		bool flag=1;
		for (int j = 0; j < sz(x); ++j) {
			int idx=(j-p+len)%len;
			if(idx==0){
				cat+=x[j];
			}else{
				if(s[idx-1]!=x[j]){
					flag=0;
					break;
				}
			}
		}
		// dbg(flag,p);
		if(flag)dog.pb(cat);
	}
	return dog;
}
mod_int cnt[26]={0};
mod_int ans[100005];
mod_int cnts=1;
int n,q;
int k;
mod_int pow2[100005];
mod_int solve(str &w,int curlvl,int l,int r,int jmp){
	dbg(w,curlvl,l,r,jmp);
	if(curlvl>=k)return 0;
	if(l==r){
		dbg(l);
		mod_int val = cnt[w[l]-'a'];
		for (int i = 0; i < curlvl; ++i) {
			if(t[i]==w[l]){
				val-=pow2[k-i-1];
			}
		}
		return val;
	}
	// str le,ri;
	int n=sz(w);
	bool flag=1;
	int curr=0;
	int fl=hell,fr=0;
	for (int i = l; i <=r; i+=jmp) {
		if((curr%2)==0){
			if(w[i]!=t[curlvl])
				flag=0;
		}else {
			// le+=w[i];
			amin(fl,i);
			amax(fr,i);
		}
		curr++;
	}
	mod_int ans=0;
	dbg(curlvl,l,r,fl,fr);
	if(flag&&fl<=fr)ans+=solve(w,curlvl+1,fl,fr,jmp*2);
	flag=1;
	curr=1;
	fl=hell,fr=0;
	for (int i = l; i <=r; i+=jmp) {
		if((curr%2)==0){
			if(w[i]!=t[curlvl])
				flag=0;
		}else {
			// ri+=w[i];
			amin(fl,i);
			amax(fr,i);
		}
		curr++;
	}
	dbg(curlvl,l,r,fl,fr);
	if(flag&&fl<=fr)ans+=solve(w,curlvl+1,fl,fr,jmp*2);
	return ans;
}
vector<str> queries[maxn];
void solve(){
	pow2[0]=1;
	for (int i = 1; i < 100005; ++i) {
		pow2[i]=pow2[i-1]*2;
	}
	read(n,q);
	read(s,t);
	vector<pii> idx;
	for (int i = 0; i < q; ++i) {
		int kk;
		str w;
		read(kk,w);
		vec<str> tr=transform(w);
		if(sz(tr))dbg(tr);
		queries[i]=tr;
		idx.pb({kk,i});
	}
	sort(all(idx));
	int curp=0;
	for (k = 0; k <=n; ++k) {
		while(curp<q&&idx[curp].fr==k){
			mod_int &res = ans[idx[curp].sc];
			for(auto &w:queries[idx[curp].sc]){
				if(sz(w)==0){
					res+=cnts;
					continue;
				}
				// keep halving until single char left
				res+=solve(w,0,0,sz(w)-1,1);
				dbg(res.val);
			}
			curp++;
		}
		if(k<n){
			cnts*=2;
			for (int i = 0; i < 26; ++i) {
				cnt[i]*=2;
			}
			cnt[t[k]-'a']+=1;
		}
	}
	for (int i = 0; i < q; ++i) {
		cout<<ans[i]<<"\n";
	}
}

signed main(){

	unsyncIO();
	// setPrec(9);
	// setIn("input.txt");
	// setOut("output.txt");
	int cases=1;
	// cin>>cases;
	for (int i = 1; i <= cases; ++i) {
		solve();
	}
	#ifdef LOCAL
	    cerr<<endl<<"Time Elasped : "<<elasped_time<<endl;
 	#endif
	return 0;
}
