#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<string.h>
#include <stdlib.h>
using namespace std;

int W,H;
struct Node{
	int x,y,cost,dir;
	Node(int p_x,int p_y,int p_c,int p_dir){
		x=p_x;y=p_y;dir=p_dir;cost=p_c;
	}
};

bool operator < (Node a,Node b){
	return a.cost>b.cost;
};

bool in(int x,int y){
	if(x<0 || y<0 || x>=W || y>=H) return false;
	return true;
}

int solve(){
	vector<vector<char> > M(H,vector<char>(W));
	vector<int> S;

	for(int y=0;y<H;y++){
		for(int x=0;x<W;x++){
			char c;
			cin>>c;
			M[y][x]=c;
			if(c=='S'){
				S.push_back(x);
			}
		}
	}

	priority_queue<Node> Q;
	int cost[2][60][30];
	memset(cost,-1,sizeof(cost));

	for(int i=0;i<S.size();i++){
		Q.push(Node(S[i],H-1,0,0));
		Q.push(Node(S[i],H-1,0,1));
	}
	while(!Q.empty()){
		Node t=Q.top();
		Q.pop();
		if(cost[t.dir][t.y][t.x]>=0) continue;
		cost[t.dir][t.y][t.x]=t.cost;
		int mul,next;
		if(t.dir==0){mul=1;next=1;}
		else{mul=-1;next=0;}

		for(int x=1;x<=3;x++){
			for(int y=-2;y<=2;y++){
				if(x+abs(y)>3) continue;
				int nx=t.x+x*mul;
				int ny=t.y+y;
				if(!in(nx,ny)) continue;

				if(M[ny][nx]=='T') return t.cost;
				if(!isdigit(M[ny][nx])) continue;

				Q.push(Node(nx,ny,t.cost+M[ny][nx]-'0',next));
			}
		}
	}
	return -1;
}

int main()
{
	while(cin>>W>>H){
		if(W==0) return 0;
		cout<<solve()<<endl;
	}
}