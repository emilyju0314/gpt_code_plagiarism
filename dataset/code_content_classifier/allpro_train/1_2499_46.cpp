#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
#define pi pair<int,int>
#define pii pair<pi,int>
#define aa first
#define bb second
#define xx aa.aa
#define yy aa.bb
#define zz bb
#define mp make_pair
#define mpp(a,b,c) mp(mp(a,b),c)
using namespace std;
int n,m;
double x[500010],p;
int y[500010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l,r,w;
	scanf("%d%d",&n,&m);
	l=1;
	r=0;
	for(i=1;i<=n;i++)
	  {
	   scanf("%d%d",&j,&k);
	   if(i>1)
	     {
		  w=k;
		  while(w)
		    if(y[l]<=w)
		      {
			   w-=y[l];
			   p-=x[l]*y[l];
			   l++;
			  }
			else
			  {
			   y[l]-=w;
			   p-=x[l]*w;
			   w=0;
			  }
		 }
	   x[++r]=j;
	   y[r]=k;
	   p+=(L)j*k;
	   while(r>l && x[r]<x[r-1])
	     {
		  x[r-1]=(x[r]*y[r]+x[r-1]*y[r-1])/(y[r]+y[r-1]);
		  y[r-1]+=y[r];
		  r--;
		 }
	   printf("%.10lf\n",p/m);
	  }
	return 0;
}
