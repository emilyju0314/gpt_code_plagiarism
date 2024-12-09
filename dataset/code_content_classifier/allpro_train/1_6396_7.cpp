#include<cstdio>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

char goal[3][3],gx,gy;

char T[3][3],F[3][3],R[3][3]; // top, front, right

int hstar(int ex,int ey,int gx,int gy){
	int cnt=0;
	rep(i,3) rep(j,3) if(!(i==ey && j==ex) && T[i][j]!=goal[i][j]) cnt++;
	return max(cnt,abs(ex-gx)+abs(ey-gy));
}

int ub;
bool dfs(int t,int ex,int ey,int pre){ // 経過ターン, スペースの位置, 直前移動した方向
	bool end=true;
	rep(i,3) rep(j,3) if(!(i==ey && j==ex) && T[i][j]!=goal[i][j]) end=false;
	if(end) return true;

	if(t+hstar(ex,ey,gx,gy)>ub) return false;

	char tmp1,tmp2,tmp3;
	// (ex,ey-1)
	if(ey>0 && pre!=1){
		tmp1=T[ey][ex]=F[ey-1][ex];
		tmp2=F[ey][ex]=T[ey-1][ex];
		tmp3=R[ey][ex]=R[ey-1][ex];
		if(dfs(t+1,ex,ey-1,0)) return true;
		F[ey-1][ex]=tmp1;
		T[ey-1][ex]=tmp2;
		R[ey-1][ex]=tmp3;
	}
	// (ex,ey+1)
	if(ey<2 && pre!=0){
		tmp1=T[ey][ex]=F[ey+1][ex];
		tmp2=F[ey][ex]=T[ey+1][ex];
		tmp3=R[ey][ex]=R[ey+1][ex];
		if(dfs(t+1,ex,ey+1,1)) return true;
		F[ey+1][ex]=tmp1;
		T[ey+1][ex]=tmp2;
		R[ey+1][ex]=tmp3;
	}
	// (ex-1,ey)
	if(ex>0 && pre!=3){
		tmp1=T[ey][ex]=R[ey][ex-1];
		tmp2=F[ey][ex]=F[ey][ex-1];
		tmp3=R[ey][ex]=T[ey][ex-1];
		if(dfs(t+1,ex-1,ey,2)) return true;
		R[ey][ex-1]=tmp1;
		F[ey][ex-1]=tmp2;
		T[ey][ex-1]=tmp3;
	}
	// (ex+1,ey)
	if(ex<2 && pre!=2){
		tmp1=T[ey][ex]=R[ey][ex+1];
		tmp2=F[ey][ex]=F[ey][ex+1];
		tmp3=R[ey][ex]=T[ey][ex+1];
		if(dfs(t+1,ex+1,ey,3)) return true;
		R[ey][ex+1]=tmp1;
		F[ey][ex+1]=tmp2;
		T[ey][ex+1]=tmp3;
	}
	return false;
}

int main(){
	for(int ex,ey;scanf("%d%d",&ex,&ey),ex;){
		ex--; ey--;
		rep(i,3) rep(j,3) {
			scanf(" %c",goal[i]+j);
			if(goal[i][j]=='E') gx=j, gy=i;
			T[i][j]='W';
			F[i][j]='R';
			R[i][j]='B';
		}

		for(ub=(abs(ex-gx)+abs(ey-gy))%2;ub<=30&&!dfs(0,ex,ey,-1);ub+=2);

		printf("%d\n",ub<=30?ub:-1);
	}

	return 0;
}