#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
using namespace std;
long long a[100001];//????????????????????????(????????????
const long long inf = 8000000000;
int zombie[100001];//????????????????????????
struct A {
	long long cost,to;
};
vector<long long>e[100001];//??????????????£????????????
long long g[100001];
struct P {
	long long cost, pos;
};
bool operator<=(P a, P b) {
	return a.cost <= b.cost;
}
bool operator>(P a, P b) {
	return a.cost > b.cost;
}
int main() {
	long long n, m, k, s, p, q, c, d;
	cin >> n >> m >> k >> s >> p >> q;
	for (int i = 0; i < k; i++) {
		cin >> c;
		zombie[i] = c;
		a[c] = 3;
	}
	for (int i = 0; i < m; i++) {
		cin >> c >> d;
		e[c].push_back(d);
		e[d].push_back(c);
	}
	for (int i = 0; i < k; i++) {
		priority_queue<P, vector<P>, greater<P>>p;
		fill(g, g + n + 1, inf);
		long long r = zombie[i];
		p.push(P{ 0,r });
		g[r] = 0;
		while (!p.empty()) {
			P t = p.top(); p.pop();
			for (int i = 0; i < (int)e[t.pos].size(); i++) {
				long long o = t.pos;
				if (g[e[o][i]] > g[o] + 1&&a[e[o][i]]!=3) {
					g[e[o][i]] = g[o] + 1;
					p.push(P{ g[o] + 1,e[o][i] });
					if (g[e[o][i]] <= s) a[e[o][i]] = 2;
					else break;
				}
			}
		}
	}
	priority_queue<P, vector<P>, greater<P>>r;
	for (int i = 0; i <= n; i++) {
		g[i] = inf;
	}
	r.push(P{ 0, 1 });
	g[1] = 0;
	while (!r.empty()) {
		P t = r.top(); r.pop();
		for (int i = 0; i < (int)e[t.pos].size(); i++) {
			long long co;
			if (a[e[t.pos][i]] == 2) co = q;
			else if(a[e[t.pos][i]]==0)co = p;
			else if(a[e[t.pos][i]]==3){
				goto stop;
			}
			if (g[e[t.pos][i]] > g[t.pos] + co) {
				g[e[t.pos][i]] = g[t.pos] + co;
				r.push(P{ g[e[t.pos][i]], e[t.pos][i] });
			}
			if (g[n] != inf) goto sto;
		stop:;
		}
	}
sto:;
	long long cos;
	if (a[n] == 2)cos = q;
	else cos = p;
	cout << g[n]-cos << endl;
}