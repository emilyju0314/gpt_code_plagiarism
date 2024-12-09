#include<bits/stdc++.h>
#define sit set<int>::iterator 
#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define mpr make_pair
#define x(v) (v).first
#define y(v) (v).second
#define siz(v) (int)(v).size()
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;

const int N = 2e5 + 10;
int n;
int fa[N], siz[N], x[N], y[N];
set<int> s;
int t[N];
int find(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
	x = find(x), y = find(y);
	if(x == y) return;
	fa[x] = y;
	siz[y] += siz[x];
	return;
}
int main()
{
	scanf("%d", &n);
	rep(i, 1, n) siz[i] = 1, fa[i] = i;
	rep(i, 1, n) scanf("%d%d", &x[i], &y[i]), t[x[i]] = y[i];
	rep(i, 1, n)
	{
		if(s.empty()) 
		{
			s.insert(t[i]);
			continue;
		}
		sit it = s.lower_bound(t[i]);
		if(it == s.begin()) 
		{
			s.insert(t[i]);
			continue;
		}
		vector<int> p;
		for(sit ti = s.begin(); ti != it; ti++)
		{
			p.push_back(*ti);
		}
		rep(j, 0, siz(p) - 2) merge(p[j + 1], p[j]);
		rep(j, 0, siz(p) - 1) s.erase(p[j]);
		merge(t[i], p[0]);
		s.insert(p[0]);
	}
	rep(i, 1, n) printf("%d\n", siz[find(y[i])]);
	return 0;
}