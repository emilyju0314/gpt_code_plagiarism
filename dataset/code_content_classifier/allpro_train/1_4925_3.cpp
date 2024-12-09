#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
int ans;
int gx,gy,gz;

void dfs(int c,int x,int y,int z){
	ans=min(ans,abs(x-gx)+abs(y-gy)+abs(z-gz)+c);
	/*if(c<3){
		printf("%d %d %d %d\n",c,x,y,z);
	}
	*/
	if(c==10)return;
	if(z!=gz){
		dfs(c+1,n+1-y,x,z);
		dfs(c+1,y,n+1-x,z);
	}else{
		if(z+1<=n)dfs(c+1,x,y,z+1);
		if(z-1>=1)dfs(c+1,x,y,z-1);
	}
	if(y!=gy){
		dfs(c+1,n+1-z,y,x);
		dfs(c+1,z,y,n+1-x);
	}else{
		if(y+1<=n)dfs(c+1,x,y+1,z);
		if(y-1>=1)dfs(c+1,x,y-1,z);
	}
	if(x!=gx){
		dfs(c+1,x,n+1-z,y);
		dfs(c+1,x,z,n+1-y);
	}else{
		if(x+1<=n)dfs(c+1,x+1,y,z);
		if(x-1>=1)dfs(c+1,x-1,y,z);
	}


}

int main(void){
	int sx,sy,sz;
	scanf("%d",&n);
	scanf("%d%d%d",&sx,&sy,&sz);
	sx++;
	sy++;
	sz++;
	scanf("%d%d%d",&gx,&gy,&gz);
	gx++;
	gy++;
	gz++;
	ans=abs(sx-gx)+abs(gy-sy)+abs(sz-gz);
	dfs(0,sx,sy,sz);
	printf("%d\n",ans);
	return 0;
}
