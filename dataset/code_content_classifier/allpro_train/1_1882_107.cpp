#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int n,q,vis[maxn];
ll m,s,cnt;
struct node {
	int x,y,z;
} d[maxn];
struct Seg {
	int fa[maxn],sz[maxn];
	void init() {
		for (int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	}
	int find(int x) {
		if (fa[x]==x) return x;
		return fa[x]=find(fa[x]);
	}
	void connect(int x,int y) {
		x=find(x); y=find(y);
		if (x==y) return;
		fa[x]=y; sz[y]+=sz[x];
	}
} A,B;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); read(q);
	int x,y,z,flag=0; A.init();
	for (int i=1;i<=q;i++) {
		read(x); read(y); read(z);
		x++; y++;
		d[i].x=x; d[i].y=y; d[i].z=z;
		if (!z) A.connect(x,y);
	}
	for (int i=1;i<=q;i++) {
		x=d[i].x; y=d[i].y; z=d[i].z;
		if (!z) continue;
		x=A.find(x); y=A.find(y);
		if (x==y) { printf("No\n"); return 0; }
		flag=1;
	}
	for (int i=1;i<=n;i++)
		if (A.find(i)==i) cnt++;
	if (m==n-1) {
		if (flag) printf("No\n");
		else printf("Yes\n");
		return 0;
	}
	if (m-(n-cnt)<=cnt*(cnt-1)/2) printf("Yes\n");
	else printf("No\n");
	return 0;
}