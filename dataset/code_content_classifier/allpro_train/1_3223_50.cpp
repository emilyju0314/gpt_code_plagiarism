#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pop_b pop_back
#define pf push_front
#define pop_f pop_front
#define mt make_tuple
#define eb emplace_back
#define sf(x) sizeof(x)
#define len(x) x.length()
#define sz(x) x.size()
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define LB(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define UB(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
typedef long long ll;
typedef pair<ll,ll> ii;
typedef long double ld; 
typedef vector<int> vi;
typedef vector<set<ll>> vset;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef deque<ll> dql;
typedef deque<int> dqi;
typedef unsigned long long ull;
typedef tuple<int,int,int> State;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\n";
	err(++it, args...);
}

#define vmax(type)   std::numeric_limits<type>::max()
#define vmin(type)   std::numeric_limits<type>::min()
#define each(a,x) for( auto &a:(x))
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define rep2(i, l, r) for (ll i = (l); i < (r); i++)
#define rep2r(i, l, r) for (ll i = (r) - 1; i >= (l); i--)
#define range(a) a.begin(), a.end()
#define deb(x) cout<<#x<<" "<<x<<endl;
#define cinai(a, n) vi a(n); rep(i, n) { cin>>a[i]; }
#define cinal(a, n) vl a(n); rep(i, n) { cin>>a[i]; }
#define coutai(a, n) rep(i, n) { cout<<a[i]<<" "; } ent;
#define coutal(a, n) rep(i, n) { cout<<a[i]<<" "; } ent;
#define ent cout<<endl;
#define resize_vec(a) a.resize(unique(a.begin(), a.end()) - a.begin());
#define ms(dp, x) memset(dp, x, sf(dp))
#define endl '\n'

ll powm(ll a, ll b, ll mod) {
	ll res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

int db = 0;
const ll mod = 1e9 + 7;
const ll N = 1000005;
const ll inf = 1e9;
#define er if(db) error

template<typename T> struct rmq {
	vector<T> v; int n;
	static const int b = 30; // block size
	vector<int> mask, t; // mask and sparse table

	int op(int x, int y) {
		return v[x] < v[y] ? x : y;
	}
	// least significant set bit
	int lsb(int x) {
		return x & -x;
	}
	// index of the most significant set bit
	int msb_index(int x) {
		return __builtin_clz(1)-__builtin_clz(x);
	}
	// answer query of v[r-size+1..r] using the masks, given size <= b
	int small(int r, int size = b) {
		// get only 'size' least significant bits of the mask
		// and then get the index of the msb of that
		int dist_from_r = msb_index(mask[r] & ((1<<size)-1));

		return r - dist_from_r;
	}
	rmq(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
		int curr_mask = 0;
		for (int i = 0; i < n; i++) {

			// shift mask by 1, keeping only the 'b' least significant bits
			curr_mask = (curr_mask<<1) & ((1<<b)-1);

			while (curr_mask > 0 and op(i, i - msb_index(lsb(curr_mask))) == i) {
				// current value is smaller than the value represented by the
				// last 1 in curr_mask, so we need to turn off that bit
				curr_mask ^= lsb(curr_mask);
			}
			// append extra 1 to the mask
			curr_mask |= 1;

			mask[i] = curr_mask;
		}

		// build sparse table over the n/b blocks
		// the sparse table is linearized, so what would be at
		// table[j][i] is stored in table[(n/b)*j + i]
		for (int i = 0; i < n/b; i++) t[i] = small(b*i+b-1);
		for (int j = 1; (1<<j) <= n/b; j++) for (int i = 0; i+(1<<j) <= n/b; i++)
			t[n/b*j+i] = op(t[n/b*(j-1)+i], t[n/b*(j-1)+i+(1<<(j-1))]);
	}
	// query(l, r) returns the actual minimum of v[l..r]
	// to get the index, just change the first and last lines of the function
	T query(int l, int r) {
		// query too small
		if (r-l+1 <= b) return v[small(r, r-l+1)];

		// get the minimum of the endpoints
		// (there is no problem if the ranges overlap with the sparse table query)
		int ans = op(small(l+b-1), small(r));

		// 'x' and 'y' are the blocks we need to query over
		int x = l/b+1, y = r/b-1;

		if (x <= y) {
			int j = msb_index(y-x+1);
			ans = op(ans, op(t[n/b*j+x], t[n/b*j+y-(1<<j)+1]));
		}

		return v[ans];
	}
};

void solve()
{
	int n;
	cin>>n;
	cinal(a, n);
	rmq<ll> pre(a);
	ll cur_min = a[0];
	ll rev_max[n];
	rev_max[n-1] = a[n-1];
	repr(i, n-1)
		rev_max[i] = max(rev_max[i+1], a[i]);
	for(int i = 0; i < n - 2; i++){
		cur_min = max(a[i], cur_min);
		int l = i+1, r = n-2;
		while(l < r){
			int mid = (l + r + 1) / 2;
			// cout<<i<<" "<<mid<<" "<<cur_min<<" "<<pre.query(i+1, mid)<<" "<<rev_max[mid+1]<<" "<<l<<" "<<r<<endl;
			if(cur_min == pre.query(i+1, mid)){
				if(rev_max[mid+1] == cur_min){
					cout<<"YES\n";
					cout<<i+1<<" "<<mid - i<<" "<<n - mid - 1<<endl;
					return;
				}else if(rev_max[mid+1] > cur_min){
					l = mid;
				}else
					r = mid - 1;
			}
			else if(cur_min > pre.query(i+1, mid)){
				r = mid - 1;
			}
			else{
				l = mid;
			}
		}
		if(cur_min == pre.query(i+1, l) and rev_max[l+1] == cur_min){
			cout<<"YES\n";
			cout<<i+1<<" "<<l - i<<" "<<n - l - 1<<endl;
			return;
		}
	}
	cout<<"NO\n";
}

// #define _DEBUG
#define testCases
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int tc = 1;
#ifdef testCases
	cin>>tc;
#endif
	for(int t = 1; t <= tc; t++)
	{
#ifdef _DEBUG
	db = 1;
	int tt = clock();
#endif
		// cout<<"Case #"<<t<<": ";
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}


