#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#define INF 1000000000

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<P, P> PP;

int main()
{
	int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1, 0};
	while(1){
		int w, h;
		cin>>w>>h;
		if(w==0 && h==0) return 0;
		int s[30][30];
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				cin>>s[i][j];
			}
		}
		int c[4];
		for(int i=0; i<4; i++){
			cin>>c[i];
		}
		int d[4][30][30];
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				for(int k=0; k<4; k++){
					d[k][i][j]=INF;
				}
			}
		}
		d[0][0][0]=0;
		priority_queue<PP, vector<PP>, greater<PP> > que;
		que.push(PP(P(0, 0), P(0, 0)));
		while(!que.empty()){
			PP p=que.top();
			que.pop();
			int k=p.first.second;
			int x=p.second.first;
			int y=p.second.second;
			for(int i=0; i<4; i++){
				int t=c[i];
				if(s[x][y]==i) t=0;
				if(!(x+dx[(k+i)%4]>=0 && x+dx[(k+i)%4]<h && y+dy[(k+i)%4]>=0 && y+dy[(k+i)%4]<w)) continue;
				if(d[(k+i)%4][x+dx[(k+i)%4]][y+dy[(k+i)%4]]>d[k][x][y]+t){
					d[(k+i)%4][x+dx[(k+i)%4]][y+dy[(k+i)%4]]=d[k][x][y]+t;
					que.push(PP(P(d[(k+i)%4][x+dx[(k+i)%4]][y+dy[(k+i)%4]], (k+i)%4), P(x+dx[(k+i)%4], y+dy[(k+i)%4])));
				}
			}
		}
		int ans=INF;
		for(int i=0; i<4; i++){
			if(d[i][h-1][w-1]<ans) ans=d[i][h-1][w-1];
		}
		cout<<ans<<endl;
	}			
	return 0;
}
