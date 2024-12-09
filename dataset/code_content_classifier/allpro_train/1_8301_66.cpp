#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define INF (1<<25)

struct P{
	int x,y;
	P(int a,int b){x = a , y = b;}
	P(){}
};
struct NODE{
	int x,y,cost,cur,id;
	NODE(P a,int c,int d,int b){
		x = a.x , y = a.y , cost = c , cur = d , id = b;
	}
};
bool operator<(const NODE &a,const NODE &b){
	return a.cost > b.cost;
}
#define next(n) ((n+1)%5)

int getCost(P a,P b){
	return abs(a.x-b.x)+abs(a.y-b.y);
}
int main(){
	int W,H;
	while(cin >> W >> H,W){
		vector<P> pos[5];
		P goal,start;
		rep(i,H)rep(j,W){
			char c;
			cin >> c;
			if(c == 'S')start = P(j,i);
			else if(c == 'G')goal = P(j,i);
			else if(c != '.')pos[c-'1'].push_back(P(j,i));
		}
		int ans = INF , choice = -1;
		rep(X,5){
			priority_queue<NODE> Q;
			Q.push(NODE(start,0,X,1023));
			int dijk[5][1024];
			rep(i,5)rep(j,1024)dijk[i][j] = INF;
			while(Q.size()){
				NODE q = Q.top(); Q.pop();
				
				if(q.cur == -1){
					if( q.cost < ans ){
						ans = q.cost;
						choice = X;
					}
					break;
				}
				
				if( next(q.cur) == X){
					Q.push(NODE(goal,q.cost+getCost(P(q.x,q.y),goal),-1,1023));
					continue;
				}
				rep(i,pos[next(q.cur)].size()){
					NODE t = NODE(pos[next(q.cur)][i] , q.cost+getCost(P(q.x,q.y),pos[next(q.cur)][i]) , next(q.cur) , i);
					if( t.cost < dijk[t.cur][t.id]){
						dijk[t.cur][t.id] = t.cost;
						Q.push(t);
					}
				}
			}
		}
		if(~choice)cout << choice+1 << " " << ans << endl;
		else cout << "NA" << endl; 
	}
}