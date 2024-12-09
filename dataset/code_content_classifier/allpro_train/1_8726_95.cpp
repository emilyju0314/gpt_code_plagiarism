#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1);
const int maxn=200001;
struct node{
	int x,y;
	friend bool operator<(node a,node b)
	{
		return a.x==b.x?a.y<b.y:a.x<b.x;
	}
}p[maxn];
int n,sx,sy,tx,ty,_x,_y,top=0,tot=0,s[maxn];
double ans;
bool ok1=false,ok2=false;
int main()
{
	cin>>sx>>sy>>tx>>ty>>n;
	if(sx>tx)
	{
		sx=-sx;
		tx=-tx;
		ok1=true;
	}
	if(sy>ty)
	{
		sy=-sy;
		ty=-ty;
		ok2=true;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>_x>>_y;
		_x*=ok1?-1:1;
		_y*=ok2?-1:1;
		if(_x>=sx&&_x<=tx&&_y>=sy&&_y<=ty)
		{
			p[++top].x=_x;
			p[top].y=_y;
		}
	}
	sort(p+1,p+top+1);
	for(int i=1;i<=top;i++)
	{
		if(!tot||p[i].y>s[tot])
		{
			s[++tot]=p[i].y;
		}
		else
		{
			int nw=lower_bound(s+1,s+tot+1,p[i].y)-s;
			s[nw]=p[i].y;
		}
	}
	ans=(double)(tx-sx+ty-sy)*100.0-(double)tot*(20.0-PI*5.0)+((tot==min(tx-sx+1,ty-sy+1))?PI*5.0:0);
	printf("%.15lf",ans);
	return 0;
}
