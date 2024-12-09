#include<iostream>
#include<vector>
using namespace std;
const int maxn = 100001;
const int maxk = 17;
struct info{
	int v, c, w;
};
struct query{
	int id, c, w, y;
};
int n, sz[maxn], g[maxn], top[maxn], up[maxn], depth[maxn], m;
long long ans[maxn];
vector < info > edge[maxn];
vector < query > ask[maxn];
int get_lca(int a, int b){
	while(g[a] != g[b])
		if(depth[top[g[a]]] < depth[top[g[b]]])b = up[top[g[b]]];
		else a = up[top[g[a]]];
	return depth[a] < depth[b] ? a : b;
}
void dfs1(int now, int last = 1){
	static int now_d = 0;
	up[now] = last;
	depth[now] = now_d++;
	sz[now] = 1;
	if(last != now){
		for(int i = 0;i < edge[now].size();++i)
			if(edge[now][i].v == last){
				edge[now].erase(edge[now].begin() + i);
				break;
			}
	}
	for(int i = 0;i < edge[now].size();++i){
		dfs1(edge[now][i].v, now), sz[now] += sz[edge[now][i].v];
		if(sz[edge[now][i].v] > sz[edge[now][0].v])swap(edge[now][i], edge[now][0]);
	}
	--now_d;
}
void dfs3(int now){
	static int now_g = 0;
	g[now] = now_g;
	if(!top[now_g])top[now_g] = now;
	if(!edge[now].empty()){
		dfs3(edge[now][0].v);
		for(int i = 1;i < edge[now].size();++i)
			++now_g, dfs3(edge[now][i].v);
	}
}
void dfs2(int now, int last = 1){
	static int total_w = 0;
	static int q_of[maxn] = {};
	static int w_of[maxn] = {};
	for(auto &i : ask[now]){
		ans[i.id] += (total_w - w_of[i.c] + q_of[i.c] * i.y) * i.w;
	}
	for(auto &i : edge[now]){
		if(i.v != last){
			++q_of[i.c];
			w_of[i.c] += i.w;
			total_w += i.w;
			dfs2(i.v, now);
			--q_of[i.c];
			w_of[i.c] -= i.w;
			total_w -= i.w;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for(int a, b, c, d, i = 1;i < n;++i){
		cin >> a >> b >> c >> d;
		edge[a].push_back({b, c, d});
		edge[b].push_back({a, c, d});
	}
	dfs1(1);
	dfs3(1);
	for(int i = 0, x, y, u, v;i < m;++i){
        cin >> x >> y >> u >> v;
		ask[u].push_back({i, x, 1, y});
		ask[v].push_back({i, x, 1, y});
		ask[get_lca(u, v)].push_back({i, x, -2, y});
	}
	dfs2(1);
	for(int i = 0;i < m;++i)cout << ans[i] << '\n';
}
