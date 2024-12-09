#include <bits/stdc++.h>
using namespace std;
int gi(){
    char ch=getchar(); int x=0,q=0;
    while(ch<'0'||ch>'9') q=ch=='-'?1:q,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return q?-x:x;
}
const int N=401,M=1e5+50;
bitset<N>f[N];
int a[M],b[M],vis[N];
int main(){
    int n=gi(),m=gi(),x,y;
    for (int i=1; i<=m; ++i)
	a[i]=gi(),b[i]=gi();
    for (int i=1; i<=n; ++i)
	f[i].set(i);
    for (int i=m; i>=1; --i){
	x=a[i],y=b[i];
	for (int t=1; t<=n; ++t)
	    if (f[t][x]||f[t][y]){
		if (f[t][y]) swap(x,y);
		if (f[t][y]) vis[t]=1;
		else f[t].set(y);
	    }
    }
    int ans=0;
    for (int i=1; i<=n; ++i)
	if (!vis[i])
	    for (int j=i+1; j<=n; ++j)
		if (!vis[j]&&(f[i]&f[j]).count()==0)
		    ++ans;
    cout<<ans;
    return 0;
}
