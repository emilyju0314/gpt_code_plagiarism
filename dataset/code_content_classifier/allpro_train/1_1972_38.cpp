#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector> 
#include<bits/stdc++.h>
using namespace std;
int q[510][510];
int n,m;
int ans;
struct data{
	int i,j;
	int x,y;
}qwq[1000010];
signed main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%d",&q[i][j]);
	for(int i=1;i<n;i++)
	  for(int j=1;j<=m;j++)
	  	{
	  	if(q[i][j]&1) 
		  	{
		  	q[i+1][j]++;
			qwq[++ans].i=i;
			qwq[ans].j=j;
			qwq[ans].x=i+1;
			qwq[ans].y=j;	
			}
		}
	  	
	for(int j=1;j<m;j++) 
		if(q[n][j]&1) 
			{
			q[n][j+1]++;
			qwq[++ans].i=n;
			qwq[ans].j=j;
			qwq[ans].x=n;
			qwq[ans].y=j+1;	
			}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++) printf("%d %d %d %d\n",qwq[i].i,qwq[i].j,qwq[i].x,qwq[i].y); 	
	return 0;
}