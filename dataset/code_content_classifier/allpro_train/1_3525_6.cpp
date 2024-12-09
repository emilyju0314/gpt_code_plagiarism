#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200005;

vector<int> adj[N];
int n,m;

bool vstd[N];

int cnt = 0;
void dfs(int x){
	cnt++;
	vstd[x] = true;
	for(int y:adj[x]){
		if(!vstd[y])dfs(y);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int ans = 1;
	
	for(int i=1;i<=n;i++){
		if(!vstd[i]){
			cnt = 0;
			dfs(i);
			ans = max(ans,cnt);
		}
	}
	
	cout<<ans;
	
	return 0;
}
