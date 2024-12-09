#include<bits/stdc++.h>
#define llong long long
#define mkpr make_pair
#define x first
#define y second
#define iter iterator
#define riter reversed_iterator
#define y1 Lorem_ipsum_
#define tm dolor_sit_amet_
using namespace std;

inline int read()
{
	int x = 0,f = 1; char ch = getchar();
	for(;!isdigit(ch);ch=getchar()) {if(ch=='-') f = -1;}
	for(; isdigit(ch);ch=getchar()) {x = x*10+ch-48;}
	return x*f;
}

const int mxN = 50;
int a[mxN+3];
llong stax[(1<<18)+3],stay[(1<<18)+3];
llong comb[mxN+3][mxN+3],f[mxN+3];
int bitcnt[(1<<25)+3];
int n,m,A,B,mx;

llong Bitcnt(llong x) {return bitcnt[x>>25]+bitcnt[x&((1ll<<25)-1)];}

int main()
{
	comb[0][0] = 1ll; for(int i=1; i<=mxN; i++) {comb[i][0] = comb[i][i] = 1ll; for(int j=1; j<i; j++) comb[i][j] = comb[i-1][j]+comb[i-1][j-1];}
	for(int i=1; i<(1<<25); i++) bitcnt[i] = bitcnt[i>>1]+(i&1);
	n = read(),m = read(),A = read(),B = read();
	for(int i=0; i<=n; i++) for(int j=1; j<=m; j++) {f[i] += comb[i][j];}
	for(int i=0; i<n; i++) a[i] = read();
	mx = (1<<18)-1;
	if((A&B)!=A) {puts("0"); return 0;}
	for(int i=0; i<=mx; i++)
	{
		for(int j=0; j<n; j++) {if((a[j]&i)==i) {stax[i] |= (1ll<<j);} if((a[j]|i)==i) {stay[i] |= (1ll<<j);}}
	}
	llong ans = 0ll;
	for(int i=A; i<=mx; i=(i+1)|A)
	{
		if((B&i)!=i) continue;
		for(int j=B^i; j>=0; j=(j==0?-1:(j-1)&(B^i)))
		{
			llong coe = (bitcnt[A]-bitcnt[i]+bitcnt[j|i]-bitcnt[B])&1,tmp = f[Bitcnt(stax[i]&stay[j|i])];
			coe?ans-=tmp:ans+=tmp;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
19 17 12296 14429
98556 131974 245670 63659 206158 29342 236386 8051 718 178812 253316 41592 210524 106503 146207 192609 81118 92232 133769 
*/