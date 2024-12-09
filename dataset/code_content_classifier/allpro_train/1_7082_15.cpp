#include <bits/stdc++.h>
using namespace std;

int read(){
	int x=0; char c; int flag=1;
	for(c=getchar();!isdigit(c);c=getchar()) if(c=='-') flag=-1;
	for(;isdigit(c);c=getchar()) x=((x+(x<<2))<<1)+(c^48);
	return x*flag;
}

const int N=505;
int n;

struct node{
    int id,v;
}a[N];
bool cmp(node a,node b) { return a.v<b.v; }

int f[N*N];
int ps;

int main() {
    n=read();
    for(int i=1;i<=n;i++) a[i].v=read(),a[i].id=i,f[a[i].v]=i;
    
    sort(a+1,a+n+1,cmp);
    
    bool flag=1;
    ps=0;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=a[i].id-1;j++) 
		{ while(f[ps+1]) ps++; f[ps+1]=a[i].id; }
	    if(ps>=a[i].v) { flag=0; break; }
	}
	if(!flag) { puts("No"); return 0; }
	
	ps=n*n+1;
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n-a[i].id;j++)
		{ while(f[ps-1]) ps--; f[ps-1]=a[i].id; }
	    if(ps<=a[i].v) { flag=0; break; }
	}
	if(!flag) { puts("No"); return 0; }
	
	puts("Yes");
	for(int i=1;i<=n*n;i++) printf("%d ",f[i]);
	return 0;
}
