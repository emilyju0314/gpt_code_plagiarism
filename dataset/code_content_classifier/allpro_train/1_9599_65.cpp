#include "bits/stdc++.h"
using namespace std;

vector<int> G[52];
vector<int> used(52,0);
int x,y;
int c=0;

int dfs(int p){
	if(p==y){
		c=1;
	}
	for(int i=0;i<G[p].size();i++){
		if((p==x&&G[p][i]==y)){
		}else if(used[G[p][i]]==0){
			used[G[p][i]]=1;
			dfs(G[p][i]);
			used[G[p][i]]=0;
		}
	}
	return 0;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> a(52);
	vector<int> b(52);
	
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];
		a[i]--;
		b[i]--;
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	
	int ans=0;
	
	for(int i=0;i<m;i++){
		x=a[i];
		y=b[i];
		c=0;
		dfs(a[i]);
		ans+=1-c;
	}
	
	cout<<ans<<endl;
	return 0;
}