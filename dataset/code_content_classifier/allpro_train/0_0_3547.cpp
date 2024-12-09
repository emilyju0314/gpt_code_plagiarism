#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	vector<string> grid(n);
	for(int i=0;i<n;i++){
		cin>>grid[i];
	}
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	string result = "";

	function<void(int, int)> dfs = [&](int i, int j){
		if(i<0 || i>=n || j<0 || j>=m || visited[i][j] || grid[i][j]=='A'){
			return;
		}
		visited[i][j] = true;
		result += grid[i][j];
		dfs(i-1, j);
		dfs(i+1, j);
		dfs(i, j-1);
		dfs(i, j+1);
	};

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]=='A' && !visited[i][j]){
				dfs(i, j);
			}
		}
	}

	sort(result.begin(), result.end());
	cout<<result<<endl;

	return 0;
}