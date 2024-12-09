#include <bits/stdc++.h>
using namespace std;
int f[100001];
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
	{
        f[i]=f[i-1]+1;
        for(j=6;j<=i;j*=6)
			f[i]=min(f[i],f[i-j]+1);
        for(j=9;j<=i;j*=9) 
			f[i]=min(f[i],f[i-j]+1);
    }
	printf("%d",f[n]);
}