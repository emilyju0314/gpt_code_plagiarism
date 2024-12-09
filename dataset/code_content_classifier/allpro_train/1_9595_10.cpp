#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> G[100005];
int deg[100005];
int used[100005];

int id = 1;
void dfs(int v, int p)
{
	used[v] = id++;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		if(used[G[v][i]]){
			if(used[G[v][i]] < used[v]){
				deg[v]++;
				cout << v << " " << G[v][i] << endl;
			}
		}
		else dfs(G[v][i], v);
	}
	if(p != -1){
		if(deg[v]%2) cout << v << " " << p << endl;
		else cout << p << " " << v << endl, deg[p]++;
	}
}

int main(void)
{
	cin >> n >> m;
	int u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(m%2){
		cout << -1 << endl;
		return 0;
	}
	
	dfs(1, -1);
	
	return 0;
}