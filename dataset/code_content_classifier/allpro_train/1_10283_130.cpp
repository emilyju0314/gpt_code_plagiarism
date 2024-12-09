#include <cstdio>
#include <algorithm>
using namespace std;

char ps[23][2333];
bool pf[23];

int heng(int n,int m,int p)
{
	int l=1,q=1,pi[25]={0},sum=0;
	while(l<=m)
	{
		pi[0]=1;
		for(int i=1; i<=n; i++)
		{
			if(ps[i][l]=='1')
			{
				pi[pi[0]]++;
				if(pi[pi[0]]>p)
				{
					if(l==q) return 23333;
					sum++; q=l; l--;
					for(int j=1; j<=n; j++) pi[j]=0;
					break;
				}
			}
			if(pf[i]==true) pi[0]++;
		}
		l++;
	}
	return sum;
}

int sou(int k,int n,int m,int p)
{
	if(k==n)
	{
		int sum=0;
		for(int i=1; i<=n; i++) if(pf[i]==true) sum++;
		return sum+heng(n,m,p);
	}
	int sum=23333;
	pf[k]=true;
	sum=min(sum,sou(k+1,n,m,p));
	pf[k]=false;
	sum=min(sum,sou(k+1,n,m,p));
	return sum;
}

int main()
{
	int n,m,p; scanf("%d%d%d",&n,&m,&p);
	for(int i=1; i<=n; i++) scanf("%s",ps[i]+1);
	printf("%d",sou(1,n,m,p));
	return 0;
}
