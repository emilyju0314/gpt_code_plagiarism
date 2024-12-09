#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
double F(double r,double s)
{
	return (r+s)*::cos(asin((r-s)/(r+s)));
}
int main()
{
	int l,a[12],n,i,j,k;
	char*p,s[256];
	while(fgets(s,256,stdin))
	{
		p=strtok(s," ");
		l=atoi(p);
		for(n=0;p;)
		{
			p=strtok(0," ");
			if(p)a[n++]=atoi(p);
		}
		std::vector<int>u,v;
		double dp[1<<12][12];
		std::fill(dp[0],dp[1<<12],1e10);
		for(i=0;i<n;++i)dp[1<<i][i]=a[i];
		for(i=1;i<(1<<n);++i)
		{
			u.clear();
			v.clear();
			for(j=0;j<n;++j)
			{
				if(i&(1<<j))u.push_back(j);
				else v.push_back(j);
			}
			for(j=0;j<u.size();++j)
			{
				for(k=0;k<v.size();++k)
				{
					double&r=dp[i|(1<<v[k])][v[k]];
					r=std::min(r,dp[i][u[j]]+F(a[u[j]],a[v[k]]));
				}
			}
		}
		k=(1<<n)-1;
		for(i=0;i<n;++i)dp[k][i]+=a[i];
		puts(*std::min_element(dp[k],dp[k]+n)-1e-7<l?"OK":"NA");
	}
	return 0;
}