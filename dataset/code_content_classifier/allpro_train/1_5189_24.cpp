#include<stdio.h>
#include<string.h>
#include<algorithm>
int v[1024*1024];
void Init(){memset(v,-1,sizeof(v));}
int Root(int x)
{
	return v[x]<0 ? x : v[x]=Root(v[x]);
}
void Link(int x, int y)
{
	x=Root(x);
	y=Root(y);
	if(x-y)
	{
		if(v[x]>v[y])std::swap(x,y);
		v[x]+=v[y];
		v[y]=x;
	}
}

const char FLOOR = '.';
char m[1024][1024];
int ID(int x, int y, int w)
{
	return y*w+x;
}
void UnionFloor(int x,int y,int w)
{
	const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
	if(m[y][x]!=FLOOR)return;
	for(int i=0;i<4; ++i)
	{
		int ax = x+dx[i];
		int ay = y+dy[i];
		if(m[ay][ax]!=FLOOR)continue;
		Link(ID(x,y,w),ID(ax,ay,w));
	}
}
int main()
{
	int w,h,x,y,gx,gy;
	memset(m,0,sizeof(m));
	scanf("%d%d",&w,&h);
	for(y=1;y<=h;++y)
	{
		scanf("%s",&m[y][1]);
		char *p=strchr(&m[y][1],'t');
		if(p)
		{
			gx=p-m[y];
			gy=y;
			*p=FLOOR;
		}
	}
	Init();
	for(y=1;y<=h;++y)
		for(x=1;x<=w;++x)
			UnionFloor(x,y,w);
	if(Root(ID(1,1,w))==Root(ID(gx,gy,w)))
	{
		puts("0");
		return 0;
	}
	int N, res=-1;
	scanf("%d",&N);
	for(int i=0; i<N; ++i)
	{
		scanf("%d%d",&x,&y);
		++x,++y;	//1-org
		m[y][x]=FLOOR;
		UnionFloor(x,y,w);


		if(Root(ID(1,1,w))==Root(ID(gx,gy,w)))
		{
			res=i+1;
			break;
		}
	}
	printf("%d\n",res);
	return 0;
}