#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
using pii=pair<int,int>;

int dist[102];
queue<pii> q;
vector<int> adj[105];
bool vis[105];

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=1,u,k;i<=n;i++){
		cin>>u>>k;
		for(int j=0,tt;j<k;j++){
			cin>>tt;
			adj[u].push_back(tt);
		}
	}
	
	q.push({1,0});
	dist[1]=0;
	for(int i=2;i<=n;i++) dist[i]=1e8;
	
	while(!q.empty()){
		int from=q.front().first, fw=q.front().second;
		q.pop();
		if(fw!=dist[from]) continue;

		for(int to:adj[from]){
			if(dist[to]>dist[from]+1){
				dist[to]=dist[from]+1;
				q.push({to,dist[from]+1});
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		cout<< i <<' '<< ((dist[i]==1e8)?-1:dist[i]) <<endl;
	}
}
