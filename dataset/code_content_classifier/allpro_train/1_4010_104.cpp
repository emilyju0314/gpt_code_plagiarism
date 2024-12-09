#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int T,n;
ll d[N],ans,q;
template<class T>
void Read(T &x)
{
	x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar());
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	return;
}
int main()
{
	Read(T);
	while(T--)
	{
		Read(n);q=ans=0;
		for(int i=1;i<=n;i++) Read(d[i]);
		sort(d+1,d+n+1);
		for(ll i=1;i<=n;i++) ans+=q-(i-1)*d[i],q+=d[i];
		ans+=d[n];
		printf("%lld\n",ans);
	}
	return 0;
} 