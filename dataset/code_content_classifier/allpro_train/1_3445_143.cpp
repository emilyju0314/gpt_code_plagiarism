#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N=405;

int n,h,a,b,c,d,in[N],out[N],f[N];
bool ok[N],vis[N];

int get(int x) {return f[x]?f[x]=get(f[x]):x;}

void merge(int x,int y) {
	x=get(x);y=get(y);
	if (x==y) return;
	f[y]=x;
}

int main() {
	scanf("%d%d",&n,&h);
	fo(i,1,n) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int l=c?-c:a;l+=h;
		int r=d?d:-b;r+=h;
		in[r]++;out[l]++;
		vis[l]=vis[r]=1;
		merge(l,r);
	}
	fo(i,h+1,h*2) if (in[i]>out[i]) {puts("NO");return 0;}
	fo(i,0,h-1) if (in[i]<out[i]) {puts("NO");return 0;}
	fo(i,0,h*2) ok[get(i)]|=(in[i]!=out[i]);
	fo(i,0,h*2) if (vis[i]&&get(i)==i&&!ok[i]) {puts("NO");return 0;}
	puts("YES");
	return 0;
}