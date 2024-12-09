//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set> 
#include<iomanip>
#define IOS 	cin.tie(0), ios::sync_with_stdio(false) 
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 1e5 + 10, M = N * 2, mod = 3;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-4;
const double pi = acos(-1);
const int P = 131;

int n;
vector<pii> v1, v2;

int h[N], e[M], ne[M], idx;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int dfs(int u, int fa)
{
	int l = 0, r = 0;
	for(int i = h[u] ; ~i ; i = ne[i])
	{
		int j = e[i];
		if(j == fa) continue;
		int cur = dfs(j, u);
		if(!cur) continue;
		if(r) v1.push_back({u, j}), v2.push_back({j, cur});
		else if(!l) l = cur;
		else if(!r) r = cur;
	}
	
	if(l && r && fa)
		v1.push_back({fa, u}), v2.push_back({l, r});
		
//	return l ? (r && fa) ? 0 : l : u;
	if(l)
	{
		if(r && fa) return 0;
		else return l;
	}
	return u;
}

int main()
{
	IOS; 
	int T;
	cin >> T;
	while(T --)
	{
		cin >> n;
		idx = 0;
		for(int i = 1 ; i <= n ; i ++) h[i] = -1;
		for(int i = 1 ; i < n ; i ++)
		{
			int a, b;
			cin >> a >> b;
			add(a, b), add(b, a);
		}
		
		
		int m = dfs(1, 0);
		cout << v1.size() << "\n";
		for(int i = 0 ; i < v1.size() ; ++ i)
			cout << v1[i].x << " " << v1[i].y << " " << m << " " << v2[i].x << "\n", m = v2[i].y;
		v1.clear(), v2.clear();
	 } 

	return 0;
} 