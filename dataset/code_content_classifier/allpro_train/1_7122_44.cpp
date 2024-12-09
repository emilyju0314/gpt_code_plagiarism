#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for(int i=(a); i<(n); ++i)
#define per(i, a, n) for(int i=(a); i>(n); --i)
#define pb emplace_back
#define mp make_pair
#define clr(a, b) memset(a, b, sizeof(a))
#define all(x) (x).begin(),(x).end()
#define lowbit(x) (x & -x)
#define fi first
#define se second
#define lson o<<1
#define rson o<<1|1
#define gmid l[o]+r[o]>>1
 
using LL = long long;
using ULL = unsigned long long;
using pii = pair<int,int>;
using PLL = pair<LL, LL>;
using UI = unsigned int;
 
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double EPS = 1e-8;
const double PI = acos(-1.0);

const int N = 1010;
const int M = 1e5 + 10;

int n, k, m, prime[M];
bool vis[M];
LL a[N], val[N], idx[N];

unordered_map<LL, int> MP;
vector<LL> V[N];

int getid(LL v){
	if(MP.count(v))	return MP[v];
	int x = MP.size();
	MP[v] = x;
	idx[x] = v;
	return x;
}

LL cal(LL v, LL top, int p){
	LL low = 0, mid, a;
	while(low <= top){
		mid = low + top >> 1;
		a = mid * mid;
		if(p == 3)	a = a * mid;
		if(a == v){
			return mid;
		}
		if(a > v)	top = mid - 1;
		else	low = mid + 1;
	}
	return -1;
}

bool is_small_prime(LL v){
	if(v >= 1000000000)	return 0;
	for(LL i=2; i*i <= v; ++i){
		if(v % i == 0)	return 0;
	}
	return 1;
}

LL get(LL v){
	LL x;
	rep(i, 0, m){
		if(v % prime[i] == 0){
			x = v;
			while(x % prime[i] == 0)	x /= prime[i];
			if(x == 1)	return prime[i];
			return -1;
		}
	}
	
	if(is_small_prime(v)){
		return v;
	}
	
	x = cal(v, 1000000, 3);
	if(x != -1)	return x;
	x = cal(v, 1000000000, 2);
	return x;
}

void solve2(int cur){
	vector<LL> ans;
	int m = MP.size();
	for(int i=0; i<m; ++i){
		if(V[i].size() > 1){
			for(LL x : V[i]){
				ans.pb(x);
			}
		}
	}
	LL v;
	for(int i=0; i<n; ++i){
		if(val[i] == -1){
			v = a[i];
			for(int j=0; j<m; ++j){
				if(V[j].size() == 1)	continue;
				LL y = idx[j];
				while(v % y == 0)	v /= y;
			}
			if(v != 1)	continue;
			ans.pb(a[i]);
			if(ans.size() == k)	break;
		}
	}
	if(ans.size() == k){
		for(LL x : ans)	printf("%lld ", x);
		puts("");
	} else {
		puts("0");
	}
}

bool mk[N];

void solve3(){
	vector<LL> ans;
	int m = MP.size();
	for(int i=0; i<m; ++i){
		mk[i] = 0;
	}
	LL v;
	for(int i=0; i<n; ++i){
		if(val[i] == -1){
			v = a[i];
			int cnt = 0;
			for(int j=0; j<m; ++j){
				if(V[j].size() == 1)	continue;
				LL y = idx[j];
				if(v % y == 0)	++cnt;
				while(v % y == 0)	v /= y;
			}
			if(v != 1)	continue;
			if(cnt * 2 + 1 <= k){
				for(int j=0; j<m; ++j){
					if(V[j].size() == 1)	continue;
					LL y = idx[j];
					if(a[i] % y == 0){
						mk[j] = 1;
						for(LL x : V[j]){
							ans.pb(x);
						}
					}
				}
				ans.pb(a[i]);

				break;
			}
		}
	}
	rep(i, 0, m){
		if(ans.size() == k)	break;
		if(mk[i] || V[i].size() == 1)	continue;
		for(LL x : V[i])	ans.pb(x);
	}
	if(ans.size() == k){
		for(LL x : ans)	printf("%lld ", x);
		puts("");
	} else {
		puts("0");
	}
}

int main(){
	scanf("%d %d", &n, &k);

	clr(vis, 0);

	vis[0] = vis[1] = 1;

	m = 0;

	rep(i, 2, M){
		if(vis[i])	continue;
		prime[m++] = i;
		for(int j=i<<1; j<M; j+=i){
			vis[j] = 1;
		}
	}

	rep(i, 0, n){
		scanf("%lld", a+i);
		LL p = get(a[i]);
		val[i] = p;
		if(p == -1)	continue;
		int id = getid(p);
		V[id].pb(a[i]);
	}

	if(k == 1){
		puts("0");
		return 0;
	}

	int sum = 0;
	int num = MP.size();
	int mx = 0;
	vector<pii> A;

	for(int i=0; i<num; ++i){
		if(V[i].size() > 1){
			sum += V[i].size();
			mx = max(mx, (int)V[i].size());
			A.pb((int)V[i].size(), i);
		}
	}

	if(sum < k){
		solve2(sum);
		return 0;
	}
	
	if(mx == 2 && (k & 1)){
		solve3();
		return 0;
	}

	sort(all(A));
	int len = A.size();
	vector<LL> ans;

	if(A[len-1].fi >= k){
		for(LL x : V[A[len-1].se]){
			printf("%lld ", x);
			--k;
			if(k == 0)	break;
		}
		puts("");
		return 0;
	}

	for(int i=0; i<len - 1; ++i){
		if(A[i].fi + A[len-1].fi >= k){
			int d = min(A[i].fi, k - 2);
			k -= d;
			for(LL x : V[A[i].se]){
				ans.pb(x);
				--d;
				if(d == 0)	break;
			}
			for(LL x : V[A[len-1].se]){
				ans.pb(x);
				--k;
				if(k == 0)	break;
			}

			break;
		} else {
			int d = min(A[i].fi, k - 4);
			k -= d;
			for(LL x : V[A[i].se]){
				ans.pb(x);
				--d;
				if(d == 0)	break;
			}
		}
	}

	for(LL x : ans){
		printf("%lld ", x);
	}
	puts("");

	return 0;
}
