#include<bits/stdc++.h>
using namespace std;
#define N 1116

int n,m,h[N],c[N],ans;
queue<int> a[N];

int read(){
	int x=0,f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-f;
	for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			a[i].push(read());
	ans=0x3fffffff;
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++)
			while (h[a[j].front()]) a[j].pop();
		fill(c+1,c+m+1,0);
		for (int j=1;j<=n;j++)
			c[a[j].front()]++;
		int t=1;
		for (int j=1;j<=m;j++)
			if (c[j]>c[t]) t=j;
		h[t]=1;ans=min(ans,c[t]);
	}
	printf("%d\n",ans);
	return 0;
}