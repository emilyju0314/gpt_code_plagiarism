#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
const int N = 500005;
int t, n, m;
std::set<int> E[N], S[N];
int cnt, d[N], bel[N], rt[N];
int p[N], q[N], tot;
int main(void)
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		memset(bel, 0, sizeof(int)*(n+5)), cnt = 0;
		memset(d, 0, sizeof(int)*(n+5));
		memset(rt, 0, sizeof(int)*(n+5));
		tot = 0;
		for(int i = 1;i <= n;++i)
			E[i].clear(), S[i].clear();
		for(int i = 1;i <= m;++i)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			E[x].insert(y), E[y].insert(x);
			++d[x], ++d[y];
		} 
		for(int i = 1;i <= n;++i)
		{
			if(d[i] == n-1)
			{
				p[i] = q[i] = ++tot;
				continue;
			}
			if(bel[i])
				continue;
			int to = 1;
			for(std::set<int>::iterator it = E[i].begin();it != E[i].end();++it, ++to)
			{
				if(to == i)
					++to;
				if(*it != to)
					break;
			}
			if(to == i)
				++to;
			if(!bel[to])
			{
				rt[bel[i] = bel[to] = ++cnt] = to;
				S[cnt].insert(i), S[cnt].insert(to);
				continue;
			}
			if(S[bel[to]].size() == 2 || rt[bel[to]] == to)
				rt[bel[to]] = to, S[bel[to]].insert(i), bel[i] = bel[to];
			else
				S[bel[to]].erase(to), rt[bel[i] = bel[to] = ++cnt] = to, S[cnt].insert(i), S[cnt].insert(to);
		}
		for(int i = 1;i <= cnt;++i)
		{
			++tot;
			p[rt[i]] = tot, q[rt[i]] = tot+S[i].size()-1;
			for(std::set<int>::iterator it = S[i].begin();it != S[i].end();++it)
				if(*it != rt[i])
					p[*it] = ++tot, q[*it] = tot-1;
		}
		for(int i = 1;i <= n;++i)
			printf("%d ", p[i]);
		putchar('\n');
		for(int i = 1;i <= n;++i)
			printf("%d ", q[i]);
		putchar('\n'); 
	}
	return 0;
}