#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int S=(1<<20)+5,N=21;

// f[s][i][j]
// (s1<<j)+s2=s,|s1|+|s2|=i

int n,k,f[S][N*(N+1)/2];
char x[S];

int Id(int i,int j) {return i*(i+1)/2+j;}

int main() {
	scanf("%d%d",&n,&k);
	fo(i,0,n) {
		scanf("%s",x);
		fo(j,0,(1<<i)-1) f[j][Id(i,i)]=x[j]=='1';
	}
	fd(i,n,1) 
		fo(s,0,(1<<i)-1) 
			fd(j,i,0)
				if (f[s][Id(i,j)]) {
					int s1=s>>j,s2=s&((1<<j)-1);
					int l1=i-j,l2=j,tmp=f[s][Id(i,j)];
					// none
					if (l2) f[s1][Id(l1,0)]+=tmp;
					// zero
					fd(k,j-1,0) 
						if (!(s2>>k&1)) {
							f[(s1<<k+1)|(s2&((1<<k)-1))][Id(l1+1+k,k)]+=tmp;
							break;
						}
					// one
					fd(k,j-1,0)
						if (s2>>k&1) {
							f[((s1<<1|1)<<k)|(s2&((1<<k)-1))][Id(l1+1+k,k)]+=tmp;
							break;
						}
				}
	fd(i,n,0)
		fo(s,0,(1<<i)-1)
			if (f[s][Id(i,0)]>=k) {
				fd(j,i-1,0) printf("%d",s>>j&1);
				puts("");
				return 0;
			}
	return 0;
}