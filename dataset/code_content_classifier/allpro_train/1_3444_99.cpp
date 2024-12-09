#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const double EPS = 1e-10;
const ll INF = 100000000;
const ll MOD = 1000000007;

constexpr int MAX_N = 100000;

struct UF{
	int par[MAX_N];
	int rank[MAX_N];
	int si[MAX_N];

	void init(int n){
		rep(i,n){
			par[i] = i;
			rank[i] = 0;
			si[i] = 1;
		}
	}

	int find(int x){
		if(par[x] == x) return x;
		else return par[x] = find(par[x]);
	}

	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		
		if(rank[x] < rank[y]){
			par[x] = y;
			si[y] += si[x];
		} else{
			par[y] = x;
			if(rank[x] == rank[y]) rank[x]++;
			si[x] += si[y];
		}
	}

	bool same(int x, int y){
		return find(x) == find(y);
	}
} uf;

int n, m;

int main(){
    cin >> n >> m;
    uf.init(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        uf.unite(a,b);
    }
    ll x = uf.si[uf.find(0)], y = uf.si[uf.find(1)];
    if (x > y) swap(x, y);
    y = n-x;
    ll ans = x*(x-1)/2+y*(y-1)/2; 
    cout << ans - m << endl;
}






























