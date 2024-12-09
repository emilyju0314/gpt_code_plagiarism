#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int MAXX=200100;
int head[MAXX],ver[MAXX<<1],nxt[MAXX<<1],ind[MAXX][2];
int n,m,tot,cnt;
bool vis[MAXX];
char s[MAXX];
queue<int>q;
inline void add(int x,int y){
	s[x]=='A' ? ++ind[y][0] : ++ind[y][1];
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
inline void topsort(){
	for(int i=1;i<=n;++i)if((!ind[i][0])||(!ind[i][1])){
		q.push(i);
		vis[i]=1;
		cnt++;
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nxt[i]){
			int y=ver[i];
			s[x]=='A' ? --ind[y][0] : --ind[y][1];
            if((!ind[y][0])||(!ind[y][1])){
            	if(vis[y])continue;
            	vis[y]=1;
            	q.push(y);
            	cnt++;
            }
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
    for(int i=1;i<=m;++i){
    	int x,y;
    	scanf("%d%d",&x,&y);
    	add(x,y);
    	add(y,x);
    }
    topsort();
    if(cnt==n)printf("No\n");
    else printf("Yes\n");
    return 0;
}