#include<bits/stdc++.h>
#define maxn 1000100
using namespace std;
int n,sum[maxn*2],tp,m,a[maxn],f[maxn];
char s[maxn];
int g(int x){
	return x<0?x+26:x;
}
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
	scanf("%s%d",s+1,&n);
	int m=strlen(s+1);
	for(int i=1;i<=m;++i)s[i]-='a',f[i]=i;
	f[m+1]=m+1;
	for(int i=m+1;i>=1;--i)s[i]=g(s[i]-s[i-1]);
	for(int i=1,l,r;i<=n;++i)
		scanf("%d%d",&l,&r),f[find(l)]=find(r+1);
	for(int i=1;i<=m-i+2;++i)f[find(i)]=find(m+2-i);
	for(int i=1;i<=m+1;++i)sum[find(i)]+=s[i];
	for(int i=1;i<=m+1;++i)if(i==find(i)&&sum[i]%26)return puts("NO"),0;
	puts("YES");
}