#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int h,w;

vector<string>adj;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int bfs(int rotx,int roty,int tox,int toy){
	vector<vector<int>>dist(h,vector<int>(w,1e7));
	dist[rotx][roty]=0;

	using piii =pair<int,pair<int,int>>;

	priority_queue<piii,vector<piii>,greater<piii>>pq;
	pq.push({0,{rotx,roty}});

	while(!pq.empty()){
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx>=0&&ny>=0&&nx<h&&ny<w && adj[nx][ny]=='.'){
				if(dist[nx][ny]>dist[x][y]){
					dist[nx][ny]=dist[x][y];
					pq.push({dist[nx][ny],{nx,ny}});
				}
			}
		}
		for(int i=x-2;i<=x+2;i++){
			for(int j=y-2;j<=y+2;j++){
				if(i>=0&&j>=0&&i<h&&j<w &&adj[i][j]=='.'){
					if(dist[i][j]>dist[x][y]+1){
						dist[i][j]=dist[x][y]+1;
						pq.push({dist[i][j],{i,j}});
					}
				}
			}
		}
	}

	return dist[tox][toy];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>h>>w;
	int ch,cw,dh,dw;
	cin>>ch>>cw>>dh>>dw;
	ch--;cw--;dh--;dw--;
	for(int i=0;i<h;i++){
		string s;
		cin>>s;
		adj.push_back(s);
	}
	int ans = bfs(ch,cw,dh,dw);
	if(ans>=1e7)ans=-1;
	
	cout<<ans<<'\n';
	return 0;
}