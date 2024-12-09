#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
int N,M,p[11];

int dfs(int n,int f,int pra)
{
	int t,r=-1;
	if(pra>M)return -1;
	if(n==N)
		return 0;
	for(int i=f;i<10;i++)
	{
		t=dfs(n+1,f,pra+p[i]);
		if(t!=-1)return t+i*(pow(10.0,N-n));
	}
	return -1;
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<10;i++)
		scanf("%d",&p[i]);
	int r=dfs(0,0,0);
	if(r==-1)puts("NA");
	else
	{
		char x[]="%0xd\n";
		x[2]=N+'0';

		printf(x,r/10);
	}
}
