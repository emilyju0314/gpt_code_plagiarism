#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
vector<int> v[maxn];
int x, y;
int dia;

int dfs(int i, int fa){
	int mx = 0;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		int x = dfs(to, i);
		dia = max(dia, mx + x);
		mx = max(mx, x);
	}
	return mx + 1;
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	dfs(1, 0);
	printf((dia - 1) % 3 ? "First" : "Second");
}