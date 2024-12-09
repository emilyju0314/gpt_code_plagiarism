#include <cstdio>
#include <set>

using namespace std;
const int N=100005;
int fa[N],stx[N],sty[N],n,top=0;
set<int> s[N];

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

void insert(int x,int y){
	if (s[x].find(y)!=s[x].end()){
		stx[++top]=x;sty[top]=y;
		s[x].erase(y);
		s[y].erase(x);
		return;
	}
	s[x].insert(y);
	s[y].insert(x);
}

void erase(int x,int y){
	x=find(x);y=find(y);
	if (x==y) return;
	if (s[x].size()<s[y].size()) swap(x,y);
	fa[y]=x;
	for (set<int>::iterator it=s[y].begin();it!=s[y].end();it++){
		int z=find(*it);s[z].erase(y);
		if (z!=x && z!=y) insert(x,z);
	}
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n*2-2;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		insert(x,y);
	}
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=top;i++) erase(stx[i],sty[i]);
	if (top==n-1) printf("YES\n");
		else printf("NO\n");
}