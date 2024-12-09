#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const double eps = 1e-4;
int w, h, n;
struct Point
{
	double x, y;
	void in(){scanf("%lf%lf", &x, &y);}
}p[N];
inline int sgn(double x){return x < -eps ? -1 : x > eps ? 1 : 0;}
struct edge{int next, to;} e[N*N];
int head[N], tot;
void gInit(){memset(head, -1, sizeof(head)); tot = 0;}
void add_edge(int u,int v){e[tot] = (edge){head[u], v}; head[u] = tot++;}
bool vis[N];
double dist(const Point &a, const Point &b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool solve(double x)
{
	gInit();
	for(int i = 1; i <= n; ++i)
		if(sgn(p[i].x - x) < 0)
			add_edge(0, i);
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			if(sgn(dist(p[i], p[j]) - x - x) < 0)
			{
				add_edge(i, j);
				add_edge(j, i);
			}
	for(int i = 1; i <= n; ++i)
		if(sgn(w - p[i].x - x) < 0)
			add_edge(i, n + 1);
	queue<int> que;
	que.push(0);
	memset(vis, false, sizeof(vis));
	vis[0] = true;
	while(!que.empty())
	{
		int u = que.front(); que.pop();
		for(int i = head[u]; ~i; i = e[i].next)
			if(!vis[e[i].to])
			{
				vis[e[i].to] = true;
				que.push(e[i].to);
			}
	}
	if(vis[n + 1]) return false;
	//check start point and end point
/*	Point w0 = (Point){w, 0};
	Point wh = (Point){w, h};
	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i]) continue;
		if(sgn(dist(w0, p[i]) - x) <= 0) return false;
		if(sgn(dist(wh, p[i]) - x) <= 0) return false;
	}
*/
	return true;
}
int main()
{
	scanf("%d%d%d", &w, &h, &n);
	for(int i = 1; i <= n; ++i) p[i].in();
	double l = 0, r = 1e10, mid, ans = 0.0;
	for(int i = 0; i < 100; ++i)
	{
		mid = 0.5 * (l + r);
		if(solve(mid))
		{
			ans = mid;
			l = mid;
		}
		else
		{
			r = mid;
		}
	}
	printf("%.3f", ans);
	return 0;
}