#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define LL long long
using namespace std;
int n,m;struct Data
{
	int a,b,p;I bool operator < (Con Data& o) Con {return 1LL*p*a+1LL*(m-p)*b>1LL*o.p*o.a+1LL*(m-o.p)*o.b;}
}s[N+5];
class FastIO
{
	private:
		#define FS 100000
		#define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
		#define D isdigit(c=tc())
		char c,*A,*B,FI[FS];
	public:
		I FastIO() {A=B=FI;}Tp I void read(Ty& x) {x=0;W(!D);W(x=(x<<3)+(x<<1)+(c&15),D);}
}F;
#define V(i,v) (v<=s[i].p?1LL*v*s[i].a:1LL*s[i].p*s[i].a+1LL*(v-s[i].p)*s[i].b)
I bool Check(Con LL& w)
{
	RI i,x=w/m,y=w%m;LL t=0;for(i=1;i<=x;++i) t+=1LL*(m-s[i].p)*s[i].b;for(;i<=n;++i) t-=1LL*s[i].p*s[i].a;
	for(i=x+1;i<=n;++i) if(t+V(i,y)>=0) return 1;for(i=1;i<=x;++i) if(t+V(x+1,m)-V(i,m)+V(i,y)>=0) return 1;return 0;
}
int main()
{
	RI i;for(F.read(n),F.read(m),i=1;i<=n;++i) F.read(s[i].p),F.read(s[i].a),F.read(s[i].b);
	sort(s+1,s+n+1);LL l=0,r=1LL*n*m,mid;W(l<r) Check(mid=l+r-1>>1)?r=mid:l=mid+1;return printf("%lld\n",r),0;
}