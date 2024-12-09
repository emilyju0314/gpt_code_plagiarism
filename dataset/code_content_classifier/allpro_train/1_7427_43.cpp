#include<bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
#define fr first
#define se second
using namespace std;
typedef long long ll;
const int N=1e5+100;
pii a[N];
set<int>S[3];
map<int,int>H[3];
int n,X,Y,Z,sz[3],ssz[3];
ll ans=0,tmp,ans1[N],ans2[N];
inline bool cmp(pii a,pii b){return a.fr-a.se<b.fr-b.se;}
void Erase(int x,int ty)
{
	if(H[ty][x]==1)S[ty].erase(x);
	H[ty][x]--;
	ans-= x;
	ssz[ty]--;
}
void Insert(int x,int ty)
{
	if(!H[ty][x])S[ty].insert(x);
	H[ty][x]++;
	ans+=x;
	ssz[ty]++;
}
void S_insert(int x,int ty)
{
	if(ssz[ty]==sz[ty])
	{
		int y=*S[ty].begin();
		if(y>x)return;
		Erase(y,ty);
	}
	Insert(x,ty);
}
int main()
{
	scanf("%d%d%d",&X,&Y,&Z);
	n=X+Y+Z;
	for(int i=1,x,y,z;i<=n;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		x-=z;y-=z;
		ans+=z;
		a[i]=mp(x,y);
	}
	tmp=ans;ans=0;
	sort(a+1,a+n+1,cmp);
	sz[0]=X;sz[1]=Y;
	for(int i=1;i<=Y;i++)S_insert(a[i].se,1);
	ans1[Y]=ans;
	for(int i=Y+1;i<=n-X;i++)S_insert(a[i].se,1),ans1[i]=ans;
	ans=0;
	for(int i=n;i>=n-X+1;i--)S_insert(a[i].fr,0);
	ans2[n-X+1]=ans;
	for(int i=n-X;i>=Y+1;i--)S_insert(a[i].fr,0),ans2[i]=ans;
	ans=-1e18;
	for(int i=Y;i<=n-X;i++)ans=max(ans,ans1[i]+ans2[i+1]);
	cout<<ans+tmp;
}