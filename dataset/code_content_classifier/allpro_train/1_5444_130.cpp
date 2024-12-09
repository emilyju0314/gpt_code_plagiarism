#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int w, h;
string b[20];
int step[20][20];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int x, int y){
	memset(step, -1, sizeof(step));
	queue< pair<int, int> > qu; qu.push(make_pair(x,y));
	step[x][y] = 0;
	while(!qu.empty()){
		pair<int, int> pr = qu.front(); qu.pop();
		int cx = pr.first, cy = pr.second;
		for(int i=0;i<4;i++){
			int nx = cx+dx[i], ny = cy+dy[i];
			if(nx<0||h<=nx||ny<0||w<=ny||b[nx][ny]=='x'||step[nx][ny]!=-1) continue;
			step[nx][ny] = step[cx][cy]+1;
			qu.push(make_pair(nx,ny));
		}
	}
}

int main(){
	int c[11][11];
	while(cin >> w >> h, w){
		for(int i=0;i<h;i++) cin >> b[i];
		vector<int> x(1), y(1);
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(b[i][j]=='o') x[0] = i, y[0] = j;
				if(b[i][j]=='*') x.push_back(i), y.push_back(j);
			}
		}
		int res = 1000000000;
		for(int i=0;i<x.size();i++){
			bfs(x[i], y[i]);
			for(int j=0;j<x.size();j++){
				c[i][j] = step[x[j]][y[j]];
				if(c[i][j]==-1) res = -1;
			}
		}
		if(res != -1){
			vector<int> a(x.size()-1);
			for(int i=0;i<x.size()-1;i++) a[i] = i+1;
			do{
				int cur = c[0][a[0]];
				for(int i=0;i+1<a.size();i++) cur += c[a[i]][a[i+1]];
				res = min(res, cur);
			}while(next_permutation(a.begin(), a.end()));
		}
		cout << res << endl;
	}
}