#include<bits/stdc++.h>
using namespace std;
int n;
int a[10],A,B,C;
int k[10],u[4],U[4];
int add,ans=2e9+7;

void dfs(int x){
	if(x>n){
		add=0;
		for(int i=1;i<=3;i++) u[i]=0,U[i]=0;
		for(int i=1;i<=n;i++){
			if(k[i]>0) u[k[i]]++,U[k[i]]+=a[i];
		}
		if(u[1]==0||u[2]==0||u[3]==0) return;
		add+=10*(u[1]+u[2]+u[3]-3);
		add+=abs(A-U[1])+abs(B-U[2])+abs(C-U[3]);
		ans=min(ans,add);
		return;
	}
	k[x]=0;dfs(x+1);
	k[x]=1;dfs(x+1);
	k[x]=2;dfs(x+1);
	k[x]=3;dfs(x+1);
}

int main(){
	scanf("%d",&n);
	scanf("%d %d %d",&A,&B,&C);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1);
	printf("%d\n",ans);
	
	return 0;
}