#include <bits/stdc++.h>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define add(a,b) a=((a)+(b))%mod
#define abs(x) ((x)>0?(x):-(x))
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define mod 998244353
#define Mod 998244351
#define ll long long
#define file
using namespace std;

struct type{ll f,g;} ans;
int d[51],A,B,s2,n,N,i,j,k,l,s,sum,X1,X2;
int a[20001][2],pre[20001],t;
type f[20001],F[20001];
ll b[20001],S[20001],x,ss;

ll qpower(ll a,int b) {ll ans=1; while (b) {if (b&1) ans=ans*a%mod;a=a*a%mod;b>>=1;} return ans;}

ll C(ll n,ll m)
{
	int i;
	ll s1=1,s2=1;
	
	fo(i,1,m) s1=s1*(n-i+1)%mod,s2=s2*i%mod;
	return s1*qpower(s2,Mod)%mod;
}
void Add(type &a,type b)
{
	if (b.f>=a.f)
	{
		if (b.f>a.f) a=b;
		else add(a.g,b.g);
	}
}

void init()
{
	static int ls[20001];
	sort(b+1,b+t+1);l=1;
	fo(i,2,t) if (b[i]!=b[l]) b[++l]=b[i];t=l;
	fo(i,1,t-1) S[i]=b[i+1]-b[i];
	
	fo(x,1,t) if (!b[x]) break;
	N=1,a[N][0]=x,a[N][1]=0;
	fo(i,1,n)
	{
		s=abs(d[i]);
		if (d[i]>0) {while (s) ++x,++N,a[N][0]=x,a[N][1]=0,s-=S[x];}
		else {while (s) --x,s-=S[x],++N,a[N][0]=x,a[N][1]=1;}
	}
	fo(i,1,N) pre[i]=ls[a[i][0]],ls[a[i][0]]=i;
}

int main()
{
//	freopen("CF1474F.in","r",stdin);
//	#ifdef file
//	freopen("CF1474F.out","w",stdout);
//	#endif
	
	scanf("%d",&n);
	scanf("%d",&l);x=0;t=2,b[1]=0,b[2]=1;
	fo(i,1,n) scanf("%d",&d[i]),x+=d[i],b[++t]=x,b[++t]=x+1;
	init();
	
	f[N+1]=type{0,1};
	fo(i,1,t) F[i]=type{0,1};
	fd(i,N,1)
	{
		X1=a[i][0],X2=a[i][1];
		if (!X2) Add(f[i],type{F[X1+1].f+S[X1],F[X1+1].g});
		else Add(f[i],type{F[X1+1].f+1,F[X1+1].g*S[X1]%mod});
		
		if (S[X1]>1)
		{
			sum=1;
			for (j=pre[i]; j; j=pre[j])
			{
				++sum;
				A=B=sum/2;
				if (sum&1) {if (!X2) ++A; else ++B;}
				s2=S[X1]-2;B=A-1;
				
				ss=0;
				fo(k,0,min(B,s2)) add(ss,C(B,k)*C((s2-k)+A-1,A-1));
				Add(f[j],type{F[X1+1].f+S[X1],F[X1+1].g*ss%mod});
			}
		}
		Add(F[X1],f[i]);
	}
	fo(i,1,N) Add(ans,f[i]);
	
	printf("%lld %lld\n",ans.f,(ans.g+mod)%mod);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}