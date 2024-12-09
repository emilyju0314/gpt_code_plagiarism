#include<bits/stdc++.h>
using namespace std;
int n,m,q,val[20],res;
struct quar{
	int a,b,c,d;
	void read(){
		scanf("%d%d%d%d",&a,&b,&c,&d);
	}
}p[100];
void dfs(int pos,int lim){
	if(pos>n){
		int tot=0;
		for(int i=1;i<=q;i++)if(val[p[i].b]-val[p[i].a]==p[i].c)tot+=p[i].d;
		res=max(res,tot);
		return;
	}
	for(int i=lim;i<=m;i++)val[pos]=i,dfs(pos+1,i);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++)p[i].read();
	dfs(1,1);
	printf("%d\n",res);
	return 0;
}