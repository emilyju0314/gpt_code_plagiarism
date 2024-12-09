#include<bits/stdc++.h>
#define M 100007
using namespace std;
int n,m,s,t;
vector<int>q[M];
struct no{
	int a,step;
};
bool flag[M][3];
int spfa(int s,int t){
	queue<no>Q;
	Q.push((no)<%s,0%>);
	while(!Q.empty()){
		no z=Q.front();
		Q.pop();
		if(z.a==t&&z.step%3==0)return z.step/3;
		for(int i=0;i<(int)q[z.a].size();i++){
			if(flag[q[z.a][i]][(z.step+1)%3])continue;
			flag[q[z.a][i]][(z.step+1)%3]=1;
			Q.push((no)<%q[z.a][i],z.step+1%>);
		}
	}
	return -1;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		q[u].push_back(v);
	}
	scanf("%d%d",&s,&t);
	printf("%d\n",spfa(s,t));
	return 0;
}