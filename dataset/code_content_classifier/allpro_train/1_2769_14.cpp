#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int h,w;
long long a,b;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,1,0,-1,1,-1,1,-1};
int COS[]={1,1,1,1,2,2,2,2};
string s[1111];
long dis[1111][1111];
int main()
{
	cin>>h>>w>>a>>b;
	int sx,sy;
	for(int i=0;i<h;i++)
	{
		cin>>s[i];
		for(int j=0;j<w;j++)if(s[i][j]=='s')
		{
			sx=i;
			sy=j;
		}
	}
	for(int i=0;i<h;i++)for(int j=0;j<w;j++)dis[i][j]=9e18;
	priority_queue<pair<long,pair<int,int> > >P;
	P.push({0,{sx,sy}});
	dis[sx][sy]=0;
	while(!P.empty())
	{
		long cost=-P.top().first;
		int x=P.top().second.first,y=P.top().second.second;
		P.pop();
		if(dis[x][y]<cost)continue;
		if(s[x][y]=='g')
		{
			cout<<cost<<endl;
			return 0;
		}
		for(int r=0;r<4;r++)
		{
			int tx=x+dx[r],ty=y+dy[r];
			if(tx<0||ty<0||tx>=h||ty>=w||s[tx][ty]=='#'||dis[tx][ty]<=cost+a)continue;
			dis[tx][ty]=cost+a;
			P.push({-cost-a,{tx,ty}});
		}
		bool flag=1;
		for(int r=0;r<8;r++)
		{
			int tx=x+dx[r],ty=y+dy[r];
			flag&=tx<0||ty<0||tx>=h||ty>=w||s[tx][ty]!='*';
		}
		flag&=s[x][y]!='*';
		if(flag)
		{
			for(int r=0;r<8;r++)
			{
				int tx=x+dx[r],ty=y+dy[r];
				int nowcos=cost+b+COS[r]*a;
				if(tx<0||ty<0||tx>=h||ty>=w||dis[tx][ty]<=nowcos)continue;
				dis[tx][ty]=nowcos;
				P.push({-nowcos,{tx,ty}});
			}
		}
	}
	cout<<"INF"<<endl;
}

