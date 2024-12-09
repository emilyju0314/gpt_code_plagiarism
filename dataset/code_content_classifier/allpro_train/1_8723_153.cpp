#include<bits/stdc++.h>
#define pll pair<ll,ll>
#define F first
#define S second
#define ll long long
using namespace std;
const int N=405;
long long n,m;char c;
long long ans;
bool a[N][N],f[N][N],o;
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
bool ok(int x2,int y2){return (x2>=0&&y2>=0&&x2<n&&y2<m);}
pll arrive(int x,int y,bool black)
{
	pll p;
	if(black)p.F++;
	else p.S++;
	for(int i=0;i<4;i++)
	{
		int x2=x+dx[i];
		int y2=y+dy[i];
		if(ok(x2,y2)&&!f[x2][y2]&&black!=a[x2][y2])
		{
			f[x2][y2]=true;
			pll j=arrive(x2,y2,!black);
			p.F+=j.F;
			p.S+=j.S;
		}
	}
	return p;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>c;
			a[i][j]=(c=='#'?true:false);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(f[i][j])continue;
			pll p=arrive(i,j,a[i][j]);
			if(a[i][j])p.F--;
			else p.S--;
			ans+=p.F*p.S;
		}
	}
	cout<<ans;
	return 0;
}