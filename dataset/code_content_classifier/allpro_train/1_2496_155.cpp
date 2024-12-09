#include<bits/stdc++.h>

using namespace std;

#define N 1600000
#define ls (x<<1)
#define rs (x<<1|1)

int n,p,t1,t2,a[N],seg[N],fst[N],mn[N],pos[N],c[N];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",a+i);
		if ((a[i]&1)!=(i&1)){puts("No"); return 0;}
		pos[a[i]]=i;
	}
	for (int i=1;i<=n-2;++i)
		if (a[i]!=i&&a[i+1]!=i+1&&a[i+2]!=i+2){puts("No"); return 0;}
	p=t1=t2=0;
	for (int i=1;i<=n;i+=2) c[++p]=a[i];
	for (int i=1;i<=p;++i)
		if (c[i]>t2) t2=c[i];
		else{
			if (c[i]>t1) t1=c[i];
			else{puts("No"); return 0;}
		}
	p=t1=t2=0;
	for (int i=2;i<=n;i+=2) c[++p]=a[i];
	for (int i=1;i<=p;++i)
		if (c[i]>t2) t2=c[i];
		else{
			if (c[i]>t1) t1=c[i];
			else{puts("No"); return 0;}
		}
	puts("Yes");
	
	return 0;
}
			