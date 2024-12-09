#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int m[210][210];
int p[1100];
int q[1100];
int dx[2][7]={{0,1,1,0,-1,-1,0},{0,1,1,0,-1,-1,0}};
int dy[2][7]={{1,0,-1,-1,-1,0,0},{1,1,0,-1,0,1,0}};
int ijk[210][210][6];
int v[210][210][6];
int ABS(int a){return max(a,-a);}
int main(){
	int sr,sc,gr,gc;
	scanf("%d%d%d%d",&sr,&sc,&gr,&gc);
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d%d",p+i,q+i);
	}
	int H,W;
	scanf("%d%d",&H,&W);
	for(int i=0;i<a;i++){
		m[p[i]+H][q[i]+W]=1;
	}
	for(int i=0;i<=2*H;i++)for(int j=0;j<=2*W;j++)for(int k=0;k<6;k++)
		ijk[i][j][k]=999999999;
	deque<pair<pair<int,int>,pair<int,int> > > Q;
	Q.push_back(make_pair(make_pair(0,0),make_pair(sr,sc)));
	ijk[sr+H][sc+W][0]=0;
	while(Q.size()){
		int cost=Q.front().first.first;
		int dir=Q.front().first.second;
		int row=Q.front().second.first;
		int col=Q.front().second.second;
		int ty=ABS(row)%2;
		Q.pop_front();
		if(v[row+H][col+W][dir])continue;
		v[row+H][col+W][dir]=1;
		int to=ABS(dir*row*col)%6;
		for(int i=0;i<7;i++){
			if(row+dx[ty][i]<-H||row+dx[ty][i]>H||col+dy[ty][i]<-W||
			col+dy[ty][i]>W)continue;
			int tr=row+dx[ty][i];
			int tc=col+dy[ty][i];
			if(m[tr+H][tc+W])continue;
			if(to==i){
				if(ijk[tr+H][tc+W][(dir+1)%6]>cost){
					ijk[tr+H][tc+W][(dir+1)%6]=cost;
					Q.push_front(make_pair(make_pair(cost,(dir+1)%6),make_pair(tr,tc)));
				}
			}else{
				if(ijk[tr+H][tc+W][(dir+1)%6]>cost+1){
					ijk[tr+H][tc+W][(dir+1)%6]=cost+1;
					Q.push_back(make_pair(make_pair(cost+1,(dir+1)%6),make_pair(tr,tc)));
				}
			}
		}
	}
	int ret=999999999;
	for(int i=0;i<6;i++)ret=min(ret,ijk[gr+H][gc+W][i]);
	if(ret>99999999)printf("-1\n");
	else printf("%d\n",ret);
}