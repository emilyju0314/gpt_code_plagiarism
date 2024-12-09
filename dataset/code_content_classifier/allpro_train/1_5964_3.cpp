#include<cstdio>
#include<vector>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int h,w,capa,a[20][20];
bool live[20][20];

bool check(int wall){ // 壁の高さの最小値
	bool vis[20][20]={};
	rep(i,h) rep(j,w) if(!vis[i][j] && a[i][j]<wall) {
		vis[i][j]=true;

		int sum=0;
		bool ok=true;
		int Q[20*20],head=0,tail=0;
		Q[tail++]=i*w+j;
		while(head<tail){
			int y=Q[head]/w,x=Q[head]%w; head++;

			if(live[y][x] || y==0 || y==h-1 || x==0 || x==w-1) ok=false;
			sum+=wall-a[y][x];

			rep(k,4){
				int yy=y+dy[k],xx=x+dx[k];
				if(0<=yy && yy<h && 0<=xx && xx<w && !vis[yy][xx] && a[yy][xx]<wall){
					vis[yy][xx]=true;
					Q[tail++]=yy*w+xx;
				}
			}
		}

		if(ok && sum>=capa) return true;
	}

	return false;
}

int main(){
	for(int m;scanf("%d%d%d%d",&h,&w,&capa,&m),h;){
		rep(i,h) rep(j,w) {
			scanf("%d",a[i]+j);
			live[i][j]=false;
		}
		rep(i,m){
			int y,x; scanf("%d%d",&y,&x); y--; x--;
			live[y][x]=true;
		}

		vector<int> as;
		rep(i,h) rep(j,w) {
			as.push_back(a[i][j]);
			as.push_back(a[i][j]+1);
		}
		sort(as.begin(),as.end());
		as.erase(unique(as.begin(),as.end()),as.end());

		rep(i,as.size()){
			if(check(as[i])) goto FOUND;
			rep(y,h) rep(x,w) if(!live[y][x]) {
				a[y][x]++;
				if(check(as[i])) goto FOUND;
				a[y][x]--;
			}
		}

		puts("No");
		continue;

		FOUND:
		puts("Yes");
	}

	return 0;
}