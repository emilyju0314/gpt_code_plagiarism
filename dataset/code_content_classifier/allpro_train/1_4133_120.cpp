#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n;
bool used[200200];
vector<int> v[200200];
vector<int> color[2];

void dfs(int now, bool col){
	used[now] = 1;
	color[col].push_back(now);
	rep(i, v[now].size()){
		if(!used[v[now][i]]){
			dfs(v[now][i], col ^ 1);
		}
	}
}

int ans[200200];

int main(){
	scanf("%d", &n);
	rep(i, n-1){
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		v[a].push_back(b);
		v[b].push_back(a);
	} 
	memset(used, 0, sizeof(used));
	dfs(0, 0);
	if(color[0].size() > color[1].size()) swap(color[0], color[1]);
	int num0 = n / 3, num1 = (n+2) / 3, num2 = (n+1) / 3;
	bool has1 = 0, has2 = 0;
	rep(i, 2){
		if(color[i].size() >= num1){
			for(int cnt = 0; cnt < num1; cnt++){
				ans[color[i][color[i].size() - 1]] = cnt*3 + 1;
				color[i].pop_back();
			} 
			has1 = 1;
			break;
		}
	}
	rep(i, 2){
		if(color[i].size() >= num2){
			for(int cnt = 0; cnt < num2; cnt++){
				ans[color[i][color[i].size() - 1]] = cnt*3 + 2;
				color[i].pop_back();
			} 
			has2 = 1;
			break;
		}
	}
	if(!(has1 && has2)){
		cout << "-1" << endl;
		return 0;
	}
	int cnt = 0;
	rep(i, n){
		if(ans[i] == 0){
			ans[i] = (cnt+1) * 3;
			cnt++;
		}
	}
	rep(i, n) cout << ans[i] << " ";
	cout << endl;
	return 0;
} 