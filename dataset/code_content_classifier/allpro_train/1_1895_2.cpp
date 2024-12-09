#include<cstdio>
#include<cstring>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int h,w,B[9][9];

int x2,y2,x3,y3; // 2, 3 それぞれの出発点

int bfs(int x,int y,int tar){
	int d[9][9];
	memset(d,-1,sizeof d);
	d[y][x]=0;
	int Q[81],head=0,tail=0; Q[tail++]=y*w+x;
	while(head<tail){
		int i=Q[head]/w,j=Q[head]%w; head++;
		rep(k,4){
			int yy=i+dy[k],xx=j+dx[k];
			if(0<=yy && yy<h && 0<=xx && xx<w && d[yy][xx]==-1){
				if(B[yy][xx]==tar) return d[i][j]+1;
				if(B[yy][xx]== 0 ) Q[tail++]=yy*w+xx, d[yy][xx]=d[i][j]+1;
			}
		}
	}
	return 777;
}

int ans;
void dfs(int x,int y,int now){
	int hstar=bfs(x,y,2)+bfs(x3,y3,3);
	if(ans<now+1+hstar) return;

	// これまでのパスと接したら枝刈り
	int cnt=0;
	rep(k,4){
		int xx=x+dx[k],yy=y+dy[k];
		if(0<=xx && xx<w && 0<=yy && yy<h && B[yy][xx]==7) cnt++;
	}
	if(cnt>=2) return;

	// 777...777
	// 700...007
	// ?00...00?
	// というパターン ( or 回転/反転して一致するもの ) があれば枝刈り
	for(int L=3;L<=8;L++){
		bool ng;
		if(y>0 && x+L-1<w){
			ng=true;
			if(ng) rep(j,L) if(B[y-1][x+j]!=7) { ng=false; break; }
			if(ng) rep(j,L) if(B[y  ][x+j]!=(j==0||j==L-1?7:0)) { ng=false; break; }
			if(ng && L>=5 && y+1<h) rep(j,L) if(0<j && j<L-1 && B[y+1][x+j]!=0) { ng=false; break; }
			if(ng) return;
		}
		if(y+1<h && x+L-1<w){
			ng=true;
			if(ng && L>=5 && y>0) rep(j,L) if(0<j && j<L-1 && B[y-1][x+j]!=0) { ng=false; break; }
			if(ng) rep(j,L) if(B[y  ][x+j]!=(j==0||j==L-1?7:0)) { ng=false; break; }
			if(ng) rep(j,L) if(B[y+1][x+j]!=7) { ng=false; break; }
			if(ng) return;
		}
		if(y>0 && x-L+1>=0){
			ng=true;
			if(ng) rep(j,L) if(B[y-1][x-j]!=7) { ng=false; break; }
			if(ng) rep(j,L) if(B[y  ][x-j]!=(j==0||j==L-1?7:0)) { ng=false; break; }
			if(ng && L>=5 && y+1<h) rep(j,L) if(0<j && j<L-1 && B[y+1][x-j]!=0) { ng=false; break; }
			if(ng) return;
		}
		if(y+1<h && x-L+1>=0){
			ng=true;
			if(ng && L>=5 && y>0) rep(j,L) if(0<j && j<L-1 && B[y-1][x-j]!=0) { ng=false; break; }
			if(ng) rep(j,L) if(B[y  ][x-j]!=(j==0||j==L-1?7:0)) { ng=false; break; }
			if(ng) rep(j,L) if(B[y+1][x-j]!=7) { ng=false; break; }
			if(ng) return;
		}
		if(y+L-1<h && x>0){
			ng=true;
			if(ng) rep(i,L) if(B[y+i][x-1]!=7) { ng=false; break; }
			if(ng) rep(i,L) if(B[y+i][x  ]!=(i==0||i==L-1?7:0)) { ng=false; break; }
			if(ng && L>=5 && x+1<w) rep(i,L) if(0<i && i<L-1 && B[y+i][x+1]!=0) { ng=false; break; }
			if(ng) return;
		}
		if(y+L-1<h && x+1<w){
			ng=true;
			if(ng && L>=5 && x>0) rep(i,L) if(0<i && i<L-1 && B[y+i][x-1]!=0) { ng=false; break; }
			if(ng) rep(i,L) if(B[y+i][x  ]!=(i==0||i==L-1?7:0)) { ng=false; break; }
			if(ng) rep(i,L) if(B[y+i][x+1]!=7) { ng=false; break; }
			if(ng) return;
		}
		if(y-L+1>=0 && x>0){
			ng=true;
			if(ng) rep(i,L) if(B[y-i][x-1]!=7) { ng=false; break; }
			if(ng) rep(i,L) if(B[y-i][x  ]!=(i==0||i==L-1?7:0)) { ng=false; break; }
			if(ng && L>=5 && x+1<w) rep(i,L) if(0<i && i<L-1 && B[y-i][x+1]!=0) { ng=false; break; }
			if(ng) return;
		}
		if(y-L+1>=0 && x+1<w){
			ng=true;
			if(ng && L>=5 && x>0) rep(i,L) if(0<i && i<L-1 && B[y-i][x-1]!=0) { ng=false; break; }
			if(ng) rep(i,L) if(B[y-i][x  ]!=(i==0||i==L-1?7:0)) { ng=false; break; }
			if(ng) rep(i,L) if(B[y-i][x+1]!=7) { ng=false; break; }
			if(ng) return;
		}
	}

	for(int k=3;k>=0;k--){
		int xx=x+dx[k],yy=y+dy[k];
		if(0<=xx && xx<w && 0<=yy && yy<h){
			if(B[yy][xx]==2){
				ans=now+1+bfs(x3,y3,3);
				return;
			}
			else if(B[yy][xx]==0){
				B[yy][xx]=7;
				dfs(xx,yy,now+1);
				B[yy][xx]=0;
			}
		}
	}
}

int main(){
	while(scanf("%d%d",&h,&w),h){
		rep(i,h) rep(j,w) scanf("%d",B[i]+j);

		rep(i,h) rep(j,w) {
			if(B[i][j]==2) x2=j, y2=i;
			if(B[i][j]==3) x3=j, y3=i;
		}
		B[y2][x2]=7; // 訪問済みのマーク

		ans=777;
		dfs(x2,y2,0);
		printf("%d\n",ans<777?ans:0);
	}

	return 0;
}