#include <iostream>
#include <utility>
#include <vector>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

struct UnionFind{
	int size;
	vector<int> parent;
	
	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++) parent[i] = i;
	}
	int root(int i){
		if(parent[i] == i) return i;
		return parent[i] = root(parent[i]);
	}
	bool same(int i, int j){
		return root(i) == root(j);
	}
	void unite(int i, int j){
		int root_i = root(i), root_j = root(j);
		if(root_i == root_j) return;
		parent[root_i] = root_j;
	}
};

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

//ax+by = gcd(a, b)を満たす(x, y)を求めgcd(a, b)を返す
llint extgcd(llint a, llint b, llint &x, llint &y)
{
	if(b == 0){
		x = 1, y = 0;
		return a;
	}
	llint xx, yy;
	llint d = extgcd(b, a%b, xx, yy);
	x = yy, y = xx-(a/b)*yy;
	return d;
}

//a^{-1} (mod m)を求める。存在しない場合(gcd(a, m)!=1)は-1を返す
llint mod_inverse(llint a, llint m)
{
	llint x, y;
	if(extgcd(a, m, x, y) != 1) return -1;
	return (x%m + m) % m;
}

//ax = b (mod m)を満たすx(mod m/gcd(a, m))を求める。存在しない場合(b%gcd(a, m)!=0)は(0, -1)を返す
P congruence(llint a, llint b, llint m)
{
	llint d = gcd(a, m);
	if(b % d) return make_pair(0, -1);
	a /= d, b /= d, m /= d;
	return make_pair(b * mod_inverse(a, m) % m, m);
}

//連立合同方程式a_i*x = b_i (mod m_i)(i = 1, 2, ..., n)の解(x, M)を求める。存在しない場合(0, -1)を返す
P SimultaneousCongruence(llint a[], llint b[], llint m[], llint n)
{
	llint x = 0, M = 1;
	for(int i = 1; i <= n; i++){
		P res = congruence(a[i]*M, (b[i]-a[i]*x%m[i]+m[i])%m[i], m[i]);
		if(res.second == -1) return res;
		x += M*res.first, M *= res.second;
	}
	return make_pair(x, M);
}

llint n;
llint p[205], q[205];
llint pinv[205];
UnionFind uf(205);
vector<llint> vec[205];
llint a[205], b[205], m[205];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i <= n; i++) cin >> q[i];
	for(int i = 1; i <= n; i++) pinv[p[i]] = i;
	
	for(int i = 1; i <= n; i++){
		llint x = p[i], mn = -1, cnt = 0;
		do{
			if(x == i) mn = cnt;
			x = q[x];
			cnt++;
		}while(x != p[i]);
		if(mn == -1){
			cout << -1 << endl;
			return 0;
		}
		a[i] = 1, b[i] = mn, m[i] = cnt;
	}
	
	//for(int i = 1; i <= n; i++) cout << a[i] << " " << b[i] << " " << m[i] << endl;
	
	P res = SimultaneousCongruence(a, b, m, n);
	if(res.second == -1) cout << -1 << endl;
	else cout << res.first << endl;
	
}
