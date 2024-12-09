#include <bits/stdc++.h>
using namespace std;

int n,k,a[200010];

void work()
{
	scanf("%d %d",&n,&k);
	for (int i=1,x; i<=n; i++)  scanf("%d",&x),a[x]++;
	sort(a+1,a+n+1),reverse(a+1,a+n+1);
	for (int i=1; i<=k; i++)  n-=a[i];
	printf("%d",n);
}

int main()
{
	work();
	return 0;
}
